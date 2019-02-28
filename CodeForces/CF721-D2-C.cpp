#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) ((ll)(x).size())
#define FOR(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);++i)
#define ROF(i,a,b) for(ll i=(ll)(a);i>=(ll)(b);--i)
const ld PI = 3.141592653589793238L , EPS = 1e-12L;
const ll N = 300005 , MOD = 1000000007;
using namespace std;

/**
* Editorial: http://codeforces.com/blog/entry/47457
*/

ll n;
vector<pair<ll,ll>> g[5001];
ll dp[5001][5001];

ll solve(ll i , ll nb){ // minimum time to go from "i" to "n" and visit nb nodes.
	if(i == n && nb == 1) return 0;
	if(i == n || nb == 1) return 2e9;

	ll &ans = dp[i][nb];
	if(ans != -1) return ans;

	ans = 2e9;
	for(auto j: g[i]) ans = min(ans , j.S + solve(j.F , nb - 1));

	return ans;
}

void print(ll i , ll nb){
	cout << i << ' ';
	if(i == n){
		cout << '\n';
		return;
	}

	ll nxt;
	for(auto j: g[i]) if(solve(i , nb) == j.S + solve(j.F , nb - 1)) nxt = j.F;

	print(nxt , nb - 1);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll m,t; cin >> n >> m >> t;
	FOR(i,1,m){
		ll u,v,w; cin >> u >> v >> w;
		g[u].pb(mp(v , w));
	}

	memset(dp,-1,sizeof(dp));

	ll ans;
	FOR(i,2,n) if(solve(1 , i) <= t) ans = i;

	cout << ans << '\n';
	print(1,ans);

    return 0;
}
