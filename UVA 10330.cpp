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
* To represent the capacity of each regulator i, put an edge between it and i+n with length w = capacity of ith regulator.
* Now when you add any edge from u to v, add it from u+n to v instead.
* Add two extra nodes; s for Barisal and t for Dhaka.And add an edge between s and all the entry points of the network x with length oo,
* and an edge of the same length from all the end points of the network y with t.Here add an edge (y+n,t).
* Now the answer is your typical s-t max_flow of the graph.
*/

ll total;
ll s,t;
ll vis[205];
ll cap[205][205];
vector<ll>path;

ll get_path(ll i,ll curr_flow){
   vis[i] = 1;

   if(i == t)  return curr_flow;

   for(int j=1;j<=total;++j) if(!vis[j] && cap[i][j]>0){
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

   ll n;
   while(cin>>n){
      memset(cap,0,sizeof(cap));

      s = 2*n+1 , t = 2*n+2;
      total = 2*n+2;

      for(int i=1;i<=n;++i) cin>>cap[i][i+n];

      ll m; cin>>m;
      while(m--){
         ll a,b,c; cin>>a>>b>>c;
         cap[a+n][b] = c;
      }

      ll b,d; cin>>b>>d;
      while(b--){
         ll x; cin>>x;
         cap[s][x] = 1e9;
      }
      while(d--){
         ll x; cin>>x;
         cap[x+n][t] = 1e9;
      }

      cout<<max_flow()<<endl;
   }

	return 0;
}
