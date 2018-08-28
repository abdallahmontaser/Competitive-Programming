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
* Well explained editorial: http://apps.topcoder.com/wiki/display/tc/SRM+514
*/

ll dp[10][10][1<<10][2];
ll vis[51][51];
ll pow_4[2501] , pow_5[2501];
ll f[10][10][2];
ll even , odd , nb;
ll h,w;
ll n,m;

void dfs(ll i,ll j,vector<string> &p){
    ++nb;
    if(p[i][j] != '.'){
        ll x = p[i][j] - '0';
        if(x & 1) ++odd;
        else ++even;
    }

    if(i + n <= h - 1 && vis[i + n][j] == 0) vis[i + n][j] = 1 , dfs(i+n,j,p);
    if(j + m <= w - 1 && vis[i][j + m] == 0) vis[i][j + m] = 1 , dfs(i,j+m,p);
}

ll solve(ll i,ll j,ll mask,ll c){
    if(i == n) return mask == (1 << m) - 1;
    if(j == m) return (c == 1) * solve(i+1,0,mask,0);

    ll &ans = dp[i][j][mask][c];
    if(ans != -1) return ans;

    ans = (f[i][j][0] * solve(i,j+1,mask,c)) % MOD;
    ans = (ans + f[i][j][1] * solve(i,j+1,mask^(1<<j),c^1)) % MOD;

    return ans;
}

class MagicalGirlLevelTwoDivOne{
    public: int theCount(vector <string> palette, int nnn, int mmm){
        pow_4[0] = 1; FOR(i,1,2500) pow_4[i] = (4 * pow_4[i - 1]) % MOD;
        pow_5[0] = 1; FOR(i,1,2500) pow_5[i] = (5 * pow_5[i - 1]) % MOD;

        h = sz(palette) , w = sz(palette[0]);
        n = nnn , m = mmm;

        FOR(i,0,n-1) FOR(j,0,m-1){
            even = odd = nb = 0;
            vis[i][j] = 1;
            dfs(i,j,palette);

            f[i][j][0] = (odd == 0) * pow_4[nb - even];
            f[i][j][1] = (even == 0) * pow_5[nb - odd];
        }

        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,0);
    };
};
