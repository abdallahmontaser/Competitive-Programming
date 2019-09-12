/**
  * A graph having one unique path between any two pair of vertices is a tree.
  * 
  * Imagine the complete graph(all the possible edges are present) where each edge has a weight: either (build_value) for
  * the edges not present at the beginning, or (-destroy_value) for the ones present.
  * Observe that (sum of weights of the graph's MinimumSpanningTree) + (sum of destroy values for edges present at start)
  * will give the answer.
*/
#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
using namespace std;
const int N = 100000 + 5, inf = 1e9;

struct DSU {
	vector<int> rep, sz;
	DSU(int n) {
		rep.resize(n + 1), sz.resize(n + 1);
		for (int i = 1; i <= n; ++i) rep[i] = i, sz[i] = 1;
	}
	int find(int x) { return (rep[x] == x) ? x : rep[x] = find(rep[x]); }
	void unite(int x, int y) {
		x = find(x), y = find(y);
		sz[x] += sz[y];
		rep[y] = x;
	}
};

class KingdomReorganization {
  public:
	int n;
	
  int mst(vector<pair<int, pair<int, int>>> &edges) {
		sort(all(edges));

		DSU dsu(n);
		int ans = 0;
		for (auto e : edges)
			if (dsu.find(e.S.F + 1) != dsu.find(e.S.S + 1)) {
				ans += e.F;
				dsu.unite(e.S.F + 1, e.S.S + 1);
			}
		return ans;
	}
	
  int value(char c) { return (('A' <= c && c <= 'Z') ? (c - 'A') : (c - 'a' + 26)); }
  
	int getCost(vector<string> kingdom, vector<string> build, vector<string> destroy) {
		n = sz(kingdom);

		int destroyTotal = 0;
		vector<pair<int, pair<int, int>>> edges;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j) {
				if (kingdom[i][j] == '1')
					destroyTotal += value(destroy[i][j]), edges.push_back({-value(destroy[i][j]), {i, j}});
				else
					edges.push_back({value(build[i][j]), {i, j}});
			}

		return destroyTotal + mst(edges);
	}
};

