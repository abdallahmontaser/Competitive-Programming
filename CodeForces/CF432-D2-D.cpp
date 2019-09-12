/**
  * Editorial: https://codeforces.com/blog/entry/12310
*/
#include <bits/stdc++.h>
#define ULL unsigned long long
#define LL long long
#define LD long double
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
using namespace std;
const int N = 100000 + 5, inf = 1e9;

int cnt[N];

void computeZ(string &s, vector<int> &z) {
	z.resize(sz(s), 0);
	int l = 0, r = 0;
	for (int i = 1; i < sz(s); i++) {
		z[i] = max(0, min(z[i - l], r - i + 1));
		while (i + z[i] < sz(s) && s[z[i]] == s[i + z[i]]) {
			l = i, r = i + z[i];
			++z[i];
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	cin >> s;

	vector<int> z;
	computeZ(s, z);
	z[0] = sz(s);

	for (int i = 0; i < sz(s); ++i) ++cnt[z[i]];
	for (int i = sz(s) - 1; i >= 1; --i) cnt[i] += cnt[i + 1];

	vector<pair<int, int>> ans;
	for (int i = sz(s) - 1; i >= 0; --i) if (i + z[i] == sz(s)) ans.push_back({z[i], cnt[z[i]]});
	cout << sz(ans) << '\n';
	for (auto p : ans) cout << p.F << ' ' << p.S << '\n';
}
