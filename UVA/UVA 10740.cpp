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
const ll N=100002;
using namespace std;

/**
* In the K_th shortest path, every node will be visited at most K times.We can use Dijkstra for this.
* In usual cases(finding the shortest path) with Dijkstra, we keep a boolean array "vis" to make sure we don't visit any node more than
* once, that's when K=1(each node visited at most 1 time).So now we make it an int array and keep pushing in our priority queue
* allowing all nodes a such that vis[a] < k (vis starting from 0) and store the distance in dist[vis[a]][a].
* 
* Finally, the K_th shortest path will be in dist[k-1][y], because although all nodes will be visited at most K times, y will be visited
* exactly K times by Dijkstra's(put K times in the priority queue).
*/

ll n,m;
ll x,y,k;
vector<pair<ll,ll> >g[101];
ll vis[101];
ll dist[10][101];

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   cin >> n >> m;
   while(n || m){
      cin >> x >> y >> k;
      for(int i=1;i<=n;++i){
         g[i].clear(),vis[i]=0;
         for(int j=0;j<k;++j) dist[j][i]=1e9;
      }

      while(m--){ll a,b,c; cin >> a >> b >> c; g[a].pb(mp(c,b));}

      priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >q;
      q.push(mp(0ll,x));
      while(!q.empty()){
         ll a=q.top().second , d=q.top().first;
         q.pop();
         if(vis[a] >= k) continue;

         dist[vis[a]][a] = d;
         ++vis[a];
         foreach(it,g[a]){
            ll b = it->second , d2 = it->first;
            q.push(mp(d+d2,b));
         }
      }

      ll ans = dist[k-1][y];
      if(ans==1e9) ans=-1;
      cout << ans << endl;

      cin >> n >> m;
   }

	return 0;
}
