#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define F  first
#define S  second
#define sz(x)  (int)(x).size()
#define all(x) x.begin(), x.end()
using namespace std;
const int N = 20000 + 5, inf = 1e9; const LD EPS = 1e-9L;
int w[N], nbCuts; vector<int> g[N];
LL cuts(int i, int p, LL mx) {
      vector<LL> values;
      for (int j:g[i]) if (j != p) values.push_back(cuts(j, i, mx));
	
      if (sz(values)) sort(all(values));
      LL cur = w[i]; if (cur > mx) nbCuts = inf;
      for (int ii = 0; ii < sz(values); ++ii) {
            if (cur + values[ii] > mx) {
                  nbCuts += sz(values) - ii; break;
            }
            else cur += values[ii];
      }
      return cur;
}
/**********************************************************/
int32_t main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      int n, k; cin >> n >> k;
      for (int i = 1; i <= n; ++i) cin >> w[i];
      for (int i = 1; i <= n - 1; ++i) {
            int u, v; cin >> u >> v; g[u].push_back(v), g[v].push_back(u);
      }
      LL best = 1e18L, lo = 1, hi = 1e18L;
      while (lo <= hi) {
            LL mid = (lo + hi) >> 1;
            nbCuts = 0;
            cuts(1, 1, mid);
            if (nbCuts <= k - 1) best = mid, hi = mid - 1;
            else lo = mid + 1;
      }
      cout << best << '\n';
}
