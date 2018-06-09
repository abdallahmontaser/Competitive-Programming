#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define endl '\n'
const ld PI =  3.141592653589793238L;
const ll N=1000002;
using namespace std;

/**
*The first answer should be the total weight of the MST of the graph.
*Then the second one should be the total weight of the second to lowest MST,
*which should have atleast one edge that doesn't exist in the first MST.
*So I looped over the edges that I didn't choose for the first MST, and each time, began first by adding this edge, and then doing the regular MST algorithm.
*And if the result is a tree(not a forest) I take the answer and finally take the minimum of those.
*/

ll n,m;
ll sz[100],rep[100];
vector<pair<ll,pair<ll,ll> > >edges;
vector<ll>v;

ll find(ll x){
   while(rep[x]!=x) x=rep[x];
   return x;
}

void unite(ll x,ll y){
   if(sz[x]<sz[y]) swap(x,y);
   rep[y]=x;
   sz[x]+=sz[y];
}

ll MST(bool bb){
   ll ans=0;
   for(int i=0;i!=edges.size();++i){
      ll a=find(edges[i].second.first);
      ll b=find(edges[i].second.second);
      if(a!=b) unite(a,b),ans+=edges[i].first;
      else if(bb) v.pb(i);
   }

   return ans;
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll tc; cin >> tc;
   while(tc--){
      edges.clear();
      v.clear();

      cin >> n >> m;
      while(m--){
         ll a,b,c; cin >> a >> b >> c;
         --a,--b;
         edges.pb(mp(c,mp(a,b)));
      }

      sort(edges.begin(),edges.end());

      for(int i=0;i!=n;++i) sz[i]=1,rep[i]=i;

      ll ans1=MST(1);

      ll ans2=1e18;
      for(int k=0;k!=v.size();++k){
         for(int i=0;i!=n;++i) sz[i]=1,rep[i]=i;

         ll tmp_ans2=edges[v[k]].first;
         unite(edges[v[k]].second.first,edges[v[k]].second.second);
         tmp_ans2+=MST(0);

         bool correct=0;
         for(int i=0;i!=n;++i) if(sz[i]==n) correct=1;

         if(correct) ans2=min(ans2,tmp_ans2);
      }

      cout << ans1 << ' ' << ans2 << endl;
   }

   return 0;

}
