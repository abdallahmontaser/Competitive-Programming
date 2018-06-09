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

vector<ll>g[50];
vector<pair<ll,pair<ll,ll> > >edge;
bool t[50];

bool dfs(ll x,ll p){
   if(t[x]) return 1;
   ll ans=0;
   for(ll y: g[x]) if(y!=p) ans|=dfs(y,x);
   return ans;
}

class BlockEnemy {
   public: ll minEffort(int n, vector<string> roads, vector<int> towns) {
      for(int i=0;i!=towns.size();++i) t[towns[i]]=1;
      for(int i=0;i!=roads.size();++i){
         istringstream iss(roads[i]);
         ll a,b,e; iss >> a >> b >> e;
         edge.pb(mp(e,mp(a,b)));
         g[a].pb(b);
         g[b].pb(a);
      }

      sort(edge.begin(),edge.end());

      ll ans=0;
      for(int i=0;i!=edge.size();++i){
         ll a=edge[i].second.first , b=edge[i].second.second , e=edge[i].first;
         if(!dfs(a,b) || !dfs(b,a)) continue;
         ans+=e;
         g[a].erase(find(g[a].begin(),g[a].end(),b));
         g[b].erase(find(g[b].begin(),g[b].end(),a));
      }

      return ans;
   }
};
