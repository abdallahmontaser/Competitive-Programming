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
* Editorial: https://codeforces.com/blog/entry/11730
*/

ll ans[1<<20] , tmp[1<<20];
pair<pair<ll,ll>,ll> a[101];
ll n,m,b;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n >> m >> b;

    FOR(i,1,n){
        ll mi; cin >> a[i].F.S >> a[i].F.F >> mi;
        ll mask = 0;
        while(mi--){
            ll tmp; cin >> tmp;
            mask |= (1 << (tmp - 1));
        }
        a[i].S = mask;
    }
    sort(a+1,a+n+1);

    FOR(mask,0,(1<<m) - 1) ans[mask] = 2e18;
    ans[0] = 0;

    ll final_ans = 2e18;
    FOR(i,1,n){
        FOR(mask,0,(1<<m)-1) tmp[mask] = ans[mask];

        FOR(mask,0,(1<<m)-1) tmp[mask | a[i].S] = min(tmp[mask | a[i].S] , ans[mask] + a[i].F.S);

        FOR(mask,0,(1<<m)-1) ans[mask] = tmp[mask];
        if(ans[(1<<m) - 1] != 2e18) final_ans = min(final_ans , a[i].F.F * b + ans[(1<<m) - 1]);
    }

    if(final_ans == 2e18) cout << "-1\n";
    else cout << final_ans << endl;

    return 0;
}
