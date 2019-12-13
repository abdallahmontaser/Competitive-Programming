#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define all(x) x.begin(), x.end()
const int inf = 2e9, mod = 998244353;
const int N = 1e5 + 3, N2 = 5000 + 3, LOGN = 20;
//--
int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	LL n,a,b,c; cin >> n >> a >> b >> c;
	LL ans = 0;
	while(true) {
		bool aa = (n >= a), bb = (n >= b);

		if(!aa && !bb) break;
		else if(aa && (!bb || a <= b - c)) ans +=  n / a, n %= a;
		else {
			LL toBuy = max(0LL,(n - c) / (b - c));
			ans += toBuy;
			n -= toBuy * (b - c);
		}
	}
	cout << ans << '\n';
	return 0;
}
