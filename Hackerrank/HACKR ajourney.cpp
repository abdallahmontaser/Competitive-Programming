/**
  * The number of ways for N stairs(the formula for the statement) is 2^(N-1)
  * The last K digits of a number X = X % 10^K
  * The first K digits of a number X = X / 10^(NB-K) where NB is the number of digits in X.
  * Both are implemented below.
  *
  * The two answers fit in 'int' and so do their sum.
  * Be very careful from precision errors.
*/
#include <bits/stdc++.h>
#define LL  long long
#define LD  long double
#define F   first
#define S   second
#define sz(x)  (int)(x).size()
#define all(x) x.begin(), x.end()
using namespace std;
const int N = 100000 + 5, inf = 1e9; const LD EPS = 1e-15;

int nbDigitsPower2(int i) {
      int nb;
      int lo = 1, hi = 1e9;

      while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (log((LD)2) * i < log((LD)10) * mid) nb = mid, hi = mid - 1;
            else lo = mid + 1;
      }
      return nb;
}
int power2Mod(int p, int mod) {
      if (p == 0) return 1;
      int ans = power2Mod(p >> 1, mod);
      ans = (1LL * ans * ans) % mod;
      if (p & 1) ans = (1LL * ans * 2) % mod;
      return ans;
}
/*****************************************************************************************************/
/*****************************************************************************************************/
int main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      int tc; cin >> tc;
      while (tc--) {
            int n, k; cin >> n >> k;

            int m = 1; for (int i = 1; i <= k; ++i) m *= 10;
            int first = power2Mod(n - 1, m);

            int nb = nbDigitsPower2(n - 1);
            int second;
            int lo = m / 10, hi = m - 1;
            while (lo <= hi) {
                  int mid = (lo + hi) >> 1;

                  LD a = log((LD)2) * (n - 1) - log((LD)10) * (nb - k);
                  LD b = log((LD)mid);
                  if (fabs(a - b) < EPS || b < a) second = mid, lo = mid + 1;
                  else hi = mid - 1;
            }

            cout << first + second << '\n';
      }
}
