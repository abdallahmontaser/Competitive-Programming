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
const ll N = 500005;

using namespace std;

/**************************************************************************************************/

/**
* solve(a,b,c) = probability of survival of "a" if "a" beats "b" and "b" beats "c".
* Let the probability of having the next two individuals that meet, of types "a" and "c" be x, of types "a" and "b" be y and of types
* "b" and "c" be z(described below).
* 
* That way we can calculate the answer for these three cases, and we'll have: ans = x * .. + y * .. + z * .. + (1 - x - y - z) * ..
* such that the last term will be the same as ans(same state i.e. same "a", "b" and "c")  the formula will become:
* ans = (x * .. + y * .. + z * .. ) / (x + y + z)
* 
* Editorial: https://codeforces.com/blog/entry/17643
*/

ld dp[101][101][101];

ld solve(ll a,ll b,ll c){
    if(a == 0) return 0.0;
    if(b == 0 && c == 0) return 1.0;

    ld &ans = dp[a][b][c];
    if(ans != -1) return ans;

    ld denom = (a + b + c) * (a + b + c - 1);
    ld x = (2 * a * c) / denom;
    ld y = (2 * a * b) / denom;
    ld z = (2 * b * c) / denom;

    ans = 0;
    if(a != 0 && c != 0) ans += x * solve(a-1,b,c);
    if(a != 0 && b != 0) ans += y * solve(a,b-1,c);
    if(b != 0 && c != 0) ans += z * solve(a,b,c-1);

    ans /= (x + y + z);

    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll r,s,p; cin >> r >> s >> p;

    FOR(i,0,100) FOR(j,0,100) FOR(k,0,100) dp[i][j][k] = -1;

    cout << fixed << setprecision(9) << solve(r,s,p) << " " << solve(s,p,r) << " " << solve(p,r,s) << endl;

    return 0;
}
