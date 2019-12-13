/**
* Code commented.
*/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define all(x) x.begin(), x.end()
const int inf = 2e9, mod = 998244353;
const int N = 1e5 + 3, N2 = 5000 + 3, LOGN = 20;
//--
map<int,map<char,int> > prf;
int count(int l,int r,char c){ return prf[r][c] - prf[l - 1][c]; }
int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,k; cin >> n >> k;
	string s; cin >> s;

	// Can the first player win immediatly?
	int first0 = find(all(s),'0') - begin(s);
	string zero = "0"; int last0 = find_end(all(s),all(zero)) - begin(s);

	int first1 = find(all(s),'1') - begin(s);
	string one = "1"; int last1 = find_end(all(s),all(one)) - begin(s);

	if(min(last0 - first0 + 1,last1 - first1 + 1) <= k) {
		cout << "tokitsukaze\n"; return 0;
	}

	// Can the second player win in the second turn regardless of the first move?
	for(char c = '0'; c <= '1'; ++c) {
		prf[0][c] = (s[0] == c);
		for(int i = 1; i < size(s); ++i) prf[i][c] = (s[i] == c) + prf[i - 1][c];
	}

	bool canWin = true;
	for(int i = 0,j = k - 1; j < n; ++i,++j) for(char c = '0'; c <= '1'; ++c) {
			// What if the first move was making the interval [i;j] equal to c?
			int nbLeft = count(0,i - 1,c), nbRight = count(j + 1,n - 1,c);
			int lenLeft = i, lenRight = n - 1 - j;

			if(nbLeft == lenLeft && lenRight <= k) continue;
			else if(nbRight == lenRight && lenLeft <= k) continue;
			else canWin = false;
		}
	if (canWin) {cout << "quailty\n"; return 0;}

	// Else it's a draw
	cout << "once again\n";
	return 0;
}
