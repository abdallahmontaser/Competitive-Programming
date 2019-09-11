/**
  * Editorial: https://codeforces.com/blog/entry/8800
*/
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	LL r, h;
	cin >> r >> h;
	cout << 2 * (h / r) + ((4 * (h % r) * (h % r) >= 3 * r * r) ? 3 : ((2 * (h % r) >= r) ? 2 : 1)) << '\n';
}
