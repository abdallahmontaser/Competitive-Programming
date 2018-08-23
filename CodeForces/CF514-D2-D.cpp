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
* You can find the maximum length of a consecutive sequence of droids that can be destroyed using two pointers.Because if you can
* destroy all the droids in [i,j] then you can destroy the droids in [i+1,j].
* For a given interval of droids, the minimum number of shots to destroy them all can be computed using a multiset.
*/

ll sum(multiset<ll>*ms,ll m){
    ll s = 0; FOR(i,1,m) s -= *(ms[i].begin());
    return s;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n,m,k; cin >> n >> m >> k;
    ll t[n+1][m+1]; FOR(i,1,n) FOR(j,1,m) cin >> t[i][j];

    multiset<ll>ms[m+1];
    ll ans[m+1]; FOR(i,1,m) ans[i] =  0;
    ll best_len = 0;

    ll e = 1;
    FOR(i,1,n){
        e = max(e,i);
        FOR(j,1,m) ms[j].insert(-t[e][j]);

        if(sum(ms,m) <= k){
            while(e + 1 <= n){
                FOR(j,1,m) ms[j].insert(-t[e+1][j]);

                if(sum(ms,m) > k){
                    FOR(j,1,m) ms[j].erase(ms[j].find(-t[e+1][j]));
                    break;
                }

                ++e;
            }

            if(e - i + 1 > best_len) FOR(j,1,m) ans[j] = -*(ms[j].begin()) , best_len = e - i + 1;
        }

        FOR(j,1,m) ms[j].erase(ms[j].find(-t[i][j]));
    }

    FOR(j,1,m) cout << ans[j] << ((j == m) ? "\n" : " ");

    return 0;
}
