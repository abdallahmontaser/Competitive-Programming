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
* Using a segment tree find out for every element the nearest element on the left that is smaller than it and do the same on the right.
* 
* O(N) solution using stack: https://github.com/guluuu3/spoj/blob/master/histogram.cpp
*/

map<ll,ll> id;
ll seg[N] , L[N] , R[N];
ll n , nn;

void upd_1(ll i,ll val){
    i += nn - 1;
    seg[i] = val;
    while(i != 1) i /= 2 , seg[i] = max(seg[i * 2] , seg[i * 2 + 1]);
}

ll que_1(ll l,ll r,ll i = 1,ll start = 1,ll en = nn){
    if(start > r || en < l || l > r) return 0;
    if(l <= start && en <= r) return seg[i];

    ll mid = (start + en) / 2;
    return max(que_1(l,r,i << 1,start,mid) , que_1(l,r,i << 1 | 1,mid+1,en));
}

void upd_2(ll i,ll val){
    i += nn - 1;
    seg[i] = val;
    while(i != 1) i >>= 1 , seg[i] = min(seg[i << 1] , seg[(i << 1) | 1]);
}

ll que_2(ll l,ll r,ll i = 1,ll start = 1,ll en = nn){
    if(start > r || en < l || l > r) return n + 1;
    if(l <= start && en <= r) return seg[i];

    ll mid = (start + en) / 2;
    return min(que_2(l,r,i << 1,start,mid) , que_2(l,r,i << 1 | 1,mid+1,en));
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while(cin >> n && n != 0){
        id.clear();

        set<ll>s;
        ll t[n+1];
        FOR(i,1,n) cin >> t[i] , s.insert(t[i]);
        nn = pow(2,ceil(log2(sz(s))));

        ll tmp = 0;
        FOREACH(it,s) id[*it] = ++tmp;

        FOR(i,1,N-1) seg[i] = 0;
        FOR(i,1,n) L[i] = que_1(1,id[t[i]]-1) , upd_1(id[t[i]],i);

        FOR(i,1,N-1) seg[i] = n + 1;
        ROF(i,n,1) R[i] = que_2(1,id[t[i]]-1) , upd_2(id[t[i]],i);

        ll ans = 0;
        FOR(i,1,n) ans = max(ans , (R[i] - L[i] - 1) * t[i]);

        cout << ans << endl;
    }

    return 0;
}
