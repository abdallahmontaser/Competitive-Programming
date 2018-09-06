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
#define dump(a) DUMP_NAME(#a, (a))

#define FOREACH(it,x) for(__typeof__((x).begin()) it = (x).begin();it!=(x).end();++it)
#define FOR(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);++i)
#define ROF(i,a,b) for(ll i=(ll)(a);i>=(ll)(b);--i)

const ld PI = 3.141592653589793238L;
const ll N = 2000005;

using namespace std;

/**************************************************************************************************/

/**
* Well explained editorial: https://codeforces.com/blog/entry/12369
*/

ll C[63][63];

ll Cnk(ll n , ll k){
    if(k < 0 || k > n) return 0;
    return C[n][k];
}

ll f(ll x , ll k){
    ll ans = 0;
    ll nb = 0;

    ROF(i,62,0) if(x & (1ll << i)){
        ans += Cnk(i , k - nb);
        ++nb;
    }

    return ans + (__builtin_popcountll(x) == k);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    FOR(n,0,62){
        C[n][0] = 1;
        FOR(k,1,n) C[n][k] = Cnk(n - 1 , k) + Cnk(n - 1 , k - 1);
    }

    ll m,k; cin >> m >> k;

    ll i = 1 , j = 2e18;
    while(i <= j){
        ll mid = (i + j) >> 1;
        
        ll x = f(mid << 1 , k) - f(mid , k);

        if(x > m) j = mid - 1;
        else if(x < m) i = mid + 1;
        else{
            cout << mid << endl;
            return 0;
        }
    }

    return 0;
}
