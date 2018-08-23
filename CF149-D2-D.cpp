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
* Much better and shorter solution:
*     https://github.com/osamahatem/CompetitiveProgramming/blob/master/Codeforces/149D.%20Coloring%20Brackets.cpp
* 
* Editorial: https://codeforces.com/blog/entry/3864
*/

ll c[701];
ll dp[701][701][3][3];
bool match[3][3] , neighb[3][3];
vector<pair<ll,ll>> d1[3][3];
vector<pair<pair<ll,ll>,pair<ll,ll>>> d2[3][3] , d3[3][3];

ll solve(ll i,ll j,ll t1,ll t2){
    if(j == i + 1) return match[t1][t2];

    ll&ans = dp[i][j][t1][t2];
    if(ans != -1) return ans;
    ans = 0;

    if(c[i] == j && !match[t1][t2]) return ans;

    if(c[i] == j && c[i+1] == j - 1) FOR(ind,0,sz(d1[t1][t2])-1){
        auto x = d1[t1][t2][ind];
        ans = (ans + solve(i+1,j-1,x.F,x.S)) % MOD;
    }

    else if(c[i] == j) FOR(ind,0,sz(d2[t1][t2])-1){
        auto x = d2[t1][t2][ind].F;
        auto y = d2[t1][t2][ind].S;
        ans = (ans + solve(i+1,c[i+1],x.F,x.S) * solve(c[i+1]+1,j-1,y.F,y.S)) % MOD;
    }

    else FOR(ind,0,sz(d3[t1][t2])-1){
        auto x = d3[t1][t2][ind].F;
        auto y = d3[t1][t2][ind].S;
        ans = (ans + solve(i,c[i],x.F,x.S) * solve(c[i]+1,j,y.F,y.S)) % MOD;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string s; cin >> s;

    stack<ll>st;
    FOR(i,0,sz(s)-1){
        if(s[i] == '(') st.push(i);
        else c[st.top()] = i , st.pop();
    }

    match[0][1] = match[0][2] = match[1][0] = match[2][0] = 1;
    memset(neighb,1,sizeof(neighb));
    neighb[1][1] = neighb[2][2] = 0;

    FOR(a,0,2) FOR(b,0,2){
        FOR(c,0,2) FOR(d,0,2)
            if(match[a][b] && match[c][d] && neighb[a][c] && neighb[d][b]) d1[a][b].pb(mp(c,d));

        FOR(c,0,2) FOR(d,0,2) FOR(e,0,2) FOR(f,0,2)
            if(match[a][b] && match[c][d])
                if(neighb[a][c] && neighb[d][e] && neighb[f][b]) d2[a][b].pb(mp(mp(c,d),mp(e,f)));

        FOR(c,0,2) FOR(d,0,2)
            if(match[a][c] && neighb[c][d]) d3[a][b].pb(mp(mp(a,c),mp(d,b)));
    }

    memset(dp,-1,sizeof(dp));
    ll ans = 0;
    FOR(i,0,2) FOR(j,0,2) ans = (ans + solve(0,sz(s)-1,i,j)) % MOD;
    cout << ans << endl;

    return 0;
}
