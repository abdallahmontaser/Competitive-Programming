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
* Construct the graph, and add weights such that the weight on edge (u,v) should be the position of v if we sort all the nodes w such there is an edge (u,w).
* Then just return the shortest distance between 1 and n.This is true because we will never need to go through a node more than once
* so if at any node u, if you choose to go through an edge having weight w>0 (then according to the problem, you just deleted w edges) it
* won't be a problem since we're not going back to u again.
*/

ll n;
ll dist[55];
ll m[55][55];

void dijkstra(){
   priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >pq;
   FOR(i,2,n) dist[i]=1e9;

   pq.push(mp(0,1));
   while(!pq.empty()){
      ll u=pq.top().second;
      pq.pop();

      FOR(v,1,n) if(m[u][v] != -1 && dist[v] > dist[u]+m[u][v]){
         dist[v] = dist[u] + m[u][v];
         pq.push(mp(dist[v],v));
      }
   }
}

class ColorfulWolves{
   public: int getmin(vector <string> colormap){
      n = colormap.size();
      memset(m,-1,sizeof(m));

      FOR(i,0,n-1){
         ll tmp=0;
         FOR(j,0,n-1) if(colormap[i][j]=='Y') m[i+1][j+1] = tmp++;
      }

      dijkstra();

      if(dist[n]==1e9) return -1;
      return dist[n];
   };
};
