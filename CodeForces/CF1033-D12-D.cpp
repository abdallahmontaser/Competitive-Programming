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
int main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      int n; cin >> n;
      for (int i = 1; i <= n; ++i) { LL x; cin >> x; ++nbAi[x]; if (nbAi[x] == 1) a.push_back(x); }

      int ans = 1;
      for (int i = 0; i < sz(a); ++i) {
            int cnt = nbAi[a[i]];

            LL p = binSearch(1LL, (LL)6e4, a[i], [](LL arg) -> LL { return arg * arg * arg * arg; });
            if (p) { nbPrime[p] += 4 * cnt; continue; }

            p = binSearch(1LL, (LL)2e6, a[i], [](LL arg) -> LL { return arg * arg * arg; });
            if (p) { nbPrime[p] += 3 * cnt; continue; }

            p = binSearch(1LL, (LL)2e9, a[i], [](LL arg) -> LL { return arg *  arg; });
            if (p) { nbPrime[p] += 2 * cnt; continue; }

            for (int j = 0; j < sz(a); ++j) if (a[i] != a[j] && __gcd(a[i], a[j]) != 1) p = __gcd(a[i], a[j]);
            if (p) { nbPrime[p] += cnt; nbPrime[a[i] / p] += cnt; continue; }

            ans = ((LL)ans * (cnt + 1)) % mod;
            ans = ((LL)ans * (cnt + 1)) % mod;
      }

      for (auto element: nbPrime) ans = ((LL)ans * (element.S + 1)) % mod;
      cout << ans << '\n';
}
