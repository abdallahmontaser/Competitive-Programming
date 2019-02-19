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
const ld PI = 3.141592653589793238L;
const ll N = 1000005 , MOD = 1000000007;
using namespace std;

/**
* Complicated and not-understandable editorial: https://codeforces.com/blog/entry/9657
* Simple yet non proven solution in the comments: https://codeforces.com/blog/entry/9657?#comment-151704
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //<<>>

	vector<ll> p = {2 , 3 , 5 , 7 , 11 , 13};
	ll n; cin >> n;

	vector<ll> ans;
	FOR(i,1,5){
		ans.clear();
		ans.pb(1);

		FOR(j,0,i){
			ll size = sz(ans);
			FOR(k,0,size - 1){
				ll x = ans[k];
				while(x * p[j] <= 2 * n * n) x *= p[j] , ans.pb(x);
			}
		}

		if(sz(ans) >= n) break;
	}

	sort(ans.rbegin(),ans.rend());

	FOR(i,0,n - 1) cout << ans[i] << " ";
	cout << endl;

    return 0;
}
