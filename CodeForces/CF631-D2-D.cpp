/*
  * Editorial: codeforces.com/blog/entry/43551
*/
#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define all(x) x.begin(), x.end()
using namespace std; const LD EPS = 1e-9L, PI = acos(-1.0L);
const int N = 20000 + 5, LOGN = 20, inf = 1e9, mod = (int)1e9 + 7;
/***********************************/
void computeZ(vector<pair<LL, char> >& s, vector<int>& z) {
      z.assign(size(s), 0);
      for (int i = 1, l = 0, r = 0; i < size(s); i++) {
            if (i <= r) z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < size(s) && s[z[i]] == s[i + z[i]]) ++z[i];
            if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
      }
}
int32_t main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      int n, m; cin >> n >> m;
      vector<pair<LL, char> >nS, mS;
      for (int i = 1; i <= n; ++i) {
            int nb; char c; cin >> nb >> c >> c;
            if (nS.empty() || nS.back().second != c) nS.emplace_back(nb, c);
            else nS.back().first += nb;
      }
      for (int i = 1; i <= m; ++i) {
            int nb; char c; cin >> nb >> c >> c;
            if (mS.empty() || mS.back().second != c) mS.emplace_back(nb, c);
            else mS.back().first += nb;
      }
      n = size(nS), m = size(mS);

      if (m == 1) {
            LL ans = 0; int nb = mS.front().first; char c = mS.front().second;
            for (auto el: nS) if (el.second == c) ans += max(0LL, el.first - nb + 1);
            cout << ans << "\n"; return 0;
      }

      if (m == 2) {
            int ans = 0;
            int nb1 = mS[0].first, nb2 = mS[1].first; char c1 = mS[0].second, c2 = mS[1].second;
            for (int i = 0; i + 1 <= n - 1; ++i) {
                  bool valid = true;
                  valid &= (nS[i].second == c1 && nS[i].first >= nb1);
                  valid &= (nS[i + 1].second == c2 && nS[i + 1].first >= nb2);
                  if (valid) ++ans;
            }
            cout << ans << "\n"; return 0;
      }

      vector<pair<LL, char> > concat;
      for (int i = 1; i <= m - 2; ++i) concat.push_back(mS[i]);
      concat.emplace_back(0, '#');
      for (int i = 0; i <= n - 1; ++i) concat.push_back(nS[i]);
      vector<int> z; computeZ(concat, z);

      int ans = 0;
      for (int i = m - 1; i <= size(concat) - 1; ++i) if (z[i] == m - 2) {
                  bool valid = true;
                  int st = i - (m - 1), en = st + (m - 2) - 1;
                  valid &= (st - 1 >= 0 && nS[st - 1].second == mS.front().second && nS[st - 1].first >= mS.front().first);
                  valid &= (en + 1 <= n - 1 && nS[en + 1].second == mS.back().second && nS[en + 1].first >= mS.back().first);
                  if (valid) ++ans;
            }
      cout << ans << "\n";

      return 0;
}
