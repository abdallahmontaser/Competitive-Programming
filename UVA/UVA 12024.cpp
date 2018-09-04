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
* Let solve(n) = the number of ways to arrange the hats such that no hat is given to it's rightful owner.
* Obviously the total number of ways to distribute hats is factorial(n).
* So the answer will be:  factorial(n) - (number of ways to arrange the hats to have at least one hat given to it's rightful owner)
* The "at least one" part - we will be going through all possible number of guys that can have their own hats from 1 to n.
* 
* If this "i" number is equal to n or n - 1, the answer is 1(the same i.e. we only count it once)
* otherwise it will be (iCn * solve(n - i)).
* 
* Read this for exact math formula: http://www.mathpages.com/home/kmath430.htm
*/

ll fact[13];
ll dp[13];

ll solve(ll n){
    if(dp[n] != 0) return dp[n];
    if(n == 2) return dp[n] = 1;

    ll ans = 1;
    FOR(i,1,n - 2) ans += ((fact[n] / fact[i]) / fact[n - i]) * solve(n - i);

    return dp[n] = fact[n] - ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    fact[0] = 1; FOR(i,1,12) fact[i] = i * fact[i - 1];
    FOR(i,2,12) solve(i);

    ll tc; cin >> tc;
    while(tc--){
        ll n; cin >> n;
        cout << dp[n] << "/" << fact[n] << endl;
    }

    return 0;
}
