/**
  * The answer is the maximum flow of the graph. Since there are capacities on nodes also, vertex splitting is necessary.
*/
#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define F  first
#define S  second
#define sz(x)  (int)(x).size()
#define all(x) x.begin(), x.end()
using namespace std;
const int N = 300000 + 5, inf = 1e9; const LD EPS = 1e-9L;
/*****************************************************************************************************/
class DINIC {
public:
struct edge { int from, to, cap, flow; };
vector<vector<int> > g;
vector<edge> e;
vector<int> level, edgeCnt;
int s, t;
DINIC(int n) {
      g.resize(n + 1), level.resize(n + 1), edgeCnt.resize(n + 1);
}
void addE(int a, int b, int cap) {
      g[a].push_back(sz(e)), e.push_back(edge{ a, b, cap, 0 });
      g[b].push_back(sz(e)), e.push_back(edge{ b, a, 0, 0 });
}
bool bfs() {
      fill(all(level), -1);
      queue<int> q;
      q.push(s), level[s] = 0;
      while (q.empty() == 0) {
            int cur = q.front(); q.pop();
            for (int i = 0; i < sz(g[cur]); i++) {
                  int curID = g[cur][i];
                  int nxt = e[curID].to;
                  if (level[nxt] == -1 && e[curID].flow < e[curID].cap) {
                        q.push(nxt);
                        level[nxt] = level[cur] + 1;
                  }
            }
      }
      return (level[t] != -1);
}
int sendFlow(int cur, int curFlow) {
      if (cur == t || curFlow == 0) return curFlow;
      for (; edgeCnt[cur] < sz(g[cur]); ++edgeCnt[cur]) {
            int curID = g[cur][edgeCnt[cur]];
            int nxt = e[curID].to;
            if (level[nxt] == level[cur] + 1) {
                  int tmpFlow = sendFlow(nxt, min(curFlow, e[curID].cap - e[curID].flow));
                  if (tmpFlow > 0) {
                        e[curID].flow += tmpFlow;
                        e[curID ^ 1].flow -= tmpFlow;
                        return tmpFlow;
                  }
            }
      }
      return 0;
}
int max_flow() {
      int f = 0;

      while (bfs() == 1) {
            fill(all(edgeCnt), 0);
            while (int tmpFlow = sendFlow(s, 2e9))
                  f += tmpFlow;
      }
      return f;
}
};
/*****************************************************************************************************/
signed main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      int n, m;
      while (cin >> n >> m && n) {
            DINIC dinic(2 * n);
            dinic.s = 1, dinic.t = n;
            for (int i = 1; i <= n - 2; ++i) {
                  int v, x; cin >> v >> x;
                  dinic.addE(v, v + n, x);
            }
            for (int i = 1; i <= m; ++i) {
                  int u, v, x; cin >> u >> v >> x;
                  if (u == dinic.s) dinic.addE(dinic.s, v, x);
                  else if (v == dinic.t) dinic.addE(u + n, dinic.t, x);
                  else dinic.addE(u + n, v, x), dinic.addE(v + n, u, x);
            }
            cout << dinic.max_flow() << '\n';
      }
}
