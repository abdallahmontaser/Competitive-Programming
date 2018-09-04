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
* Let's count for an integer x, the maximal number of times we can replae it with it's square root rounded to the nearest integer before
* it becomes 1 i.e. it's no longer needed to apply the modification on it.
* I have no exact formula, but I believe the worst case is when it's a power of two.That is, there exists an n >= 0 such that x = 2^n
*
* The answer for x will obviously be O(log(log(x))).And because all integers in the problem are < 1e18, that number will be < 6.
*
* So, using a segment tree, we store for every interval, the sum and the value of the maximum element in it.
* When the operation is a modification, we keep going down and ignore every interval that has a maximum value of 1 in it(because it will be
* useless to enter it) and go through all others to the bottom, modify the leaves then go back up and update the parents' sum and max.
*
* That way, we guarantee that every element of the array gets touched(squared down) by the segment tree directly at most 6 times.
* The complexity will be O(n * log(n)  +  m * log(n)  +  m * log(log(1e18)))
*/

ll nn;
pair<ll,ll> seg[N];

void modif(ll l,ll r,ll i = 1,ll st = 1,ll en = nn){
    if(st > r || en < l) return;
    if(st == en){
        ll s = sqrt(seg[i].F);
        seg[i] = mp(s , s);
        return;
    }

    if(seg[i].S == 1) return;

    ll mid = (st + en) >> 1;
    modif(l,r,i<<1,st,mid);
    modif(l,r,i<<1|1,mid+1,en);

    seg[i].F = seg[i<<1].F + seg[i<<1 | 1].F;
    seg[i].S = max(seg[i<<1].S , seg[i<<1 | 1].S);
}

ll que(ll l,ll r,ll i = 1,ll st = 1,ll en = nn){
    if(st > r || en < l) return 0;
    if(l <= st && en <= r) return seg[i].F;

    ll mid = (st + en) >> 1;
    return que(l,r,i<<1,st,mid) + que(l,r,i<<1 | 1,mid+1,en);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    ll tc = 1;
    while(cin >> n){
        if(tc != 1) cout << endl;
        cout << "Case #" << tc++ << ":\n";

        nn = pow(2,ceil(log2(n)));

        ll x;
        FOR(i,1,n) cin >> x , seg[i + nn - 1] = mp(x , x);
        ROF(i,nn - 1,1){
            seg[i].F = seg[i<<1].F + seg[i<<1 | 1].F;
            seg[i].S = max(seg[i<<1].S , seg[i<<1 | 1].S);
        }

        ll m; cin >> m;
        while(m--){
            ll t,x,y; cin >> t >> x >> y;
            if(x > y) swap(x , y);

            if(t == 0) modif(x , y);
            else cout << que(x , y) << endl;
        }
    }

    return 0;
}
