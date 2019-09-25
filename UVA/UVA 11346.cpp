/**
  * Let's work only on the rectangle [0;a] x [0;b], it clearly doesn't affect the final answer.
  * If S=0, the answer is 100%
  * Else, I'm going to calculate the area(with an integral) of min(b,S/x) with x in [0;a].
  * That area, divided by the area of the full rectangle(a*b) will give the probability that a chosen point (x,y) will give us
  * a rectangle with area <= S.
  * The answer is 100 * (1 - that value)
*/
#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define F  first
#define S  second
#define sz(x)  (int)(x).size()
#define all(x) x.begin(), x.end()
using namespace std;
const int N = 100000 + 5, inf = 2e9; const LD EPS = 1e-9L;
/**********************************************************/
signed main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      int tc; cin >> tc;
      for (int t = 1; t <= tc; ++t) {
            LD a, b, s; cin >> a >> b >> s;
            LD ans;
            if (s < EPS) ans = 100.L;
            else if (a * b <= s) ans = 0.L;
            else ans = 100.L * (1.L - (s * (1.L + log(a * b / s))) / (a * b));
            cout << fixed << setprecision(6) << ans  << "%\n";
      }
}
