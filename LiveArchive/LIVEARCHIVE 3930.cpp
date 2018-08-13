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
#define EPS 1e-15
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
#define endl '\n'
#define FOREACH(it,x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define FOR(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);++i)
#define ROF(i,a,b) for(ll i=(ll)(a);i>=(ll)(b);--i)
const ld PI=3.141592653589793238L;
const ll N=300005;
using namespace std;
//   <<>>

ll dp[2000000];
ll pow_3[13];
ll convert[1<<26];

ll calc(ll mask){
    ll n = __builtin_popcount(mask);
    if(n <  3) return 0;

    ll&val = convert[mask];
    if(val == 0) FOR(i,0,12){
        if(mask&(1<<i)) val += pow_3[i];
        if(mask&(1<<(i+13))) val += pow_3[i];
    }

    ll&ans = dp[val];
    if(ans != -1) return ans;

    vector<ll>v;
    FOR(i,0,12) if((mask&(1<<i)) || mask&(1<<(i+13)))  v.pb(i+1);

    ans = 0;
    FOR(i,0,v.size()-1) FOR(j,i,v.size()-1) FOR(k,j,v.size()-1){
        if(v[i] == v[j] && v[j] == v[k]) continue;
        if((v[i] == v[j] || v[i] == v[k]) && ((mask&(1<<(v[i]-1))) == 0 || (mask&(1<<(v[i]-1+13))) == 0)) continue;
        if((v[j] == v[i] || v[j] == v[k]) && ((mask&(1<<(v[j]-1))) == 0 || (mask&(1<<(v[j]-1+13))) == 0)) continue;
        if((v[k] == v[i] || v[k] == v[j]) && ((mask&(1<<(v[k]-1))) == 0 || (mask&(1<<(v[k]-1+13))) == 0)) continue;

        if(v[i] + v[j] <= v[k]){
            k=v.size();
            continue;
        }

        ll t_mask = mask;

        if(t_mask&(1<<(v[i]-1+13))) t_mask -= (1<<(v[i]-1+13));
        else t_mask -= (1<<(v[i]-1));

        if(t_mask&(1<<(v[j]-1+13))) t_mask -= (1<<(v[j]-1+13));
        else t_mask -= (1<<(v[j]-1));

        if(t_mask&(1<<(v[k]-1+13))) t_mask -= (1<<(v[k]-1+13));
        else t_mask -= (1<<(v[k]-1));

        k = v.size();

        ans = max(ans , 1 + calc(t_mask));
        if(ans == n/3) return ans;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

    pow_3[0]=1;
    FOR(i,1,12) pow_3[i] = 3*pow_3[i-1];

    memset(dp,-1,sizeof(dp));

    ll n;
    while(cin >> n && n){
        ll a[14] , b[14];
        FOR(i,1,13) a[i] = b[i] = 0;

        FOR(i,1,n){
            ll t; cin >> t;
            if(i & 1) ++a[t];
            else ++b[t];
        }

        ll x1 = 0 , x2 = 0;
        FOR(i,1,13){
            x1 += a[i]/3 , a[i] %= 3;
            x2 += b[i]/3 , b[i] %= 3;
        }

        if(x1 != x2){
            if(x1 > x2) cout << "1\n";
            else cout << "2\n";
            continue;
        }

        ll mask1 = 0 , mask2 = 0;
        FOR(i,1,13){
            if(a[i]) mask1 += (1<<(i-1));
            if(a[i] == 2) mask1 += (1<<(i-1+13));

            if(b[i]) mask2 += (1<<(i-1));
            if(b[i] == 2) mask2 += (1<<(i-1+13));
        }

        x1 = calc(mask1) , x2 = calc(mask2);

        if(x1 > x2) cout << "1\n";
        else if(x1 < x2) cout << "2\n";
        else cout << "0\n";
    }

    return 0;
}

