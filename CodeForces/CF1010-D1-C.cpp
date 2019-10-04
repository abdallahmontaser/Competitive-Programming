/**
  * Editorial: https://codeforces.com/blog/entry/60851
*/
#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define F  first
#define S  second
#define sz(x)  (int)(x).size()
#define all(x) x.begin(), x.end()
using namespace std;
const int N = 100000 + 5, inf = 1e9; const LD EPS = 1e-9L;
/**********************************************************/
int32_t main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      int n, k; cin >> n >> k;
      int g = 0; for (int i = 1; i <= n; ++i) { int x; cin >> x; g = __gcd(g, x % k); }
      vector<int> ans = { g };
      int tmp = g;
      while (true) {
            tmp = (tmp + g) % k;
            if (tmp == g) break;
            ans.push_back(tmp);
      }
      sort(all(ans));
      cout << sz(ans) << '\n'; for (int x: ans) cout << x << ' '; cout << '\n';
}
