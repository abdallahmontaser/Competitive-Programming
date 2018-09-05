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
* The answer will never be -1.It's always possible for Valera to win.
* So just pick any i such that the current value at the i_th counter is equal to a[i] and increment it and it's neighbours.
* Keep doing so until there's no such i.
* To find i, I used a segment tree.Where each node is a boolean representing whether or not there's an i in that interval such that a[i] = current_value[i]
* 
* The editorial: https://codeforces.com/blog/entry/5837 describes a linear solution(instead of segment tree) along with a not-well explained
* proof of this greedy approach.
*/

ll nn;
ll curr[N] , a[N];
bool seg[N] , done[N];
vector<ll> g[N];

ll que(){
    ll i = 1;
    while(i <= nn - 1){
        if(seg[i << 1] == 1) i <<= 1;
        else i <<= 1 , i |= 1;
    }

    return i - (nn - 1);
}

void upd(ll i){
    bool go_up = 0;
    if((curr[i] + 1 == a[i] && !done[i]) || curr[i] == a[i]) go_up = 1;

    ++curr[i];
    if(go_up){
        seg[i + nn - 1] = (curr[i] == a[i]);
        i += nn - 1;
        while(i > 1) i >>= 1 , seg[i] = seg[i << 1] | seg[i << 1 | 1];
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n,m; cin >> n >> m;

    while(m--){
        ll x,y; cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    nn = pow(2 , ceil(log2(n)));
    FOR(i,1,n) cin >> a[i];
    FOR(i,n+1,nn) a[i] = -1;

    FOR(i,1,nn) seg[i + nn - 1] = (a[i] == curr[i]);
    ROF(i,nn-1,1) seg[i] = seg[i << 1] | seg[i << 1 | 1];

    vector<ll> v;
    while(seg[1] != 0){
        ll x = que();
        done[x] = 1;
        v.pb(x);

        upd(x);
        FOREACH(it,g[x]) upd(*it);
    }

    cout << sz(v) << endl;
    FOREACH(it,v) cout << *it << " ";
    cout << endl;

    return 0;
}
