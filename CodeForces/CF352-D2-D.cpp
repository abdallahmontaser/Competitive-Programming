/**
  * Editorial: https://codeforces.com/blog/entry/9070
*/
#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define all(x) x.begin(), x.end()
using namespace std; const LD EPS = 1e-9L;
const int N = 3000 * 3000 + 5, LOGN = 20, inf = 1e9, mod = 998244353;
/****************************************************************/
int main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      int n; cin >> n;
      vector<int> v(n); for (int i = 0; i < n; ++i) cin >> v[i], --v[i];

      int nbSwaps = 0;
      for (int i = 0; i < n; ++i) {
            int pos = find(all(v), i) - begin(v);
            nbSwaps += pos - i;
            v.erase(begin(v) + pos);
            v.insert(begin(v) + i, i);
      }
      cout << (nbSwaps&1) + 4 * (nbSwaps / 2) << ".000000\n";
}
