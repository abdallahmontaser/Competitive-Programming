#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define LL long long
#define LD long double
#define all(x) x.begin(), x.end()
const int inf = 2e9, mod = 998244353;
const int N = 1e5 + 3, N2 = 5000 + 3, LOGN = 20;
//--
vector<pair<int,int> > pnts; ordered_set xSet;
int cnt(int l,int r){ // how many integers l < a < r inside the set 'xSet'
	return xSet.order_of_key(r) - xSet.order_of_key(l) - (xSet.find(l) != end(xSet));
}
int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for(int i = 1; i <= n; ++i) { int x,y; cin >> x >> y; pnts.push_back({y,x});}
	sort(all(pnts)); for(auto&p: pnts) swap(p.first,p.second);

	LL ans = 0;
	while(!empty(pnts)) {
		int curY = pnts.back().second;
		vector<int> curX;
		while(!empty(pnts) && pnts.back().second == curY) {
			curX.push_back(pnts.back().first);
			pnts.pop_back();
		}
		sort(all(curX));

		vector<int> nbInBetween;
		nbInBetween.push_back(cnt(0, curX.front()) + 1);
		for(int i = 0; i + 1 < size(curX); ++i) nbInBetween.push_back(cnt(curX[i],curX[i + 1]) + 1);
		nbInBetween.push_back(cnt(curX.back(), inf) + 1);

		int sum = accumulate(all(nbInBetween), 0);
		LL curAns = 0; for(int nb: nbInBetween) curAns += (LL)nb * (sum - nb);
		curAns /= 2;

		ans += curAns;
		for(int x: curX) xSet.insert(x);
	}
	cout << ans << '\n';

	return 0;
}
