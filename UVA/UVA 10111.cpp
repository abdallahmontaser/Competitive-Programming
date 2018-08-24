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
* We'll use dp + bitmsks(in base 3).
* Code is commented.
*/

pair<ll,ll> ans;
bool dp[44000000] , done[44000000];
ll p[17];

ll check(char c[4][4]){
    bool lose = 0;
    FOR(i,0,3) if(c[i][0] == c[i][1] && c[i][1] == c[i][2] && c[i][2] == c[i][3] && c[i][0] != '.'){ // rows
        if(c[i][0] == 'o') lose = 1; else return 1;
    }

    FOR(j,0,3) if(c[0][j] == c[1][j] && c[1][j] == c[2][j] && c[2][j] == c[3][j] && c[0][j] != '.'){ // columns
        if(c[0][j] == 'o') lose = 1; else return 1;
    }

    if(c[0][0] == c[1][1] && c[1][1] == c[2][2] && c[2][2] == c[3][3] && c[0][0] != '.'){ // first diagonal
        if(c[0][0] == 'o') lose = 1; else return 1;
    }

    if(c[0][3] == c[1][2] && c[1][2] == c[2][1] && c[2][1] == c[3][0] && c[0][3] != '.'){ // second diagonal
        if(c[0][3] == 'o') lose = 1; else return 1;
    }

    if(lose == 1) return 0;

    return -1;
}

bool f(char c[4][4]){
    ll val = 0; // calculating the mask of the current matrix
    FOR(i,0,3) FOR(j,0,3) if(c[i][j] != '.'){
        val += p[i * 4 + j];
        if(c[i][j] == 'x') val += p[i * 4 + j];
    }
    
    if(done[val]) return dp[val]; // if we already computed the answer for it, return

    ll x = check(c);
    if(x != -1){ // see if there's a winner already
        done[val] = 1;
        return dp[val] = x;
    }

    vector<pair<ll,ll>>v;
    FOR(i,0,3) FOR(j,0,3) if(c[i][j] == '.') v.pb(mp(i,j));
    // if the matrix is full and it's a draw, the vector will be empty(we won't enter the loop) and we'll later return 0

    FOR(ind,0,sz(v)-1){
        bool win = 1;
        
        FOR(ind2,0,sz(v)-1) if(ind2 != ind){
            char tmp[4][4];
            FOR(iii,0,3) FOR(jjj,0,3) tmp[iii][jjj] = c[iii][jjj];
            
            // we will choose a cell (v[ind] in this case) and see if it's a forced win
            // to do that, we need to check that whatever other empty cell O chooses (v[ind2]s) , X will win.
            
            tmp[v[ind].F][v[ind].S] = 'x';
            tmp[v[ind2].F][v[ind2].S] = 'o';

            if(f(tmp) == 0) win = 0; // we CAN lose if we choose v[ind]
        }

        if(win){ // there's no way we can lose if we choose v[ind], so it's the first cell that is a forced win
            ans = v[ind];
            done[val] = 1;
            return dp[val] = 1;
        }
    }
    
    // either it's a draw or no cell is a forced win
    done[val] = 1;
    return dp[val] = 0;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    *p = 1;
    FOR(i,1,16) p[i] = 3 * p[i - 1];

    char t;
    while(cin >> t && t != '$'){
        char c[4][4];
        FOR(i,0,3) FOR(j,0,3) cin >> c[i][j];

        if(f(c)) cout << "(" << ans.F << "," << ans.S << ")\n";
        else cout << "#####\n";
    }

    return 0;
}

