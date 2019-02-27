#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) ((ll)(x).size())
#define FOREACH(it,x) for(__typeof__((x).begin()) it = (x).begin();it!=(x).end();++it)
#define FOR(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);++i)
#define ROF(i,a,b) for(ll i=(ll)(a);i>=(ll)(b);--i)
const ld PI = 3.141592653589793238L , EPS = 1e-12L;
const ll N = 300005 , MOD = 1000000007;
using namespace std;

/**
* Editorial: https://codeforces.com/blog/entry/9425
* Another solution: https://github.com/osamahatem/CompetitiveProgramming/blob/master/Codeforces/359D.%20Pair%20of%20Numbers.cpp
* 
* For every 1 <= i <= n compute l[i] - the smallest value such that gcd(a[l[i]] .. a[i]) = a[i] and r[i] - same thing but on the right.
* These propreties are monotonic, so you can binary search.And compute the gcd of a range of length L using sparse tables in log(L) time.
* Segment trees will give TLE.
*/

ll a[N] , g[N][19];

ll f(ll i , ll j){
	ll ans = 0;
	ll len = j - i + 1;

	while(len != 0){
		ll jump = __builtin_ctzll(len);

		ans = __gcd(ans , g[i][jump]);
		
		len -= (1 << jump);
		i += (1 << jump);
	}

	return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll n; cin >> n;
	FOR(i,1,n) cin >> a[i];
	FOR(i,1,n) g[i][0] = a[i];

	FOR(j,1,18) FOR(i,1,n) if(i + (1 << j) - 1 <= n) g[i][j] = __gcd(g[i][j - 1] , g[i + (1 << (j - 1))][j - 1]);

	ll l[n + 1];
	FOR(i,1,n){
		ll lo = 1 , hi = i;
		while(lo <= hi){
			ll mid = (lo + hi) >> 1;
			
			if(f(mid , i) == a[i]) l[i] = mid , hi = mid - 1;
			else lo = mid + 1;
		}
	}

	ll r[n + 1];
	FOR(i,1,n){
		ll lo = i , hi = n;
		while(lo <= hi){
			ll mid = (lo + hi) >> 1;
			
			if(f(i , mid) == a[i]) r[i] = mid , lo = mid + 1;
			else hi = mid - 1;
		}
	}

	ll best = 0;
	FOR(i,1,n) best = max(best , r[i] - l[i]);

	vector<ll> v;
	FOR(i,1,n) if(r[i] - l[i] == best && (sz(v) == 0 || l[i] != v[sz(v) - 1])) v.pb(l[i]);

	cout << sz(v) << " " << best << '\n';
	FOR(i,0,sz(v) - 1) cout << v[i] << " ";
	cout << '\n';

    return 0;
}
