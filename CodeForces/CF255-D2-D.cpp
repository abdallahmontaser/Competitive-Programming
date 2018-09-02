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
const ll N = 300005;

using namespace std;

/**************************************************************************************************/

/**
* Use binary search to find the smallest number of seconds s such that after s seconds, we will have c or more cells turned on.
* It works because, obviously, the more seconds you take the bigger turned on cells you'll have.
* 
* See the comments below to understand the two functions.
*/



// compute sum of all integers in [a , b]

ll sum(ll a,ll b){return (b >= a) ? (((b - a + 1) * (b + a)) / 2) : 0ll;}



// computing the sum of numbers from a to x then from b to x(without taking x twice) and taking in each time the minimum of the integer and mn.
// equivalent to this:

// long long res = 0;
// for(int i = a ; i <= x ; ++i) res += min(i , mn);
// for(int i = b ; i <= x ; ++i) res += min(i , mn);
// return res - min(x , mn);

ll f(ll a,ll x,ll b,ll mn){
    if(mn >= x) return sum(a , x) + sum(b , x) - x;

    if(mn >= max(a , b)) return ((2 * (x - mn + 1) - 1) * mn) + sum(a , mn - 1) + sum(b , mn - 1);
    if(mn <= min(a , b)) return ((x - a + 1) + (x - b + 1) - 1) * mn;

    if(mn < b) return sum(a , mn) + f(mn + 1 , x , b , mn);
    if(mn < a) return sum(b , mn) + f(a , x , mn + 1 , mn);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n,x,y,c; cin >> n >> x >> y >> c;

    ll i = 0 , j = 2e18;
    ll ans;
    while(i <= j){
        ll mid = (i + j) / 2;

        ll left = min(y - 1 , mid); // number of turned on cells in line x from column 1 to column y - 1
        ll right = min(n - y , mid); // number of turned on cells in line x from column y + 1 to column n

        ll top = f(mid - left , mid , mid - right , x - 1); // number of turned on cells in all columns from line 1 to line x - 1
        ll down = f(mid - left , mid , mid - right , n - x); // number of turned on cells in all columns from line x + 1 to line n

        if(top + down + left + right + 1 >= c) ans = mid , j = mid - 1;
        else i = mid + 1;
    }

    cout << ans << endl;

    return 0;
}
