#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
#define sz(x) ((ll)(x).size())
#define EPS ((ld)1e-12)
#define endl '\n'
#define FOREACH(it,x) for(__typeof__((x).begin()) it = (x).begin();it!=(x).end();++it)
#define FOR(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);++i)
#define ROF(i,a,b) for(ll i=(ll)(a);i>=(ll)(b);--i)
#define in(x) cin>>x
#define out(x) cout<<x
const ld PI = 3.141592653589793238L;
const ll N = 2000005 , MOD = 1000000007;
using namespace std;

/**
* First I binary searched over the maximum possible number of blocks(which is <= 18)
* Then I found the smallest volume that gives that number of blocks and tried to maximize it while maintaining
* The number of blocks
* 
* Better solution in the editorial: 
*/

ll p[N];

ll f(ll x){
	ll nb = 0;

	while(x != 0){
		ll lo = 1 , hi = 1e5;
		ll ans;
		while(lo <= hi){
			ll mid = (lo + hi) >> 1;

			if(x >= p[mid]) ans = p[mid] , lo = mid + 1;
			else hi = mid - 1;
		}

		nb += x / ans , x %= ans;
	}

	return nb;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //<<>>

	ll m; in(m);

	FOR(i,1,N - 1) p[i] = i * i * i;

	ll lo = 1 , hi = 18;
	ll ans,x;
	while(lo <= hi){
		ll mid = (lo + hi) >> 1;

		ll sum = 0 , curr = 1 , nb = mid;
		while(sum <= m && nb != 0 && curr < N - 1){
			ll take = min((p[curr + 1] - sum - 1) / p[curr] , nb);

			nb -= take;
			sum += take * p[curr];

			++curr;
		}

		if(sum > m || curr >= N - 1) hi = mid - 1;
		else ans = mid , x = sum , lo = mid + 1;
	}

	vector<ll> v;
	ll tmp = x;
	ROF(i,1e5,1){
		FOR(j,1,tmp / p[i]) v.pb(p[i]);
		tmp %= p[i];
	}

	FOR(i,0,sz(v) - 1){
		ll ind; FOR(j,0,N - 1) if(p[j] == v[i]) ind = j;

		ll lo = ind , hi = N - 1;
		ll best = v[i];
		while(lo <= hi){
			ll mid = (lo + hi) >> 1;

			if(f(x + p[mid] - v[i]) == ans && x + p[mid] - v[i] <= m) best = p[mid] , lo = mid + 1;
			else hi = mid - 1;
		}

		x += best - v[i];
		v[i] = best;
	}

	out(ans) , out(" ") , out(x) , out(endl);

    return 0;
}
