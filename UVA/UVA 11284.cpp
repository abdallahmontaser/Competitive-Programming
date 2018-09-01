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
* Used dp[i][mask] = maximum money one can save from store i to the house 0, given that the stores whose bit is 1 in mask are already
* visited.
*/

ll n,m;
ld d[51][51] , win[51];
map<ll,ll>dvd;
ld dp[51][1<<12];
ll done[51][1<<12];

ld solve(ll i,ll mask){
    if(done[i][mask] == 2) return dp[i][mask];
    if(done[i][mask] == 1) return -1e18;

    done[i][mask] = 1;
    ld &ans = dp[i][mask];
    ans = -d[i][0];

    FOR(j,1,n){
        ll x = dvd[j];
        if(x == 0 || (((1<<(x - 1)) & mask) != 0)) ans = max(ans , -d[i][j] + solve(j , mask));
        else ans = max(ans , -d[i][j] + max((ld)0,win[j]) + solve(j , mask | (1<<(x - 1))));
    }

    done[i][mask] = 2;
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll tc; cin >> tc;
    while(tc--){
        cin >> n >> m;

        FOR(i,0,n) FOR(j,0,n) d[i][j] = d[j][i] = 1e18;
        FOR(i,0,n) d[i][i] = 0;
        while(m--){
            ll x,y; ld c;
            cin >> x >> y >> c;
            d[x][y] = min(d[x][y] , c);
            d[y][x] = min(d[x][y] , c);
        }
        FOR(k,0,n) FOR(i,0,n) FOR(j,0,n) d[i][j] = min(d[i][j] , d[i][k] + d[k][j]);

        FOR(i,0,n) win[i] = 0;
        dvd.clear();
        ll nb = 0;
        ll p; cin >> p;
        while(p--){
            ll x; ld c;
            cin >> x >> c;
            if(dvd[x] == 0) dvd[x] = ++nb;
            win[x] += max((ld)0 , c);
        }

        memset(done,0,sizeof(done));
        ld ans = solve(0,0);
        if(ans + EPS < 0.01) cout << "Don't leave the house\n";
        else cout << "Daniel can save $" << fixed << setprecision(2) << ans << endl;
    }

    return 0;
}
