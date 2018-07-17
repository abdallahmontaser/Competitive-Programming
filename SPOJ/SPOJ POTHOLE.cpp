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
* This corresponds to a classical max-flow problem, where the capacity of all edges (u,v) is equal to "1" if u=1 or v=n and "oo" otherwise.
*/

ll n;
ll vis[201];
ll cap[201][201];
vector<ll>path;

ll get_path(ll i,ll curr_flow){
   vis[i] = 1;

   if(i == n)  return curr_flow;

   for(int j=1;j<=n;++j) if(!vis[j] && cap[i][j]>0){
      ll res = get_path(j,min(curr_flow,cap[i][j]));
      if(res>0) {
         path.pb(j);
         return res;
      }
   }

   return 0;
}

ll max_flow(){
   ll ans=0;
   while(1){
      path.clear();
      memset(vis,0,sizeof(vis));
      ll res = get_path(1,1e9);

      if(!res) break;

      path.pb(1);
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
      cin>>n;
      memset(cap,0,sizeof(cap));
      for(int i=1;i<n;++i){
         ll m; cin>>m;
         while(m--){
            ll j; cin>>j;
            ll c=1e9;
            if(i==1 || j==n) c=1;

            cap[i][j] += c;
         }
      }

      cout<<max_flow()<<endl;
   }

	return 0;
}
