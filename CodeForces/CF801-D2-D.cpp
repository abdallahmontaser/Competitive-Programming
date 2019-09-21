/*
  * Editorial: https://codeforces.com/blog/entry/51598
  * Other code: https://github.com/MeGaCrazy/CompetitiveProgramming/blob/ff934b5231a55818d401805db5e0caa0720a1fa4/Codeforces/CF801-D2-D.cpp
*/
#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define F  first
#define S  second
#define sz(x)     (int)(x).size()
#define all(x)    x.begin(), x.end()
using namespace std;
const int N = 300000 + 5, inf = 1e9; const LD EPS = 1e-9;
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
LD norm(const point &p) {
      return sqrtl(p.X * p.X + p.Y * p.Y);
}
point center(point &a, point &b) {
      return (a + b) * 0.5;
}
point perp(const point &p) {
      return point{ p.Y, -p.X };
}
bool intersectLines(point &answer, const point &a, const point &b, const point &c, const point &d) {
      LD A1 = b.Y - a.Y, B1 = a.X - b.X, C1 = A1 * a.X + B1 * a.Y;
      LD A2 = d.Y - c.Y, B2 = c.X - d.X, C2 = A2 * c.X + B2 * c.Y;
      LD determinant = A1 * B2 - A2 * B1;

      if (EQU(determinant, 0)) return 0;   // parallel

      answer = point{ (B2 * C1 - B1 * C2) / determinant, (A1 * C2 - A2 * C1) / determinant };
      return 1;
}
/*****************************************************************************************************/
signed main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      int n; cin >> n;
      point arr[n + 1]; for (int i = 1; i <= n; ++i) cin >> arr[i].X >> arr[i].Y;
      LD ans = 1e18L;
      for (int i = 1; i <= n; ++i) {
            point j = arr[(i != n) ? i + 1 : 1];
            point k = arr[(i != 1) ? i - 1 : n];
            point ii; intersectLines(ii, arr[i], arr[i] + perp(k - j), j, k);
            ans = min(ans, norm(arr[i] - ii) * 0.5);
      }
      cout << fixed << setprecision(9) << ans << '\n';
	//
}
