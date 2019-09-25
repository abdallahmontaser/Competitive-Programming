/**
  * Editorial: https://codeforces.com/blog/entry/1773
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
            LD a, b; cin >> a >> b;
            LD ans;
            if (a < EPS && b < EPS) ans = 1.L;
            else if (a / 4.L <= b) ans = 0.5L + 0.0625L * a / b;
            else ans = 1.L - b / a;
            cout << fixed << setprecision(6) << ans  << '\n';
      }
}
