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
const ll N = 500005;
using namespace std;

/**
* Editorial: https://img.atcoder.jp/agc027/editorial.pdf
*/

ull a[N];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //<<>>

    ll n,x; cin >> n >> x;
    FOR(i,1,n) cin >> a[i];
    reverse(a + 1 , a + n + 1);
    ROF(i,n - 1,1) a[i] += a[i + 1];

    ull ans = ULLONG_MAX;
    FOR(k,1,n){
        ull ans1 = k * x;
        bool take = 1;

        FOR(i,1,n){
            ull ans2 = (a[i] - a[i + k]) * max(5ll , 2 * ((i - 1) / k + 1) + 1);
            if(ans - ans2 <= ans1) take = 0;
            ans1 += ans2;

            i += k - 1;
        }

        if(take == 1) ans = ans1;
    }

    ans += (ull) n * x;

    cout << ans << endl;

    return 0;
}
