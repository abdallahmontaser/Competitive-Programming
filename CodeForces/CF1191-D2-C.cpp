/**
* Simulate the process of deletion. To find out the real index of an item, you'll only need to keep record
* of the number of removed items so far(because those will be before it).
*/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define all(x) x.begin(), x.end()
const int inf = 2e9, mod = 998244353;
const int N = 200000 + 3, N2 = 5000 + 3, LOGN = 20;
//--
set<LL> specials;
int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	LL n,k; int m; cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i) { LL x; cin >> x; specials.insert(x - 1); }
	// x - 1  so I can find out the "group" of x using x/k

	int ans = 0,removedSoFar = 0;
	while(!empty(specials)) {
		LL fst = *begin(specials) - removedSoFar;

		int nbToRemove = 0;
		auto it = begin(specials);
		while(it != end(specials) && (*it - removedSoFar) / k == fst / k) {
			++nbToRemove; ++it;
		}

		for(int cnt = 1; cnt <= nbToRemove; ++cnt) specials.erase(begin(specials));
		removedSoFar += nbToRemove;
		++ans;
	}
	cout << ans << '\n';
	return 0;
}
