/**
  * Solved with two pointer.
  * Other solutions: https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Codeforces/CF101864-GYM-L.txt
*/
#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define F  first
#define S  second
#define sz(x)  (int)(x).size()
#define all(x) x.begin(), x.end()
using namespace std;
const int N = 100000 + 5, inf = 2e9; const LD EPS = 1e-9L;
/**********************************************************/
signed main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      int tc; cin >> tc;
      for (int t = 1; t <= tc; ++t) {
            int n, p; cin >> n >> p;
            vector<pair<int, int> > events;
            for (int i = 1; i <= n; ++i) {
                  int x, y; cin >> x >> y;
                  events.push_back({ x, -i });
                  events.push_back({ y, i });
            }
            sort(all(events));

            int r = -1, cnt = 0;
            int best = inf;
            for (int l = 0; l < sz(events); ++l) {
                  while ((cnt < p && r + 1 < sz(events)) || r < l) {
                        ++r;
                        if (events[r].S < 0) ++cnt;
                  }
                  if (cnt == p) best = min(best, events[r].F - events[l].F);
			            if (events[l].S > 0) --cnt;
            }

            cout << "Case " << t << ": " << best << '\n';
      }
}
