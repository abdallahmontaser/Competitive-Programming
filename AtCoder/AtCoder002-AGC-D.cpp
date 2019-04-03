#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
#define ll long long
using namespace std;
const int N = 100123;
int rep[N] , sz[N];
vector<pair<int,int>> v_sz[N] , v_rep[N];

/**
* Imagine that for every query we do a binary search on the answer and for each possible mid answer we construct
* a DSU using only the edges with index <= that mid answer and we see if it's possible to have z_i nodes in that DSU or not.
* That would take O(M*log(M)) for every query, right?
* 
* I have done just that! Except that I constructed the DSU only once for the entire graph
* and I have stored, for every node, the times at which it's tree size(in the DSU) increased, and the time at which
* that node got a new direct parent(also talking in the DSU).
* For every node, at most one time it will have a new parent(if not, it will remain the parent of the whole graph)
* And for the total number of changes in subtree sizes, it will be at most n - 1 times.
* We update this history every time we enter the 'unite' function.
* 
* Now for every query(X,Y,Z) and for every 'mid' value in the binary search inside it, we find the parent of X after adding 'mid' edges
* and it's subtree size. And the same for y.
* If this parent is the same for X and Y, the number of touched vertices is that subtree size, else it is the sum of both subtree sizes.
* We compare this number with Z to find out the next binary search interval.
* 
* Official editorial explains a cool 'parallel binary search' trick: http://agc002.contest.atcoder.jp/data/agc/002/editorial.pdf
*/

int find(int x) {
      if (x == rep[x]) return x;
      return rep[x] = find(rep[x]);
}

void unite(int i , int x , int y){
      x = find(x) , y = find(y);
      if(x == y) return;

      if(sz[x] < sz[y]) swap(x , y);

      sz[x] += sz[y];
      v_sz[x].pb(mp(i , sz[x]));

      rep[y] = x;
      v_rep[y].pb(mp(i , rep[y]));
}

pair<int,int> find2(int i , int x){
      while(1){
            int t = (upper_bound(v_rep[x].begin() , v_rep[x].end() , mp(i , N)) - 1)->S;
            if(t == x) break;
            x = t;
      }

      int nb_x = (upper_bound(v_sz[x].begin() , v_sz[x].end() , mp(i , N)) - 1)->S;

      return mp(x , nb_x);
}

int32_t main(){
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

      int n,m; cin >> n >> m;
      for(int i = 1; i <= n; ++i){
            rep[i] = i , sz[i] = 1;
            v_sz[i].pb(mp(0 , sz[i]));
            v_rep[i].pb(mp(0 , rep[i]));
      }

      for(int i = 1; i <= m; ++i){
            int a,b; cin >> a >> b;
            unite(i , a , b);
      }

      int q; cin >> q;
      while(q--){
            int u,v,nb; cin >> u >> v >> nb;

            int lo = 1 , hi = m , best;
            while(lo <= hi){
                  int mid = (lo + hi) >> 1;

                  pair<int,int> x = find2(mid , u);
                  pair<int,int> y = find2(mid , v);

                  int ans = x.S + y.S;
                  if(x.F == y.F) ans = x.S;

                  if(ans >= nb) best = mid , hi = mid - 1;
                  else lo = mid + 1;
            }

            cout << best << '\n';
      }

      return 0;
}
