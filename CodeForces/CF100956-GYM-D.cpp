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
const ll N = 200005 , MOD = 1000000007;
using namespace std;

/**
* Here is the blog that I posted about this problem: https://codeforces.com/blog/entry/65472
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll n; cin >> n;
  
	pair<ll,ll> a[n + 1];
	FOR(i,1,n) cin >> a[i].F;
	FOR(i,1,n) cin >> a[i].S;
	
  sort(a + 1 , a + n + 1);
	reverse(a + 1 , a + n + 1);

	priority_queue<ll , vector<ll> , greater<ll> > q;
	FOR(i,1,n){
		q.push(a[i].S);
		if(i % 2 == 1) q.pop();
	}

	ll ans = 0;
	while(q.empty() == 0) ans += q.top() , q.pop();

	cout << ans << '\n';

    return 0;
}
