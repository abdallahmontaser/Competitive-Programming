#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define all(x) x.begin(), x.end()
const int inf = 2e9, mod = 998244353;
const int N = 7 * 1e3 + 3, N2 = 5000 + 3, LOGN = 20;
//--
LL a[N]; map<LL,LL>b; map<LL,vector<LL> > g; map<LL,int> occ; map<LL,bool>vis;
void dfs(LL cur){
	vis[cur] = true;
	for(auto nxt: g[cur]) if(!vis[nxt]) dfs(nxt);
}
int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for(int i = 1; i <= n; ++i) { cin >> a[i]; ++occ[a[i]]; }
	for(int i = 1; i <= n; ++i) { int bb; cin >> bb; b[a[i]] += bb; }

	for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) if(a[i] != a[j])
				if((a[i] & a[j]) == a[j]) g[a[i]].push_back(a[j]);

	for(auto ele: occ) if(ele.second > 1) dfs(ele.first);

	LL ans = 0; for(auto ele: vis) ans += b[ele.first];
	cout << ans << '\n';

	return 0;
}
