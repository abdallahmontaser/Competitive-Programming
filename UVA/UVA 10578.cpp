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
* dp with bitmasks
*/

ll dp[15700];
ll pow5[6];

ll solve(ll mask,ll sum){
    if(sum > 31) return 1;

    ll &ans = dp[mask];
    if(ans != -1) return ans;

    ll t[6];
    ROF(i,5,0){
        ll x = mask / pow5[i];
        t[i] = x;
        mask -= x * pow5[i];
    }

    FOR(i,0,5) if(t[i] >= 1 && sum + i + 1 <= 31){
        bool win = 1;

        FOR(j,0,5) if((j != i && t[j] >= 1) || (i == j && t[j] >= 2)){
            ll t_mask = 0;
            FOR(k,0,5){
                ll x = t[k] - (k == i) - (k == j);
                t_mask += x * pow5[k];
            }

            if(solve(t_mask, sum + i + 1 + j + 1) == 0) win = 0 , j = 6;
        }

        if(win == 1) return ans = 1;
    }

    return ans = 0;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    pow5[0] = 1;
    FOR(i,1,5) pow5[i] = 5 * pow5[i - 1];

     string s;
     while(cin >> s){
        ll sum = 0;
        ll t[6]; FOR(i,0,5) t[i] = 4;
        FOR(i,0,sz(s) - 1){
            sum += s[i] - '0';
            --t[s[i] - '1'];
        }

        ll mask = 0;
        FOR(i,0,5) mask += t[i] * pow5[i];

        memset(dp,-1,sizeof(dp));

        cout << s << " ";
        if(sz(s) & 1){
            if(solve(mask,sum) == 1) cout << "B\n";
            else cout << "A\n";
        }
        else{
            if(solve(mask,sum) == 1) cout << "A\n";
            else cout << "B\n";
        }
     }

    return 0;
}
