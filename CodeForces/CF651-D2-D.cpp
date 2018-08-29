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
* Same as the second solution in the editorial: https://codeforces.com/blog/entry/43677
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n,a,b,T; cin >> n >> a >> b >> T;
    ll t[n+1];
    FOR(i,1,n){
        char ch; cin >> ch;
        t[i] = b * (ch == 'w');
    }

    if(T < 1 + t[1]){
        cout << "0\n";
        return 0;
    }
    T -= 1 + t[1];

    ll ans = 1;

    ll l[n+1];
    ll curr = 0;
    FOR(i,2,n){
        if(curr + a + 1 + t[i] > T){
            curr = 2e9;
            l[i] = curr;
            continue;
        }

        curr += a + 1 + t[i];
        l[i] = curr;
        ans = max(ans, i);
    }

    ll r[n+1];
    curr = 0;
    ROF(i,n,2){
        if(curr + a + 1 + t[i] > T){
            curr = 2e9;
            r[i] = curr;
            continue;
        }

        curr += a + 1 + t[i];
        r[i] = curr;
        ans = max(ans , n - i + 2);
    }

    FOR(i,2,n){
        ll low = i + 1 , high = n;
        while(low <= high){
            ll mid = (low + high) / 2;
            if(l[i] + a * (i - 1) + r[mid] <= T) ans = max(ans , i + n - mid + 1) , high = mid - 1;
            else low = mid + 1;
        }
    }

    ROF(i,n,2){
        ll low = 2 , high = i - 1;
        while(low <= high){
            ll mid = (low + high) / 2;
            if(r[i] + a * (n - i + 1) + l[mid] <= T) ans = max(ans , mid + n - i + 1) , low = mid + 1;
            else high = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}
