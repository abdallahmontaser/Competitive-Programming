/**
* Editorial: https://img.atcoder.jp/agc026/editorial.pdf
* Other explanation: https://codeforces.com/blog/entry/60562?#comment-445168
*/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define all(x) x.begin(), x.end()
const int inf = 2e9, mod = 1e9 + 7;
const int N = 15 + 3, N2 = 5000 + 3, LOGN = 20;
LL a,b,c,d;
bool forever(){
	if(min(a,d) < b) return false;
	if(c >= b - 1) return true;
	LL k = (b - a % b + __gcd(b,d) - 1) / __gcd(b,d) - 1;
	return !(k > (c - a % b) / (__gcd(b,d)) || c < a % b);
}
int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	while(tc--) {
		cin >> a >> b >> c >> d;
		cout << (forever() ? "Yes" : "No") << "\n";
	}
	return 0;
}
