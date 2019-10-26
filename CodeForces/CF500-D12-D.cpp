/**
  * Editorial: https://codeforces.com/blog/entry/15488
*/
#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define all(x) x.begin(), x.end()
using namespace std; const LD EPS = 1e-9L;
const int N = 100000 + 5, LOGN = 20, inf = 1e9, mod = (int)1e9 + 7;
/***********************************/
tuple<int, int, int> e[N]; vector<int> g[N]; int children[N], n;
void dfs(int i, int p) {
      children[i] = 1;
      for (int j: g[i]) if (j != p) dfs(j, i), children[i] += children[j];
}
inline LL triplets(int x) {
      return ((LL)x * (x - 1) * (x - 2)) / 6;
}
inline LL contribution(int i) {
      int&u = get<0>(e[i]), &v = get<1>(e[i]), &w = get<2>(e[i]);
      int nb = min(children[u], children[v]);
      return (LL)w * 2 * (triplets(n) - triplets(nb) - triplets(n - nb));
}
int32_t main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      cin >> n;
      for (int i = 1; i <= n - 1; ++i) {
            int&u = get<0>(e[i]), &v = get<1>(e[i]), &w = get<2>(e[i]);
            cin >> u >> v >> w;
            g[u].push_back(v);
            g[v].push_back(u);
      }
      dfs(1, 1);

      LD ans = 0;
      for (int i = 1; i <= n - 1; ++i) ans += (LD)contribution(i) / triplets(n);

      int q; cin >> q;
      while (q--) {
            int ind, w; cin >> ind >> w;
            ans -= (LD)contribution(ind) / triplets(n);
            get<2>(e[ind]) = w;
            ans += (LD)contribution(ind) / triplets(n);
            cout << fixed << setprecision(12) << ans << "\n";
      }

      return 0;
}
