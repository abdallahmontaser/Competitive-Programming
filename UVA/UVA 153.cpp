#include <bits/stdc++.h>
#define ULL unsigned long long
#define LL long long
#define LD long double
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define loop(i, a, b) for (int i = a; i <= b; ++i)
#define pool(i, a, b) for (int i = a; i >= b; --i)
using namespace std;
const int N = 100 + 5, inf = 1e9;

set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void addFactorialFactors(map<int, int> &m, int x, int add) {
	loop(i, 1, x) {
		int tmp = i;
		for (int p : primes)
			while (tmp % p == 0) tmp /= p, m[p] += add;
	}
}
int nbStrings(string &s) {
	map<int, int> m;
	loop(c, 0, 25) addFactorialFactors(m, count(all(s), 'a' + c), -1);
	addFactorialFactors(m, sz(s), 1);

	int nb = 1;
	for (auto e : m) loop(i, 1, e.S) nb *= e.F;
	return nb;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	while (cin >> s && s != "#") {
		int ans = 0;
		string tmp = s;
		loop(i, 0, sz(s) - 1) {
			loop(c, 0, s[i] - 'a' - 1) if (count(all(tmp), char('a' + c))) {
				tmp.erase(find(all(tmp), char('a' + c)));
				ans += nbStrings(tmp);
				tmp += char('a' + c);
			}
			tmp.erase(find(all(tmp), s[i]));
		}
		cout << setw(10) << 1 + ans << '\n';
	}
}
