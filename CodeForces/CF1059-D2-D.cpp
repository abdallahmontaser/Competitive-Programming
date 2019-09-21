/**
  * This has tough tests that require precise computing. See the editorial's code. 
  * Editorial: https://codeforces.com/blog/entry/62238
*/
#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define F  first
#define S  second
#define sz(x)     (int)(x).size()
#define all(x)    x.begin(), x.end()
using namespace std;
const int N = 300000 + 5, inf = 1e9; const LD EPS = 1e-9L;
/*****************************************************************************************************/
#define INF(A, B) (fabs((A)-(B)) > EPS && A < B)
#define SUP(A, B) (fabs((A)-(B)) > EPS && A > B)
#define EQU(A, B) (fabs((A)-(B)) < EPS)
class point {
public:
LD X = 0, Y = 0;
point() {
}
point(LD XX, LD YY) {
      X = XX, Y = YY;
}
bool operator==(const point &other) {
      return EQU(X, other.X) && EQU(Y, other.Y);
}
point operator+(const point &other) {
      return point{ X + other.X, Y + other.Y };
}
point operator-(const point &other) {
      return point{ X - other.X, Y - other.Y };
}
point operator*(LD f) {
      return point{ X *f, Y *f };
}
};
/*****************************************************************************************************/
signed main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      int n; cin >> n;
      point pnts[n + 1]; for (int i = 0; i < n; ++i) cin >> pnts[i].X >> pnts[i].Y;

      for (int i = 1; i < n; ++i) if ((pnts[i].Y > 0) != (pnts[0].Y > 0)) {
                  cout << "-1\n"; return 0;
            }

      for (int i = 0; i < n; ++i) pnts[i].Y = fabs(pnts[i].Y);

      LD lo = 0, hi = 1e14L;
      for (int cnt = 1; cnt <= 70; ++cnt) {
            LD mid = 0.5L * (lo + hi);

            LD l = -1e9, r = 1e9;
            for (int i = 0; i < n; ++i) {
                  LD b = -2. * pnts[i].X;
                  LD c = pnts[i].X * pnts[i].X + pnts[i].Y * pnts[i].Y - 2. * pnts[i].Y * mid;
                  LD delta = b * b - 4. * c;

                  if (INF(delta, 0.)) l = 1e9, r = -1e9;
                  else {
                        LD sqDelta = sqrtl(delta);
                        LD x1 = (-b - sqDelta) * 0.5;
                        LD x2 = (-b + sqDelta) * 0.5;

                        l = max(l, x1), r = min(r, x2);
                  }
            }

            if (!SUP(l, r)) hi = mid;
            else lo = mid;
      }
      cout << fixed << setprecision(9) << lo << '\n';
}
