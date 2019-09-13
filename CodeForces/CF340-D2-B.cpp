/**
  * Editorial: https://codeforces.com/blog/entry/8755
*/
#include <bits/stdc++.h>
#define LL  long long
#define LD  float
#define F   first
#define S   second
#define sz(x)  (int)(x).size()
#define all(x) x.begin(), x.end()
using namespace std;
#define int long long
const int N = 300 + 5, inf = 1e9; const LD EPS = 1e-9;

struct point {
      int X = 0, Y = 0;
};
LD triangleArea(point&a, point&b, point&c) {
      int area = 0;

      area += a.X * b.Y - a.Y * b.X;
      area += b.X * c.Y - b.Y * c.X;
      area += c.X * a.Y - c.Y * a.X;
      return 0.5 * area;
}
point pnts[N]; LD mx[N][N], mn[N][N];
/*****************************************************************************************************/
/*****************************************************************************************************/
signed main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      int n; cin >> n;
      for (int i = 1; i <= n; ++i) cin >> pnts[i].X >> pnts[i].Y;

      for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                  for (int k = j + 1; k <= n; ++k) {
                        LD area = triangleArea(pnts[i], pnts[j], pnts[k]);

                        if (area >= 0) {
                              mx[i][j] = max(mx[i][j], area);
                              mn[i][k] = min(mn[i][k], -area);
                              mx[j][k] = max(mx[j][k], area);
                        } else {
                              mn[i][j] = min(mn[i][j], area);
                              mx[i][k] = max(mx[i][k], -area);
                              mn[j][k] = min(mn[j][k], area);
                        }
                  }

      LD best = 0;
      for (int i = 1; i <= n; ++i) for (int j = i + 1; j <= n; ++j)
        if (mx[i][j] != 0 && mn[i][j] != 0)
          best = max(best, mx[i][j] - mn[i][j]);

      cout << fixed << setprecision(9) << best << '\n';
}
