#include<bits/stdc++.h>
#define MOD 1000000007
#define EPS 1e-15
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define endl '\n'
#define foreach(it,x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
const ld PI=3.141592653589793238L;
const ll N=100005;
using namespace std;

/**
* I used a segment tree with lazy propagation.
* For each node "i" of the tree, seg[i].v will store the occurences of each character(from 'a' to 'z') in the range
* for which "i" is responsible for.
* 
* Editorial: http://codeforces.com/blog/entry/19212
*/

struct node{
   vector<ll>v;
   ll lazy;
   node(){
      v.resize(26,0);
      lazy=0;
   }
};

ll nn;
vector<node>seg;
ll l,r,k;

void f(node&a,node&b,node&c,ll&sum,ll order){ // divide a half of a, in b and the rest in c (depends on the "order")
   ll sum2=0;

   if(order == 1) for(int j=0;j<26;++j){
      if(sum2+a.v[j] <= sum) sum2+=a.v[j] , b.v[j]=a.v[j] , c.v[j]=0;
      else{
         b.v[j]=sum - sum2;
         c.v[j]=a.v[j]-b.v[j];
         while(++j != 26) c.v[j]=a.v[j],b.v[j]=0;
      }
   }
   else for(int j=25;j>=0;--j){
      if(sum2+a.v[j] <= sum) sum2+=a.v[j] , b.v[j]=a.v[j] , c.v[j]=0;
      else{
         b.v[j]=sum - sum2;
         c.v[j]=a.v[j]-b.v[j];
         while(--j != -1) c.v[j]=a.v[j],b.v[j]=0;
      }
   }
}

void up(ll i){
   i/=2;
   while(i){
      for(int j=0;j<26;++j) seg[i].v[j] = seg[2*i].v[j] + seg[2*i+1].v[j];
      i/=2;
   }
}

void f2(node a){
   for(int j=0;j<26;++j) if(a.v[j]) cout << (char)('a'+j);
   cout <<  endl;
}

void propagate(ll i){
   ll sum=0;
   for(int j=0;j<26;++j) sum+=seg[i].v[j];
   sum /= 2;

   f(seg[i],seg[2*i],seg[2*i+1],sum,seg[i].lazy);

   seg[2*i].lazy = seg[2*i+1].lazy = seg[i].lazy;
   seg[i].lazy=0;
}

void modif(node& x,ll i=1,ll st=1,ll en=nn){
   if(l>en || r<st) return;

   if(st != en && seg[i].lazy) propagate(i);

   if(l<=st && en<=r){
      for(int j=0;j<26;++j) seg[i].v[j] = x.v[j];
      seg[i].lazy = k;
      up(i);
      return;
   }

   // we need to divide x in two segments
   ll mid = (st+en)/2;

   ll nbLeft = mid-max(l,st)+1;
   nbLeft=max(0ll,nbLeft);

   node y,z;
   f(x,y,z,nbLeft,k);

   modif(y,2*i,st,mid);
   modif(z,2*i+1,mid+1,en);
}

node get(ll i=1,ll st=1,ll en=nn){
   node ans;
   if(l>en || r<st) return ans;
   if(l<=st && en<=r) return seg[i];

   if(st != en && seg[i].lazy) propagate(i);

   ll mid = (st+en)/2;

   node ans1 = get(2*i,st,mid) , ans2 = get(2*i+1,mid+1,en);
   for(int j=0;j<26;++j) ans.v[j] = ans1.v[j]+ans2.v[j];

   return ans;
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll n,q; cin >> n >> q;

   nn = pow(2,ceil(log2(n)));
   seg.resize(2*nn);

   for(int i=0;i<n;++i){
      char c; cin >> c;
      ++(seg[i+nn].v[c-'a']);
      up(i+nn);
   }

   while(q--){
      cin >> l >> r >> k;
      if(!k) k = -1;
      node ans = get();
      modif(ans);
   }

   for(int i=1;i<=nn-1;++i) if(seg[i].lazy) propagate(i);

   for(int i=nn;i<n+nn;++i) for(int j=0;j<26;++j) if(seg[i].v[j]) cout << (char)('a'+j);

   cout << endl;

	return 0;
}
