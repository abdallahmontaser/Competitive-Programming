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
* We need to find out if there exists a path from node 1 to node 3 that passes by 2 without passing by any node more than once.
* This can be solved by finding a max_flow.
* Suppose that 2 is our source.Make a super sink and attach 1 and 3 to it, while setting all capacities(edges and verticies) to 1.
* The answer will be "YES" if and only if the maximum flow(s-t) is equal to 2.
* Since the maximum flow can either be 0, 1 or 2; the final complexity will be O(tc * E).
* 
* For a more detailed explanation: https://www.quora.com/How-can-I-approach-the-problem-Intergalactic-Map-IM-on-SPOJ-using-Max-Flow
*/

ll s,t;
map<ll,ll>vis;
map<ll,ll>cap[62000];
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

   ll tc; cin>>tc;
   while(tc--){
      ll n,m; cin>>n>>m;
      FOR(i,1,2*n+4) cap[i].clear();

      s=n+1,t=n+2;
      cap[s][2]=2;
      ++cap[1+n+2][t];
      ++cap[3+n+2][t];

      FOR(i,1,n) cap[i][i+n+2]=1;
      ++cap[2][2+n+2];

      FOR(i,1,m){
         ll x,y; cin>>x>>y;
         ++cap[x+n+2][y];
         ++cap[y+n+2][x];
      }

      if(max_flow()==2) cout<<"YES\n";
      else cout<<"NO\n";
   }

	return 0;
}
