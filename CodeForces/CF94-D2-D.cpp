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
const ll N = 200005;

using namespace std;

/**************************************************************************************************/

/**
* Editorial: http://codeforces.com/blog/entry/2208
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("grant.in","r",stdin);
    //freopen("grant.out","w",stdout);
    //<>

    ll n,w,m; cin >> n >> w >> m;

    ll cap[m + 1];
    vector<pair<ll,ll>>give[m + 1];
    FOR(i,1,m) cap[i] = ((w * n * m) * n) / m;

    FOR(i,1,n){
        ll total = w * n * m , nb = 0;
        FOR(j,1,m){
            if(nb == 2) continue;

            ll x = min(total , cap[j]);
            if(x == 0) continue;

            ++nb;
            total -= x;
            cap[j] -= x;
            give[j].pb(mp(i , x));
        }
    }

    FOR(i,1,m) if(cap[i] != 0){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    FOR(i,1,m){
        FOREACH(it,give[i]) cout << it->F << " " << fixed << setprecision(6) << (ld)it->S / (ld)(n * m) << " " ;
        cout << endl;
    }

    return 0;
}
