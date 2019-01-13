#include <bits/stdc++.h>

#define MOD 1000000007
#define EPS ((long double)1e-12)
#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
#define sz(x) ((long long)(x).size())
#define endl '\n'

#define DUMP_NAME(name,a) cout << "#dump " << (name) << " = " << (a) << "  "
#define dump(a) DUMP_NAME(#a, (a));

#define FOREACH(it,x) for(__typeof__((x).begin()) it = (x).begin();it!=(x).end();++it)
#define FOR(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);++i)
#define ROF(i,a,b) for(ll i=(ll)(a);i>=(ll)(b);--i)

const ld PI = 3.141592653589793238L;
const ll N = 300005;

using namespace std;

/**
* First thing to notice is that "the average commute time in the subway is calculated as the sum of pairwise
* distances between stations, divided by the number of pairs (that is n(n-1)/2) and divided by the speed of the train" just means
* that we need to minimize the pairwise distances in the K stations we'll choose; since all of the possible K stations will be
* divided by the constant train speed and by k*(k-1)/2.
* 
* Next we can prove that the best station to remove at each step will be either the one at the left or the right of the Ox axis.
* That means the best K stations will be a contiguous subarray in the (sorted)first array.So we'll just try all the possible K-subarrays and
* take the one with the minimum sum of pairwise distances value.
* 
* t[i] represents the sum of pairwise distances between all the stations [1..i], and s[i] is the prefix sum of their distances(to the origin).

/**************************************************************************************************/

ll t[N] , s[N];

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	#endif
	//<<>>

   	ll n; cin >> n;
   	pair<ll,ll> a[n + 1]; FOR(i,1,n) cin >> a[i].F , a[i].S = i;
   	ll k; cin >> k;
   	sort(a + 1, a + n + 1); 

   	FOR(i,1,n) t[i] = t[i - 1] + a[i].F * (i - 1) - s[i - 1] , s[i] = s[i - 1] + a[i].F;

   	ll ans , best;
   	FOR(i,1,n - k + 1){
   		ll t_ans = t[i + k - 1] - t[i - 1];
   		t_ans -= (s[i + k - 1] - s[i - 1]) * (i - 1) - s[i - 1] * k;

   		if(i == 1 || t_ans < ans) ans = t_ans , best = i;
   	}

   	FOR(i,best,best + k - 1) cout << a[i].S << " ";

	return 0;
}
