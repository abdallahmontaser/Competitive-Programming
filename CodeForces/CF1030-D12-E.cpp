#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <iterator>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#include <limits>
#include <math.h>
#include <stdio.h>
#include <string.h>

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
const ll N = 100005;

using namespace std;

/**************************************************************************************************/

/**
* Editorial: http://codeforces.com/blog/entry/62013
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("grant.in","r",stdin);
    //freopen("grant.out","w",stdout);
    //<>

    ll n; cin >> n;
    ll a[n + 1] , aa[n + 1]; a[0] = 0;
    FOR(i,1,n){
        ll x; cin >> x;
        aa[i] = __builtin_popcountll(x);
        a[i] = aa[i] + a[i - 1];
    }

    ll ans = 0;
    ll even = 1 , odd = 0;
    FOR(i,1,n){
        if(a[i] % 2 == 0) ans += even , ++even;
        else ans += odd , ++odd;
    }

    FOR(i,1,n){
        ll mx = 0;
        ll sum = 0;
        ROF(j,i,max(1ll , i - 70)){
            mx = max(mx , aa[j]);
            sum += aa[j];

            if((a[i] % 2) == (a[j - 1] % 2) && mx > sum - mx) --ans;
        }
    }

    cout << ans << endl;

    return 0;
}
