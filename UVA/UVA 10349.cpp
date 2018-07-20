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
* I got the solution from here: https://github.com/3agwa/CompetitiveProgramming/blob/master/UVA/UVA%2010349.cpp
* (There are other more complicated solutions, so this might be the easiest and simplest out there.)
* For anyone who didn't understand why the answer will be "the number of * - max_flow", and because I didn't understand 3agwa's explanation;
* Draw a small example of a grid, and construct the corresponding graph.What will the max_flow represent??
* Because all the edges' lengths are 1, and because s can reach t if and only if it passes by a black cell which passes by a white cell then t, 
* then the max_flow will simply be the maximum number of '*' that we can cover without putting an antenna in their places(i.e. the white cells that will be the third node in any path from s to t).
* Let that number be nb.That's why, we don't need to put antennas in nb places in order to cover them, and because nb is maximum possible, 
* we MUST put antennas in ALL the other places of interest in order to cover them.So the answer will be "number of '*' - nb".
*/

ll total,s,t;
vector<pair<ll,ll> >v;
vector<ll>path;
ll cap[410][410],vis[410];
vector<ll> g[410];

ll dx[4] = {1,0,-1,0};
ll dy[4] = {0,1,0,-1};

void add(ll x,ll y){
   g[x].pb(y);
   ++cap[x][y];
}

ll get_path(ll i,ll curr_flow){
   vis[i] = 1;

   if(i == t)  return curr_flow;

   for(int j=0;j<g[i].size();++j) if(!vis[g[i][j]] && cap[i][g[i][j]]>0){
      ll res = get_path(g[i][j],min(curr_flow,cap[i][g[i][j]]));
      if(res>0) {
         path.pb(g[i][j]);
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

   ll tc; cin>>tc;
   while(tc--){
      v.clear();
      memset(cap,0,sizeof(cap));
      for(int i=0;i<410;++i) g[i].clear();
      ll n,m; cin>>n>>m;

      //total=n*m;
      s=408 , t=409;
      
      for(int i=1;i<=n;++i) for(int j=1;j<=m;++j){
         char c; cin>>c;
         if(c=='*'){
            if((i+j)%2) add(s,i*(m-1)+j);
            else add(i*(m-1)+j,t);
            v.pb(mp(i,j));
         }
      }

      sort(v.begin(),v.end());

      for(int i=0;i<v.size();++i){
         ll x=v[i].first,y=v[i].second;
         
         for(int a=0;a<4;++a) if(binary_search(v.begin(),v.end(),mp(x+dx[a],y+dy[a])))
            add(x*(m-1)+y,(x+dx[a])*(m-1)+(y+dy[a]));
      }

     cout<<v.size()-max_flow()<<endl;
   }

	return 0;
}
