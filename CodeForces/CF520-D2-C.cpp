#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define all(x) x.begin(), x.end()
const int inf = 2e9, mod = 1e9 + 7;
const int N = 1 * 1e5 + 3, N2 = 5000 + 3, LOGN = 20;
//--
int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; string s; cin >> n >> s;
	vector<int> occ; for(char c: {'A','C','G','T'}) occ.push_back(count(all(s),c));
	int nb = count(all(occ),*max_element(all(occ)));
	int ans = 1; for(int i = 1; i <= n; ++i) ans = ((LL)ans * nb) % mod;
	cout << ans << '\n';
	return 0;
}
