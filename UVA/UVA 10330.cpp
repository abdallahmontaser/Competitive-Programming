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
* This corresponds to a regular s-t max flow problem.Construct a graph, where for every gopher "i" and every hole "j";
* If "i" can reach "j" with the given velocity in less than the given number of seconds, add an edge of length 1 between them.
* Then add two extra nodes s and t.Add an edge between s and all the gophers(of length 1) and between t and all the holes(of length one).
* Now find the maximum flow between s and t.That will be the maximum number of gophers that will escape in the optimal strategy.
* So the answer will be n-max_flow(s,t);
*/

ll total;
ll s,t;
ll vis[205];
ll cap[205][205];
vector<ll>path;

bool f(ld&a,ld&b,ld&x,ld&y,ld&t,ld&v){
   ld d = sqrt((a-x)*(a-x) + (b-y)*(b-y));
   ld t2 = d / v;
   return t2 < t || fabs(t-t2) < EPS;
}

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

   ll n,m;
   ld time,velocity;
   while(cin>>n>>m>>time>>velocity){
      memset(cap,0,sizeof(cap));

      s = n+m+1 , t = n+m+2;
      total = n+m+2;

      vector<pair<ld,ld> >gophers;
      for(int i=1;i<=n;++i){
         ++cap[s][i];
         ld x,y; cin>>x>>y;
         gophers.pb(mp(x,y));
      }

      for(int i=1;i<=m;++i){
         ++cap[i+n][t];
         ld x,y; cin>>x>>y;
         for(int j=1;j<=n;++j) if(f(gophers[j-1].first,gophers[j-1].second,x,y,time,velocity)) ++cap[j][i+n];
      }

      cout<<n-max_flow()<<endl;
   }

	return 0;
}
