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
* Used segment tree.
* Where each interval stores how many numbers are currently present under it(in the sorted version of the array that contains all the elements)
* Then to remove a number just perform a point update; start from it's index in the sorted array(used the "ind" map to compute it) and 
* go up while decreasing each value on every interval by 1.
* 
* Then to find the i_th integer, we binary search to find the smallest index j such that sum(1,j) == i.
*/

ll n,m;
pair<ll,ll> tmp[30001];
ll a[30001] , b[30001];
ll nn;
ll seg[N];

void upd(ll i){
    i += nn - 1;
    while(i >= 1){
        --seg[i];
        i >>= 1;
    }
}

ll que(ll l,ll r,ll i = 1,ll st = 1,ll en = nn){
    if(l > en || r < st) return 0;

    if(l <= st && en <= r) return seg[i];

    ll mid = (st + en) >> 1;
    return que(l , r , i << 1 , st , mid) + que(l , r , i << 1 | 1 , mid + 1 , en);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("grant.in","r",stdin);
    //freopen("grant.out","w",stdout);

    ll tc; cin >> tc;
    while(tc--){
        cin >> n >> m;
        FOR(i,1,n) cin >> a[i] , tmp[i].F = a[i] , tmp[i].S = i;
        FOR(i,1,m) cin >> b[i];

        sort(tmp + 1, tmp + n + 1);
        map<ll,ll>ind;
        FOR(i,1,n) ind[tmp[i].S] = i;

        nn = 1 << (ll)ceil(log2(n));
        FOR(i,nn,nn + n - 1) seg[i] = 1;
        FOR(i,nn + n, nn + nn - 1) seg[i] = 0;
        ROF(i,nn - 1,1) seg[i] = seg[i << 1] + seg[i << 1 | 1];

        ll curr_n = n;
        vector<ll>v;
        ROF(i,m,1){
            while(curr_n > b[i]) upd(ind[curr_n]) , --curr_n;

            ll low = 1 , high = n;
            ll ans;
            while(low <= high){
                ll mid = (low + high) >> 1;

                if(que(1,mid) >= i) ans = tmp[mid].F , high = mid - 1;
                else low = mid + 1;
            }

            v.pb(ans);
        }

        ROF(i,sz(v) - 1,0) cout << v[i] << endl;

        if(tc != 0) cout << endl;
    }

    return 0;
}
