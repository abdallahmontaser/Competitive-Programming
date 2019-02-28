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
* If this triangle exists, then it's head can be (0,0).
* Find all combinations of points {A , B} such that the distance from A to the origin is a and the distance frm B to the origin is B.
* Check if the distance between A and B is the square root of a^2 + b^2.
* Also check that the first coordinates of the three points are different and the same for their second coordinates, that will guarantee that
* none of the triangle's sides are parallel to the coordinate axes.
* 
* Good trick in the editorial: https://codeforces.com/blog/entry/11333
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll a,b; cin >> a >> b;

	vector<pair<ll,ll>> va;
	FOR(x,-a,a){
		ll y = sqrt(a * a - x * x);

		if(x * x + y * y != a * a) continue;

		va.pb(mp(x , y));
	}

	vector<pair<ll,ll>> vb;
	FOR(x,-b,b){
		ll y = sqrt(b * b - x * x);

		if(x * x + y * y != b * b) continue;

		vb.pb(mp(x , y));
	}

	FOR(i,0,sz(va) - 1) FOR(j,0,sz(vb) - 1){
		if((va[i].F - vb[j].F) * (va[i].F - vb[j].F) + (va[i].S - vb[j].S) * (va[i].S - vb[j].S) != a * a + b * b) continue;
		if(va[i].F == 0 || vb[j].F == 0 || va[i].F == vb[j].F) continue;
		if(va[i].S == 0 || vb[j].S == 0 || va[i].S == vb[j].S) continue;

		cout << "YES\n";
		cout << "0 0\n";
		cout << va[i].F << " " << va[i].S << '\n';
		cout << vb[j].F << " " << vb[j].S << '\n';

		return 0;
	}

	cout << "NO\n";

    return 0;
}
