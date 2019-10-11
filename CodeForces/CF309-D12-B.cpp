/**
  * Editorial: https://codeforces.com/blog/entry/7749
*/
#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define F  first
#define S  second
#define sz(x)  (int)(x).size()
#define all(x) x.begin(), x.end()
using namespace std;
const int N = 1000000 + 5, LOGN = 20, inf = 1e9; const LD EPS = 1e-9L;
string a[N]; int nb[N][LOGN];
/**************/
int32_t main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      int n, R, C; cin >> n >> R >> C;
      for (int i = 1; i <= n; ++i) cin >> a[i];

      int r = 0, sum = 0;
      for (int l = 1; l <= n; ++l) {
            if (sz(a[l]) > C) {
                  r = l; nb[l][0] = 0; continue;
            }
            while (r + 1 <= n && sum + sz(a[r + 1]) + r + 1 - l <= C) sum += sz(a[r + 1]), ++r;
            nb[l][0] = r - l + 1;
            sum -= sz(a[l]);
      }
      nb[n + 1][0] = 0;

      for (int lg = 1; lg <= LOGN - 1; ++lg) for (int i = 1; i <= n + 1; ++i) {
                  int nxt = i + nb[i][lg - 1];
                  nb[i][lg] = nb[i][lg - 1] + nb[nxt][lg - 1];
            }

      vector<int>binaryRep;
      for (int b = 0; b < LOGN; ++b) if (R & (1 << b)) binaryRep.push_back(b);

      int mx = 0, best = -1;
      for (int i = 1; i <= n; ++i) {
            int cur = i, nbWords = 0;
            for (int x: binaryRep) nbWords += nb[cur][x], cur += nb[cur][x];
            if (nbWords > mx) mx = nbWords, best = i;
      }

      int curLine = 0;
      for (int i = best; i < best + mx; ++i) {
            if (curLine + (curLine != 0) + sz(a[i]) > C) {
                  cout << '\n'; curLine = 0;
			            --i; continue;
            }

            if (curLine != 0) cout << ' ', ++curLine;
            curLine += sz(a[i]);
            cout << a[i];
      }
}
