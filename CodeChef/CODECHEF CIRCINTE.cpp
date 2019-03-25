#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
#define ll long long
using namespace std;

/**
* I found no editorial for this problem.
* Here I have an unproven solution.
* 
* First binary search on the answer(distance).
* It is known that if you fix the minimum distance and the starting point(for example in the first interval; [L0 ; R0])
* you can fix all the other points' optimal places in the other intervals in this case.
* 
*        ** UNPROVEN PART **
* For each distance 'd', to find out if it's possible to find a set of points with a minimum distance between them >= d
* it is enough to try three possibilities as a starting point with it; L0 , R0 , (L0 + R0) / 2
* If it's not possible with those three starting points, then the answer is in [1 ; d - 1] else it's in [d ; oo[
*/

int n;
ll m;
pair<ll,ll> a[400005];

bool f(ll first , ll d){
	ll prv = first;

	for(int i = 1; i < n; ++i){
		ll cur = max(a[i].F , prv + d);

		if(cur > a[i].S) return 0;

		prv = cur;
	}

	if(m + first - prv < d) return 0;

	return 1;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> m >> n;

	for(int i = 0; i < n; ++i) cin >> a[i].F >> a[i].S;

	ll best = 0;

	ll lo = 1 , hi = m;
	while(lo <= hi){
		ll mid = (lo + hi) >> 1;

		vector<ll> v = {a[0].F , (a[0].F + a[0].S) / 2 , a[0].S};

		bool valid = 0;
		for(ll x: v) valid |= f(x , mid);

		if(valid) best = mid , lo = mid + 1;
		else hi = mid - 1;
	}

	cout << best << '\n';

    return 0;
}
