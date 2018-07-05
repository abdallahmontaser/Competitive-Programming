#include<bits/stdc++.h>
#define MOD 1000000007
#define EPS 1e-9
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define endl '\n'
#define foreach(it,x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
const ld PI=3.141592653589793238L;
const ll N=300002;
using namespace std;

/**
* The problem statement has missing information.
* See this for the correction and the solution: https://ideone.com/x8zpRc
*/

ll n,m;
ll ans[105][105],dist[105][105];
vector<pair<ll,pair<ll,ll> > >edges;

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll tc=0;
   while(cin >> n >> m){
      ++tc;
      if(!(n+m)) break;
      edges.clear();
      for(int i=0;i<n;++i) for(int j=0;j<n;++j) dist[i][j] = 1e9 , ans[i][j] = 1e9;

      for(int i=0;i<n;++i) dist[i][i]=0;
      while(m--){
         ll u,v,x; cin >> u >> v >> x;
         edges.pb(mp(x,mp(u,v)));
         dist[u][v]=x;
         dist[v][u]=x;
      }

      for(int k=0;k<n;++k) for(int i=0;i<n;++i) for(int j=0;j<n;++j) dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);

      for(int i=0;i<n;++i) for(int j=0;j<n;++j){
         ll &res=ans[i][j];
         for(int k=0;k<edges.size();++k){
            ll a=edges[k].second.first , b=edges[k].second.second , c=edges[k].first;
            ll d;

            d=dist[i][a] + c + dist[b][j];
            if(d > dist[i][j]) res=min(res,d);

            d=dist[i][b] + c + dist[a][j];
            if(d > dist[i][j]) res=min(res,d);
         }
      }

      cout << "Set #" << tc << endl;
      ll q; cin >> q;
      while(q--){
         ll i,j; cin >> i >> j;
         if(ans[i][j] == 1e9) cout << "?\n";
         else cout << ans[i][j] << endl;
      }
   }

	return 0;
}
