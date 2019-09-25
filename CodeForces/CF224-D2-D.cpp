/**
  * Editorial: https://codeforces.com/blog/entry/5301
  * Other solution: https://github.com/abdullaAshraf/Problem-Solving/blob/master/CodeForces/CF224-D2-D.cpp
*/
#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define F  first
#define S  second
#define sz(x)  (int)(x).size()
#define all(x) x.begin(), x.end()
using namespace std;
const int N = 200000 + 5, inf = 2e9; const LD EPS = 1e-9L;
vector<pair<int, int> > pairs[26];
vector<int> mn[26];
int leftSub[N], rightSub[N];
void computeSub(string & a, string & b, int ans[]) {
      for (int i = 0; i < sz(a); ++i) {
            int prv = 0; if (i != 0) prv = ans[i - 1];
            if (prv == sz(b) || a[i] != b[prv]) ans[i] = ans[i - 1];
            else ans[i] = 1 + ans[i - 1];
      }
}
/**********************************************************/
int32_t main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      string s, t; cin >> s >> t;
      for (int i = 0; i < sz(t); ++i) {
            int l = i, r = sz(t) - 1 - i;
            pairs[t[i] - 'a'].push_back({ l, r });
      }
      for (int c = 0; c < 26; ++c) {
            sort(all(pairs[c]));
            for (int i = 0; i < sz(pairs[c]); ++i) {
                  if (i == 0) mn[c].push_back(pairs[c][i].S);
                  else mn[c].push_back(min(pairs[c][i].S, mn[c][i - 1]));
            }
      }

      computeSub(s, t, leftSub);
      
      reverse(all(s)), reverse(all(t));
      computeSub(s, t, rightSub);

      reverse(all(s)), reverse(rightSub, rightSub + sz(s));
      for (int i = 0; i < sz(s); ++i) {
            int a = 0, b = 0;
            if (i != 0) a = leftSub[i - 1];
            if (i != sz(s) - 1) b = rightSub[i + 1];

            pair<int, int> p = { a, inf };
            if (pairs[s[i] - 'a'].empty() || pairs[s[i] - 'a'][0] > p) {
                  cout << "No\n"; return 0;
            }

            int ind = upper_bound(all(pairs[s[i] - 'a']), p) - begin(pairs[s[i] - 'a']);
            if (mn[s[i] - 'a'][ind - 1] > b) {
                  cout << "No\n"; return 0;
            }
      }

      cout << "Yes\n";
}
