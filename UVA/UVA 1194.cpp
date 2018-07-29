#include<bits/stdc++.h>
#define MOD 1000000007
#define EPS 1e-15
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define endl '\n'
#define foreach(it,x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define FOR(i,a,b) for(ll i=(ll)a;i<=(ll)b;++i)
#define FOR_(i,a,b,c) for(ll i=(ll)a;i<=(ll)b;i+=(ll)c)
const ld PI=3.141592653589793238L;
const ll N=100005;
using namespace std;

/**
* Construct a bipartite graph where, on the left are the modes of the machine A and on the right are the modes of machine B.
* Return the maximum bipartite matching.
*/

ll s,t,total;
map<ll,ll> vis;
map<ll,ll>cap[205];
vector<ll>path;

ll get_path(ll i,ll curr_flow){
   vis[i] = 1;

   if(i == t)  return curr_flow;

   foreach(j,cap[i]) if(!vis[j->first] && j->second > 0){
      ll res = get_path(j->first,min(curr_flow,j->second));
      if(res>0) {
         path.pb(j->first);
         return res;
      }
   }

   return 0;
}

ll max_flow(){
   ll ans=0;
   while(1){
      path.clear();
      vis.clear();
      ll res = get_path(s,1e9);

      if(!res) break;

      path.pb(s);
      reverse(path.begin(),path.end());

      for(int i=0;i<path.size()-1;++i){
         cap[path[i]][path[i+1]] -= res;
         cap[path[i+1]][path[i]] += res;
      }
      ans += res;
   }

   return ans;
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   while(1){
      FOR(i,1,204) cap[i].clear();

      ll n; cin>>n;
      if(!n) break;
      ll m,k; cin>>m>>k;

      s=n+m+1 , t=s+1;

      FOR(i,1,k){
         ll ind,x,y; cin>>ind>>x>>y;
         if(!x || !y) continue;
         cap[s][x]=1;
         cap[x][y+n]=1;
         cap[y+n][t]=1;
      }

      cout<<max_flow()<<endl;
   }

	return 0;
}
