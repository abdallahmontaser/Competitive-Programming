#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define F  first
#define S  second
#define sz(x)  (int)(x).size()
#define all(x) x.begin(), x.end()
using namespace std; const LD EPS = 1e-9L;
const int N = 500 + 5, LOGN = 20, inf = 1e9, mod = 998244353;
/***********************************************************/
#define int long long
LL binSearch(int lo, int hi, LL x, function<LL(LL)> f) {
      while (lo <= hi) {
            LL mid = (lo + hi) >> 1;
            LL cur = f(mid);

            if (cur == x) return mid;
            if (cur < x) lo = mid + 1;
            else hi = mid - 1;
      }
      return 0LL;
}
vector<LL> a; map<LL, int> nbAi, nbPrime;
int32_t main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      int n; cin >> n;
      for (int i = 1; i <= n; ++i) { LL x; cin >> x; ++nbAi[x]; a.push_back(x); }
	sort(all(a)); a.resize(unique(all(a)) - begin(a));

      int ans = 1;
      for (int i = 0; i < sz(a); ++i) {
            int cnt = nbAi[a[i]];

            if (LL p = binSearch(1LL, (LL)6e4, a[i], [](LL arg) -> LL { return arg * arg * arg * arg; })) nbPrime[p] += 4 * cnt;
            else if (LL p = binSearch(1LL, (LL)2e6, a[i], [](LL arg) -> LL { return arg * arg * arg; })) nbPrime[p] += 3 * cnt;
            else if (LL p = binSearch(1LL, (LL)2e9, a[i], [](LL arg) -> LL { return arg * arg; })) nbPrime[p] += 2 * cnt;
            else {
                  LL g = 1;
                  for (int j = 0; j < sz(a); ++j) if (i != j) g = max(g, __gcd(a[i], a[j]));

                  if (g != 1) nbPrime[g] += cnt, nbPrime[a[i] / g] += cnt;
                  else ans = ((LL)ans * (cnt + 1) * (cnt + 1)) % mod;
            }
      }
      for (auto element: nbPrime) ans = ((LL)ans * (element.S + 1)) % mod;
      cout << ans << '\n';
}
