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
const ll N = 1000005;

using namespace std;

/**************************************************************************************************/

/**
* Same exact solution in the editorial: https://codeforces.com/blog/entry/1088
*/

ll n;
ld p[1001];
ld dp[1001][1001];

ld solve(ll i , ll nb){
    if(i == n + 1) return 1.0 * (nb == 0);
    if(nb == -1) return 0.0;

    ld &ans = dp[i][nb];
    if(ans != -1) return ans;

    return ans = (1.0 - p[i]) * solve(i + 1 , nb) + p[i] * solve(i + 1 , nb - 1);
}

ll f(ll l , ll r){
    if(l == 1e18) return 1;
    if(r == 1e18) return 1 + f(l , r - 1);

    ll ans = 0;
    while(1){
        ostringstream oss; oss << l;
        string s = oss.str();

        if(s[0] != '1'){
            s[0] = '1';
            FOR(i,1,sz(s) - 1) s[i] = '0';
            s += "0";

            istringstream iss(s);
            iss >> l;
            if(l > r) break;
        }
        else{
            FOR(i,1,sz(s) - 1) s[i] = '9';
            istringstream iss(s);
            ll x; iss >> x;

            if(x > r){
                ans += r - l + 1;
                break;
            }
            else{
                ans += x - l + 1;
                l = x + 1;
            }
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n;
    FOR(i,1,n){
        ll l,r; cin >> l >> r;
        ld a = f(l , r) , b = r - l + 1;
        p[i] = a / (ld)b;
    }

    ll k; cin >> k;
    k = (k * n + 99) / 100;
    // k will be equal to ceil(k * n / 100) so now the answer is the sum of the probabilities of having exactly k <= nb <= n 1s.

    FOR(i,0,1000) FOR(j,0,1000) dp[i][j] = -1;

    ld ans = 0;
    FOR(nb,k,n) ans += solve(1 , nb);

    cout << fixed << setprecision(9) << ans << endl;

    return 0;
}
