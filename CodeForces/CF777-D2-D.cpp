#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define all(x) x.begin(), x.end()
const int inf = 2e9, mod = 1e9 + 7;
const int N = 5 * 1e5 + 3, N2 = 5000 + 3, LOGN = 20;
//--
string str[N]; int sz[N];
int lcp(int i,int j){
	int ind = 0;
	while(ind < min(sz[i],sz[j]) && str[i][ind] == str[j][ind]) ++ind;
	return ind;
}
int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> str[i]; sz[i] = size(str[i]);
	}
	for(int i = n - 1; i >= 1; --i) {
		int nb = lcp(i,i + 1);
		char a = ((nb == sz[i]) ? ('a' - 1) : str[i][nb]);
		char b = ((nb == sz[i + 1]) ? ('a' - 1) : str[i + 1][nb]);
		if(a > b) sz[i] = nb;
	}
	for(int i = 1; i <= n; ++i) cout << str[i].substr(0,sz[i]) << '\n';
	return 0;
}
