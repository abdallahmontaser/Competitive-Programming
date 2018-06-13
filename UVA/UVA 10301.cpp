#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define endl '\n'
const ld PI =  3.141592653589793238L;
const ll N=100002;
using namespace std;

/**
* I used DSU to link every pair of rings that overlap in two points, then printed the maximum value in the "sz" array.
* For two rings to overlap, the need to not be completely disjoint(or tangent) and one mustn't be inside another.
*/

ll rep[100],sz[100];
pair<pair<ld,ld>,ld>a[100];

ll find(ll x){
   while(x!=rep[x]) x=rep[x];
   return x;
}

void unite(ll x,ll y){
   if(x==y) return;
   if(sz[y]>sz[x]) swap(x,y);
   rep[y]=x;
   sz[x]+=sz[y];
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll n; cin >> n;
   while(n!=-1){
      if(!n){
         cout << "The largest component contains 0 rings.\n";
         cin >> n;
         continue;
      }

      for(int i=0;i!=n;++i){
         cin >> a[i].first.first >> a[i].first.second >> a[i].second;
         rep[i]=i;
         sz[i]=1;
      }

      for(int i=0;i!=n;++i) for(int j=0;j!=n;++j){
         ld x1=a[i].first.first,y1=a[i].first.second,r1=a[i].second;
         ld x2=a[j].first.first,y2=a[j].first.second,r2=a[j].second;

         if((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) >= (r1+r2)*(r1+r2)) continue;
         if((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) <= (r1-r2)*(r1-r2)) continue;

         unite(find(i),find(j));
      }

      ll ans=1;
      for(int i=0;i!=n;++i) ans=max(ans,sz[i]);

      cout << "The largest component contains " << ans << " ring";
      if(ans!=1) cout << "s";
      cout << ".";

      cin >> n;
      if(n!=-1) cout << endl;
   }

   return 0;

}
