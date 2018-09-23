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
* Idea: https://github.com/MeGaCrazy/CompetitiveProgramming/blob/478ef4641bab747e4fd63fffdff7d55287242921/PKU/PKU_2096.cpp
*/

ll n,s;
ld dp[1001][1001];

ld f(ld a, ld b){
    return a / b;
}

ld solve(ll cn,ll cs){
    if(cn == n && cs == s) return 0.0;

    ld &ans = dp[cn][cs];
    if(ans != -1) return ans;
    ans = 0.0;

    ld p1 = f(n - cn, n) * f(s - cs, s);
    if(cn == n || cs == s) p1 = 0.0;
    else ans += p1 * solve(cn + 1, cs + 1);

    ld p2 = f(cn, n) * f(s - cs, s);
    if(cn == 0 || cs == s) p2 = 0.0;
    else ans += p2 * solve(cn, cs + 1);

    ld p3 = f(n - cn, n) * f(cs, s);
    if(cn == n || cs == 0) p3 = 0.0;
    else ans += p3 * solve(cn + 1, cs);

    ans += 1.0;
    ans /= p1 + p2 + p3;

    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n >> s;

    FOR(i,0,1000) FOR(j,0,1000) dp[i][j] = -1;

    cout << fixed << setprecision(4) << solve(0, 0);

    return 0;
}
