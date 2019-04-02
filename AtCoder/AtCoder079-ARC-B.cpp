#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
#define ll long long
using namespace std;

/**
* Editorial: https://img.atcoder.jp/arc079/editorial.pdf
*/

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll k; cin >>k;
  int n = 50;
	ll a[n + 1]; for(int i = 1; i <= n; ++i) a[i] = k / n + i - 1;

	k %= n;
	while(k--){
        a[1] += n;
        for(int i = 2; i <= n; ++i) --a[i];

        sort(a + 1 , a + n + 1);
	}

	cout << n << '\n';
	for(int i = 1; i <= n; ++i) cout << a[i] << ' ';
	cout << '\n';

  return 0;
}
