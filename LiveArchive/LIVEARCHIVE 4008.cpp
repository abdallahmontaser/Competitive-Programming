#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define all(x) x.begin(), x.end()
using namespace std; const LD EPS = 1e-9L, PI = acos(-1.0L);
const int N = 1000000 + 5, LOGN = 20, inf = 1e9, mod = (int)1e9 + 7;
/***********************************/
int pf[N];
void add(map<int, int>&m, int x, int val) {
      for (int y = 1; y <= x; ++y) {
            int z = y;
            while (z > 1) {
                  m[pf[z]] += val;
                  z /= pf[z];
            }
      }
}
int pow(int x, int n, int m) {
      if (n == 0) return 1;
      int y = pow(x, n / 2, m);
      y = ((LL)y * y) % m; if (n & 1) y = ((LL)y * x) % m;
      return y;
}
int32_t main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      for (int i = 1; i <= N - 1; ++i) pf[i] = i;
      for (int i = 2; i <= N - 1; ++i) for (int j = i + i; j <= N - 1; j += i) if (pf[j] == j) pf[j] = i;

      string s; while (cin >> s) {
            map<int, int> primePowers;
            add(primePowers, s.size(), 1);
            for (char c = 'a'; c <= 'z'; ++c) add(primePowers, count(all(s), c), -1);

            int remov = min(primePowers[2], primePowers[5]);
            primePowers[2] -= remov;
            primePowers[5] -= remov;

            int d = 1;
            for (auto el: primePowers) d = (d * pow(el.first, el.second, 10)) % 10;
            cout << d << "\n";
      }
      return 0;
}
