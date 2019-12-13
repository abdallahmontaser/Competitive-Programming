/**
* The number of turns before no more turns can be made is fixed.
* Because the stones will eventually end up like this: 0,1,2,3... (unless there's a duplicate after the first turn)
* Find it and decide the winner based on it's parity.
*/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define all(x) x.begin(), x.end()
const int inf = 2e9, mod = 998244353;
const int N = 1e5 + 3, N2 = 5000 + 3, LOGN = 20;
//--
int a[N];
int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1,a + 1 + n);

	int nbDuplicate = 0; int ind;
	for(int i = 2; i <= n; ++i) if(a[i] == a[i - 1]) {
			++nbDuplicate;
			ind = i - 1;
		}

	if(nbDuplicate > 1) {cout << "cslnb\n"; return 0;}
	a[0] = -1;
	if(nbDuplicate == 1 && a[ind] == a[ind - 1] + 1) {cout << "cslnb\n"; return 0;}

	int operations = 0;
	for(int i = 1; i <= n; ++i) operations += a[i] - a[i - 1] - 1, a[i] = a[i - 1] + 1;

	if(operations % 2) cout << "sjfnb\n";
	else cout << "cslnb\n";
	return 0;
}
