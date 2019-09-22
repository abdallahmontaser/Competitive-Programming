/**
  * Editorial: https://codeforces.com/blog/entry/4488
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
/*****************************************************************************************************/
signed main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      LD S; cin >> S;
      LD a, b, c; cin >> a >> b >> c;
      LD sum = max(1.L, a + b + c);

      cout << fixed << setprecision(14);
      cout << S * a / sum << ' ' << S * b / sum << ' ' << S * c / sum << '\n';
}
