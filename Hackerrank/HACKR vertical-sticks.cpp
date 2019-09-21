/**
  * The expected total value is the sum of the expected values for each Ai.
  * The expected value of a certain Ai is the sum of {d * probability(Ai,d)} where d is every possible distance Ai can reach,
  * and probability(Ai,d) is the number of permutations that give 'Ai' a distance 'd'
  * divided on the number of permutations = N!
  * To get that number, you just need to know X = how many j such that Aj >= Ai && j != i
*/
#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define F  first
#define S  second
#define sz(x)  (int)(x).size()
#define all(x) x.begin(), x.end()
using namespace std;
const int N = 300000 + 5, inf = 1e9; const LD EPS = 1e-9;
/*****************************************************************************************************/

/*****************************************************************************************************/
signed main() {
      int tc; cin >> tc;

      while (tc--) {
            int n; cin >> n;
            int arr[n + 1]; for (int i = 1; i <= n; ++i) cin >> arr[i];

            LD ans = 0;
            for (int i = 1; i <= n; ++i) {
                  int x = 0;
                  for (int j = 1; j <= n; ++j) if (arr[i] <= arr[j] && i != j) ++x;

                  if (x == 0) ans += 0.5 * (n + 1);
                  else for (int d = 1; d <= n - x; ++d) {
                              vector<int> a, b;
                              for (int aa = n - d - x + 1; aa <= n - d; ++aa) a.push_back(aa);
                              for (int bb = n - x; bb <= n; ++bb) b.push_back(bb);
                              LD result = 1;
                              for (int& aa: a) for (int& bb: b) {
                                          int g = __gcd(aa, bb);
                                          aa /= g, bb /= g;
                                    }
                              for (int aa:a) result *= aa;
                              for (int bb:b) result /= (LD)bb;

                              ans += result * d * (x + 1);
                        }
            }
            cout << fixed << setprecision(2) << ans << endl;
      }
}
