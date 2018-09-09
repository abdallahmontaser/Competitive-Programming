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
* Let ans[i] be the rank of the i_th soldier.These will be calculated from n to 1.
* ans[i] = i - walk[i] + x
* 
* Where x is the number of j ( > i) such that ans[j] <= y (using a binary indexed tree)
* 
* Where y is the smallest number such that i - walk[i] + number_of_j_( > i)_such_that_ans[j]_<=_y  <  y + 1
*/

void upd(ll *bit, ll n, ll x){
    while(x <= n) ++bit[x] , x += x & (-x);
}

ll sum(ll* bit, ll x){
    ll s = 0;
    while(x != 0) s += bit[x] , x -= x & (-x);
    return s;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll tc; cin >> tc;
    while(tc--){
        ll n; cin >> n;
        ll a[n + 1]; FOR(i,1,n) cin >> a[i];

        ll bit[n + 1]; FOR(i,1,n) bit[i] = 0;
        ll ans[n + 1];

        ROF(i,n,1){
            ll low = i - a[i] , high = n;
            while(low <= high){
                ll mid = (low + high) >> 1;

                if(mid == n || i - a[i] + sum(bit, mid) < mid + 1) ans[i] = i - a[i] + sum(bit, mid) , high = mid - 1;
                else low = mid + 1;
            }

            upd(bit , n, ans[i]);
        }

        FOR(i,1,n) cout << ans[i] << ((i == n) ? "\n" : " ");
    }

    return 0;
}
