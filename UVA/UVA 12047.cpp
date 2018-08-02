#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <iterator>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#include <limits>
#include <math.h>
#include <stdio.h>
#include <string.h>

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
* The answer is the weight of an edge in the graph, right?
* 
* Go over all the edges (u,v) of weight w; if dist(s,u) + w + dist(v,t) <= p then this edge can be the answer.
* Among all these edges, return the one with the greatest w.
* 
* I believe the code alone is enough to understand how to get these distances if you haven't figured it out already.
*/

void dijkstra(vector<pair<ll,ll> >*g,ll*dist,ll s,ll t){
   priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >pq;

   dist[s]=0;
   pq.push(mp(0,s));

   while(!pq.empty()){
      ll u=pq.top().second;
      pq.pop();

      foreach(it,g[u]){
         ll v=it->second , w=it->first;
         if(dist[v] < dist[u] + w) continue;

         dist[v] = dist[u] + w;
         pq.push(mp(dist[v],v));
      }
   }
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll tc; cin>>tc;
   while(tc--){
      ll n,m; cin>>n>>m;
      ll s,t,p; cin>>s>>t>>p;

      ll dist1[n+1],dist2[n+1];
      FOR(i,1,n) dist1[i]=1e18 , dist2[i]=1e18;

      vector<pair<ll,ll> >g1[n+1],g2[n+1];
      vector<pair<pair<ll,ll>,ll> >e;

      while(m--){
         ll x,y,c; cin>>x>>y>>c;
         g1[x].pb(mp(c,y));
         g2[y].pb(mp(c,x));
         e.pb(mp(mp(x,y),c));
      }

      dijkstra(g1,dist1,s,t);
      dijkstra(g2,dist2,t,s);

      ll ans=-1;
      FOR(k,0,e.size()-1){
         ll i=e[k].first.first , j=e[k].first.second , w=e[k].second;
         if(dist1[i]+dist2[j]+w <= p) ans=max(ans,w);
      }

      cout<<ans<<endl;
   }

	return 0;
}
