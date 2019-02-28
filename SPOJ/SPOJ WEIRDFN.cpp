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
* The problem is in finding the median in every step.
* The trick is to use 2 priority queues(using multisets will give TLE).
* 
* Maintain a min pq(lo) and a max pq(hi) and at each step these two propreties must remain true:
**      All the elements in "lo" are smaller than or equal to all the elements in "hi".
**      Let n1 = size(lo) and n2 = size(hi), either n1 = n2 or n1 = n2 + 1.
* The median will be lo.top() i.e. the biggest element in lo.
* So begin by inserting F[1] in lo, then from 2 to n, see if F[i] <= current_median, if so insert it in "lo" else in "hi".
* 
* In lines 53 and 52 I check at every i if the second proprety is still true or not.
* If n1 became equal to n2 + 2, remove one element from "lo"(the biggest) and put it in "hi".
* Or if n1 became equal to n2 - 1, remove one element from "hi"(the smallest) and put it in "lo".
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t; cin >> t;
	while(t--){
		ll a,b,c,n; cin >> a >> b >> c >> n;
		priority_queue<ll , vector<ll> , greater<ll>> hi;
		priority_queue<ll> lo;

		lo.push(1);
		ll ans = 1;
		FOR(i,2,n){
			ll med = lo.top(); 
			ll f = (a * med + b * i + c) % MOD;
			
			ans += f;

			if(f > med) hi.push(f);
			else lo.push(f);

			if(sz(lo) > sz(hi) + 1) hi.push(lo.top()) , lo.pop();
			if(sz(lo) < sz(hi)) lo.push(hi.top()) , hi.pop();
		}

		cout << ans << '\n';
	}

    return 0;
}
