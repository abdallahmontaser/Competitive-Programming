/**
  * Solved with dynamic programming
  * Solution: https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/UVA/UVA_1218.txt
*/
#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define F  first
#define S  second
#define sz(x)  (int)(x).size()
#define all(x) x.begin(), x.end()
using namespace std;
const int N = 100000 + 5, inf = 1e5; const LD EPS = 1e-9L;
vector<int> g[N]; int dp[N][2][2];
int dfs(int i, int p, int a, int b) {
      int &ans = dp[i][a][b]; if (ans != -1) return ans;

      if (a == 1) {
            ans = 1; for (int j: g[i]) if (j != p) ans += min(dfs(j, i, 0, 1), dfs(j, i, 1, 0));
      }
      if (a == 0) {
            ans = 0; for (int j: g[i]) if (j != p) ans += dfs(j, i, 0, 0);
            if (b == 0) {
                  int tmp = inf; for (int j: g[i]) if (j != p) tmp = min(tmp, dfs(j, i, 1, 0) - dfs(j, i, 0, 0));
                  ans += tmp;
            }
      }
      return ans;
}
/**********************************************************/
int32_t main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      while (true) {
            int n; cin >> n;
            for (int i = 1; i <= n; ++i) g[i].clear();
            for (int i = 1; i <= n - 1; ++i) {
                  int u, v; cin >> u >> v; g[u].push_back(v), g[v].push_back(u);
            }
            for (int i = 1; i <= n; ++i) dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = -1;

            cout << min(dfs(1, 1, 0, 0), dfs(1, 1, 1, 0)) << '\n';

            int tmp; cin >> tmp; if (tmp == -1) break;
      }
}
