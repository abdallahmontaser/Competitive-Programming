/**
  * Beware! The string can be empty!
  * The answer is, by dynamic programming, dp[1][n]
  * Where dp[i][j] is either dp[i+1][j-1] or dp[i][k] + dp[k+1][j] for some k in (i;j)
  * Other solutions: https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/UVA/UVA_1626.txt
*/
#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define F  first
#define S  second
#define sz(x)  (int)(x).size()
#define all(x) x.begin(), x.end()
using namespace std;
const int N = 300 + 5, inf = 1e9; const LD EPS = 1e-9L;
int dp[N][N]; string s;
bool match(char a, char b) {
      return (a == '(' && b == ')') || (a == '[' && b == ']');
}
int minChars(int i, int j) {
      if (j - i + 1 <= 1) return j - i + 1;
      int &ans = dp[i][j]; if (ans != -1) return ans; ans = inf;
      for (int k = i; k <= j - 1; ++k) ans = min(ans, minChars(i, k) + minChars(k + 1, j));
      if (match(s[i - 1], s[j - 1])) ans = min(ans, minChars(i + 1, j - 1));
      return ans;
}
void print(int i, int j) {
      int len = j - i + 1;

      if (len <= 0) return;
      else if (len == 1) {
            if (s[i - 1] == '(' || s[i - 1] == ')') cout << "()";
            else cout << "[]";
      }
      else {
            for (int k = i; k <= j - 1; ++k) if (minChars(i, j) == minChars(i, k) + minChars(k + 1, j)) {
                        print(i, k); print(k + 1, j); return;
                  }

            if (match(s[i - 1], s[j - 1]) && minChars(i, j) == minChars(i + 1, j - 1)) {
                  cout << s[i - 1]; print(i + 1, j - 1); cout << s[j - 1];
            }
      }
}
/**********************************************************/
int32_t main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      vector<string> input;
      while (getline(cin, s)) input.push_back(s);

      for (int iii = 2; iii < sz(input); iii += 2) {
            s = input[iii];
            
		for (int i = 0; i <= sz(s); ++i) for (int j = 0; j <= sz(s); ++j) dp[i][j] = -1;
            if (s != "") print(1, sz(s));
            cout << '\n';

            if (iii + 2 < sz(input)) cout << '\n';
      }
}
