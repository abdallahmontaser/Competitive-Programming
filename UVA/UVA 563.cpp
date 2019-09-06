/**
  * Consider a network where sources are the banks and sinks are the borders of the map.
  * It's possible  <===>  The max flow is equal to the number of banks b.
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
const int N = 5000 + 5, N2 = 50000 + 5, LOG = 9 + 1, INF = 1e9;
int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};

struct edge {
	int nxt, rev;
	int f, cap;
};
class DINIC {
  public:
	vector<vector<edge>> g;
	vector<int> level, c_e;
	int s, t;
	DINIC() {
		g.resize(N);
		level.resize(N);
		c_e.resize(N);
	}
	void addE(int a, int b, int c) {
		edge e;
		e.nxt = b, e.f = 0, e.cap = c, e.rev = sz(g[b]);
		g[a].pb(e);
		e.nxt = a, e.f = 0, e.cap = 0, e.rev = sz(g[a]);
		g[b].pb(e);
	}
	bool bfs() {
		fill(all(level), -1);
		queue<int> q;
		q.push(s);
		level[s] = 0;
		while (q.empty() == 0) {
			for (edge e : g[q.front()])
				if (level[e.nxt] == -1 && e.f < e.cap) {
					level[e.nxt] = level[q.front()] + 1;
					q.push(e.nxt);
				}
			q.pop();
		}
		return (level[t] != -1);
	}
	int send_flow(int curr, int curr_f) {
		if (curr == t) return curr_f;
		for (; c_e[curr] < sz(g[curr]); ++c_e[curr]) {
			edge &e = g[curr][c_e[curr]];
			if (level[e.nxt] == level[curr] + 1 && e.f < e.cap) {
				int tmp_f = send_flow(e.nxt, min(curr_f, e.cap - e.f));
				if (tmp_f > 0) {
					e.f += tmp_f;
					g[e.nxt][e.rev].f -= tmp_f;

					return tmp_f;
				}
			}
		}
		return 0;
	}
	int max_flow() {
		int f = 0;
		while (bfs() == 1) {
			fill(all(c_e), 0);
			while (int tmp_f = send_flow(s, 2e9))
				f += tmp_f;
		}
		return f;
	}
};

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, b;
		cin >> n >> m >> b;
		set<pair<int, int>> coords;

		DINIC dinic;
		dinic.s = n * m * 2 + 1, dinic.t = n * m * 2 + 2;
		loop(i, 1, b) {
			int x, y;
			cin >> x >> y;
			coords.insert(mp(x, y));
			dinic.addE(dinic.s, (x - 1) * m + y, 1);
		}
		loop(x, 1, n) loop(y, 1, m) dinic.addE((x - 1) * m + y, (x - 1) * m + y + n * m, 1);
		loop(x, 1, n) loop(y, 1, m) loop(z, 0, 3) {
			if (1 <= x + dx[z] && x + dx[z] <= n && 1 <= y + dy[z] && y + dy[z] <= m)
				dinic.addE((x - 1) * m + y + n * m, (x + dx[z] - 1) * m + y + dy[z], 1);
		}
		loop(x, 1, n) loop(y, 1, m) if (x == 1 || y == 1 || x == n || y == m) dinic.addE((x - 1) * m + y + n * m, dinic.t, 1);

		if (sz(coords) == b && b <= 2 * (n + m - 2) && dinic.max_flow() == b)
			cout << "possible\n";
		else cout<<"not possible\n";
	}
}
