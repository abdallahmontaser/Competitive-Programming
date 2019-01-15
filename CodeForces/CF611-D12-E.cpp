#include <bits/stdc++.h>

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

/**
* Here is a well explained solution: https://codeforces.com/blog/entry/22441?#comment-270050
* And this is the editorial: https://codeforces.com/blog/entry/22441
*/

set<pair<ll,ll> > s;

void del(int x) {
    if (s.empty()) return;
    if ((*s.begin()).F > x) return;
    if (((*s.rbegin()).F <= x)) {
        s.erase(*s.rbegin());
        return;
    }

    set<pair<ll,ll> >::iterator it = s.lower_bound(mp(x , 0));
    if ((*it).F > x) it--;
    s.erase(*it);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif
    //<<>>

    ll n; cin >> n;
    ll a,b,c; cin >> a >> b >> c;

    bool valid = 1;    
    FOR(i,1,n){
        ll x; cin >> x;
        s.insert(mp(x , i));
        if(x > a + b + c) valid = 0;
    }

    if(valid == 0){
        cout << "-1\n";
        return 0;
    }

    ll ta = max(a,max(b,c)) , tc = min(a,min(b,c)) , tb = a + b + c - ta - tc;
    a = ta , b = tb , c = tc;

    ll ans = 0;
    
    if ((*s.rbegin()).F > a + b + c) {
        cout << "-1\n";
        return 0;
    }

    while (!s.empty() && (*s.rbegin()).F > a + b) ++ans , del(a + b + c);

    while (!s.empty() && (*s.rbegin()).F > a + c) del(a + b) , del(c) , ++ans;

    while (!s.empty() && ((*s.rbegin()).F > max(a , b + c))) del(a + c) , del(b) , ++ans;

    if (a >= b + c) {
        while (!s.empty()) {
            ++ans , del(a);

            if(s.empty()) continue;

            if ((*s.begin()).F <= b) del(b) , del(c);
            else del(b + c);
        }
    } else {
        while (!s.empty() && ((*s.rbegin()).F > a)) del(b + c) , del(a) , ++ans;

        while (!s.empty()) {
            ++ans , del(a);

            if(s.empty()) continue;

            if ((*s.begin()).F <= b) del(b) , del(c);
            else del(b + c);
        }
    }

    cout << ans << endl;

    return 0;
}
