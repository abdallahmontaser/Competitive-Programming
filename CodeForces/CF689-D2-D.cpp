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
const ll N = 200005;

using namespace std;

/**************************************************************************************************/

/**
* Editorial: http://codeforces.com/blog/entry/45912
*/

ll n;
ll a[N][18] , b[N][18];

ll rmq1(ll i,ll j){
    ll len = floor(log2(j - i + 1));
    return max(a[i][len], a[j - (1 << len) + 1][len]);
}

ll rmq2(ll i,ll j){
    ll len = floor(log2(j - i + 1));
    return min(b[i][len], b[j - (1 << len) + 1][len]);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("grant.in","r",stdin);
    //freopen("grant.out","w",stdout);

    cin >> n;
    FOR(i,1,n) cin >> a[i][0];
    FOR(i,1,n) cin >> b[i][0];

    FOR(j,1,17) FOR(i,1,n) if(i + (1 << j) - 1 <= n){
        a[i][j] = max(a[i][j - 1] , a[i + (1 << (j - 1))][j - 1]);
        b[i][j] = min(b[i][j - 1] , b[i + (1 << (j - 1))][j - 1]);
    }

    ll ans = 0;
    FOR(i,1,n){
        ll l = 0;
        ll low = i , high = n;
        while(low <= high){
            ll mid = (low + high) >> 1;
            ll x = rmq1(i, mid) - rmq2(i, mid);

            if(x == 0) l = mid;

            if(x >= 0) high = mid - 1;
            else low = mid + 1;
        }

        ll r = -1;
        low = i , high = n;
        while(low <= high){
            ll mid = (low + high) >> 1;
            ll x = rmq1(i, mid) - rmq2(i, mid);

            if(x == 0) r = mid;

            if(x > 0) high = mid - 1;
            else low = mid + 1;
        }

        ans += r - l + 1;
    }

    cout << ans << endl;

    return 0;
}
