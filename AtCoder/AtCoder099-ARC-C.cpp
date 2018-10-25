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
const ll N = 100005;

using namespace std;

/**************************************************************************************************/

/**
* Editorial: https://img.atcoder.jp/arc099/editorial.pdf
* 
* Comments below.
*/

ll n , m;
vector<ll> g[705];
ll e[705][705];
ll c[705];
vector<pair<ll,ll>> comp;
ll one , two;
ll dp[705][705];

ll solve(ll i , ll nb){
    if(i == sz(comp)) return (nb * (nb - 1)) / 2 + ((n - nb) * (n - nb - 1)) / 2;

    ll &ans = dp[i][nb];
    if(ans != -1) return ans;

    return ans = min(solve(i + 1 , nb + comp[i].F) , solve(i + 1 , nb + comp[i].S));
}

void dfs(ll x,ll color){
    c[x] = color;

    if(color == 1) ++one;
    else ++two;

    FOREACH(y , g[x]) if(c[*y] == 0) dfs(*y , 3 - color);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("grant.in","r",stdin);
    //freopen("grant.out","w",stdout);
    //<>

    cin >> n >> m;
    vector<pair<ll,ll>>v;
    FOR(i,1,m){
        ll a,b; cin >> a >> b;
        e[a][b] = e[b][a] = 1;
        v.pb(mp(a , b));
    }
  
    // constructing the complement graph
    FOR(i,1,n) FOR(j,1,n) if(i != j && e[i][j] == 0) g[i].pb(j) , g[j].pb(i);
    
    // supposing the graph is bipartite and finding the unique coloring for each component of the graph
    FOR(i,1,n) if(c[i] == 0){
        one = 0 , two = 0; // see the dfs function to understand
        dfs(i , 1);

        comp.pb(mp(one , two));
    }
    
    // if the graph isn't bipartite there's no answer
    FOR(i,1,n) FOREACH(j , g[i]) if(c[i] == c[*j]){
        cout << "-1\n";
        return 0;
    }
    
    // else we have the coloring division for each component, so we use dp to find the best way to divide the total n nodes
    // in two such that for each component, we choose which number of group(each component is divided into two groups which are the 'one' and 'two' variables above)
    // to add to which component IN ORDER TO minimize(let k be the total number of nodes colored the same color and n-k will be the number of the other color of course)
    // k * (k - 1) / 2   +   (n - k) * (n - k - 1) / 2
    // see the dp function to understand
    memset(dp , -1 , sizeof(dp));
    cout << solve(0 , 0) << endl;

    return 0;
}
