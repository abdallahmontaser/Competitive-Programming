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
const ll N = 2000005;
using namespace std;

/**
* Not very helpful official editorial: https://codeforces.com/blog/entry/54888
* A helpful comment: https://codeforces.com/blog/entry/54821?#comment-388474
* Another helpful comment: https://codeforces.com/blog/entry/54888?#comment-388584
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    #endif
    //<<>>
    
    ll n; cin >> n;
    multiset<ll> sold , not_used;
    
    sold.insert(1e9) , not_used.insert(1e9); // just dummy values
    ll ans = 0;
    FOR(i,1,n){
        ll x; cin >> x;
        ll a = *(sold.begin()) , b = *(not_used.begin());
        ll c = min(a , b);
        if(c >= x) not_used.insert(x);
        else if(*(sold.begin()) == c){
            not_used.insert(c);
            sold.erase(sold.find(c));
            sold.insert(x);
            ans += x - c;
        }else{
            not_used.erase(not_used.find(c));
            sold.insert(x);
            ans += x - c;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
