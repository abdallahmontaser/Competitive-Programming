/**
  * You can understand from the statement that it's a tree(weighted undirected).
  * You'll need to find the values of the edges on the path from every node to every other(I did so with a simple dfs and stack-like vector)
  * Then, when getting a query of the form {a,b,c}, you check if (c - sum_of_edge_weights from a to b) is not negative and even
  * The distance will be possible if that value / 2 can be derived from summing some of the edge weights in the path(excluding the last value)
  * That can be found with simple dp[i] = minimum number of values that sum to i.(The maximum state is 100000/2 since that's our maximum possible value)
  * 
  * Video solution: https://www.youtube.com/watch?v=OWlJ8chpit0
*/
#include <bits/stdc++.h>
#define ULL unsigned long long
#define LL long long
#define LD long double
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define loop(i, a, b) for (int i = a; i <= b; ++i)
#define pool(i, a, b) for (int i = a; i >= b; --i)
using namespace std;
const int N = 50 + 5, N2 = 50000 + 5, LOG = 9 + 1, INF = 1e9;

int vis[N], dp[N2];
vector<int> path[N][N];
vector<pair<int, int>> g[N];

void dfs(int first, int cur, vector<int> &v) {
	path[first][cur].assign(all(v));
	for (auto e : g[cur])
		if (!vis[e.F]) {
			vis[e.F] = 1;

			v.pb(e.S);
			dfs(first, e.F, v);
			v.pop_back();
		}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		loop(i, 0, N - 1) g[i].clear();
		loop(i, 0, N - 1) loop(j, 0, N - 1) path[i][j].clear();
		int n, m;
		cin >> n >> m;

		loop(i, 1, m) {
			int a, b, c;
			cin >> a >> b >> c;
			g[a].pb(mp(b, c));
			g[b].pb(mp(a, c));
		}

		loop(i, 1, n) {
			vector<int> v;
			memset(vis, 0, sizeof(vis));
			vis[i] = 1;
			dfs(i, i, v);
		}

		int q;
		cin >> q;
		while (q--) {
			int a, b, c;
			cin >> a >> b >> c;
      
			for (int d : path[a][b]) c -= d;
			if (c < 0 || c % 2 == 1) {
				cout << "No\n";
				continue;
			}
			c /= 2;

			dp[0] = 0;
			loop(i, 1, c) dp[i] = INF;
			loop(i, 1, c) loop(j, 0, sz(path[a][b]) - 2) if (i >= path[a][b][j])
				dp[i] = min(dp[i], 1 + dp[i - path[a][b][j]]);

			if (dp[c] == INF) {
				cout << "No\n";
				continue;
			}
			cout << "Yes " << sz(path[a][b]) + 2 * dp[c] << '\n';
		}
		if (tc) cout << '\n';
	}
}
