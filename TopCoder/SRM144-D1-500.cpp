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
* Editorial(without dp): https://www.topcoder.com/tc?module=Static&d1=match_editorials&d2=srm144
*/

ll dp1[8][101];
ll solve1(ll i,ll p,ll x,ll n,ll uniq){
    if(i == n) return 1;

    if(dp1[i][p] != -1) return dp1[i][p];
    ll &ans = dp1[i][p];
    ans = 0;

    FOR(j,p+uniq,x) ans += solve1(i + 1 , j , x , n , uniq);

    return ans;
}

class Lottery{
    public: vector <string> sortByOdds(vector <string> rules){
        vector<pair<ll,string>>v;

        FOREACH(it,rules){
            ll ind;
            FOR(i,0,sz(*it) - 1) if((*it)[i] == ':') ind = i;

            string name((*it).begin(),(*it).begin() + ind);
            (*it).erase((*it).begin(),(*it).begin() + ind + 1);

            ll x,n; char sor , uniq;
            istringstream iss(*it);
            iss >> x >> n >> sor >> uniq;

            ll ans;

            if(sor == 'F' && uniq == 'F') ans = pow(x,n);
            if(sor == 'T' && uniq == 'F'){
                memset(dp1,-1,sizeof(dp1));
                ans = solve1(0,1,x,n,0);
            }
            if(sor == 'F' && uniq == 'T'){
                ans = 1;
                FOR(i,0,n-1) ans *= (x - i);
            }
            if(sor == 'T' && uniq == 'T'){
                memset(dp1,-1,sizeof(dp1));
                ans = solve1(0,0,x,n,1);
            }

            v.pb(mp(ans , name));
        }
        
        sort(v.begin() , v.end());
        
        vector<string> v2;
        FOREACH(it,v) v2.pb(it->S);
        
        return v2;
    };
};
