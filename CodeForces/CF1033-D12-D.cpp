/**
  * Editorial: https://codeforces.com/blog/entry/62287
*/
#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define F  first
#define S  second
#define sz(x)  (int)(x).size()
#define all(x) x.begin(), x.end()
using namespace std; const LD EPS = 1e-9L;
const int N = 500 + 5, LOGN = 20, inf = 1e9, mod = 998244353;
/**************/
vector<LL> a; map<LL, int> occ;
int32_t main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      int n; cin >> n;
      for (int i = 1; i <= n; ++i) {
            LL x; cin >> x;
            ++occ[x];
            if (occ[x] == 1) a.push_back(x);
      }

      map<LL, int> primeOcc;
      int ans = 1;
      for (int i = 0; i < sz(a); ++i) {
            int cnt = occ[a[i]];
            LL p = 0;
            LL lo = 1, hi = 6e4;
            while (lo <= hi) {
                  LL mid = (lo + hi) / 2;
                  LL cur = mid * mid * mid * mid;

                  if (cur == a[i]) p = mid;
                  if (cur < a[i]) lo = mid + 1;
                  else hi = mid - 1;
            }
            if (p) {
                  primeOcc[p] += 4 * cnt; continue;
            }

            lo = 1, hi = 2e6;
            while (lo <= hi) {
                  LL mid = (lo + hi) / 2;
                  LL cur = mid * mid * mid;

                  if (cur == a[i]) p = mid;
                  if (cur < a[i]) lo = mid + 1;
                  else hi = mid - 1;
            }
            if (p) {
                  primeOcc[p] += 3 * cnt; continue;
            }

            lo = 1, hi = 2e9;
            while (lo <= hi) {
                  LL mid = (lo + hi) / 2;
                  LL cur = mid * mid;

                  if (cur == a[i]) p = mid;
                  if (cur < a[i]) lo = mid + 1;
                  else hi = mid - 1;
            }
            if (p) {
                  primeOcc[p] += 2 * cnt; continue;
            }

            for (int j = 0; j < sz(a); ++j) if (a[i] != a[j] && __gcd(a[i], a[j]) != 1) p = __gcd(a[i], a[j]);
            if (p) {
                  primeOcc[p] += cnt; primeOcc[a[i] / p] += cnt; continue;
            }

            ans = ((LL)ans * (cnt + 1)) % mod;
            ans = ((LL)ans * (cnt + 1)) % mod;
      }

      for (auto el: primeOcc) ans = ((LL)ans * (el.S + 1)) % mod;
      cout << ans << '\n';
}
