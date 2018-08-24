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
* Solve using dynamic programming - dp[w][b][t] is the probability for the princess(if t=0 else it's the dragon) to win with w white mice
* and b black mice.
* 
* Editorial: https://codeforces.com/blog/entry/3819
*/

ld dp[1001][1001][2];

ld solve(ll w,ll b,ll turn){
    if(b <= 0){
        if(turn == 0 && w != 0) return 1;
        else if(turn == 0) return 0;
        return 1;
    }
    if(w == 0) return turn;

    ld&ans = dp[w][b][turn];
    if(ans != -1) return ans;

    ld p = w / (ld)(w + b);

    ld p1 = w / (ld)(w + b - 1);
    ld p2 = (b - 1) / (ld)(w + b - 1);

    if(turn == 0) ans = p + (1.0 - p) * (1.0 - solve(w,b-1,1));
    if(turn == 1) ans = p + (1.0 - p) * (p1 * (1.0 - solve(w-1,b-1,0)) + p2 * (1.0 - solve(w,b-2,0)));

    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll w,b; cin >> w >> b;

    FOR(i,0,1000) FOR(j,0,1000) dp[i][j][0] = dp[i][j][1] = -1;

    cout << fixed << setprecision(9) << solve(w,b,0) << endl;

    return 0;
}

