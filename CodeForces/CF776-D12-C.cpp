#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define all(x) x.begin(), x.end()
const int inf = 2e9, mod = 998244353;
const int N = 1 * 1e5 + 3, N2 = 5000 + 3, LOGN = 20;
//--
map<LL,int> occ;
int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,k; cin >> n >> k;
  
	vector<LL> powers;
	if(k == 1) powers = {1};
	else if(k == -1) powers = {-1,1};
	else{
		LL curPower = 1; LL limit = 1e14L;
		while(abs(curPower) <= limit) powers.push_back(curPower), curPower *= k;
	}

	LL ans = 0; ++occ[0]; LL curSum = 0;
	for(int i = 1; i <= n; ++i) {
		LL x; cin >> x; curSum += x;
		for(LL p: powers) ans += occ[curSum - p];
		++occ[curSum];
	}
	cout << ans << '\n';
	return 0;
}
