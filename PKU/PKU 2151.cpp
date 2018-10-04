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
const ll N = 500005;

using namespace std;

/**************************************************************************************************/

/**
* The answer is the probability that all the teams solve 1 problem or more - the probability that all the teams solve between [1..n-1] problems
* We need to use dp to calculate the probability that a team i solves j problems, which is solve(i,j,1).
*/

ll m,t,n;
ld p[1001][31] , dp[1001][31][31];

ld solve(ll i,ll j,ll k){
    if(k == m + 1) return 1.0 * (j == 0);

    ld &ans = dp[i][j][k];
    if(ans != (ld)-1) return ans;

    return ans = p[i][k] * solve(i,j - 1,k + 1) + (1.0 - p[i][k]) * solve(i,j,k + 1);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("grant.in","r",stdin);
    //freopen("grant.out","w",stdout);

    while(cin >> m >> t >> n && m != 0){
        FOR(i,1,t) FOR(j,1,m) cin >> p[i][j];

        FOR(i,0,1000) FOR(j,0,30) FOR(k,0,30) dp[i][j][k] = (ld)-1;

        ld ans1 = 1.0;
        FOR(i,1,t) ans1 *= 1.0 - solve(i,0,1);

        ld ans2 = 1.0;
        FOR(i,1,t){
            ld sum = 0;
            FOR(j,1,n - 1) sum += solve(i,j,1);
            ans2 *= sum;
        }

        cout << fixed << setprecision(3) << ans1 - ans2 << endl;
    }


    return 0;
}
