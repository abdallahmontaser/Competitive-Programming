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

/**
* Same solution as the editorial: https://codeforces.com/blog/entry/6054
*/

ll n;

bool equal(ll*a,ll*b){
    FOR(i,1,n) if(a[i] != b[i]) return 0;
    return 1;
}

void apply(ll*p,ll*a){
    ll tmp[n+1];
    FOR(i,1,n) tmp[i] = a[p[i]];
    FOR(i,1,n) a[i] = tmp[i];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

    ll k; cin >> n >> k;
    ll p[n+1] , t[n+1];
    FOR(i,1,n) cin >> p[i] , t[p[i]] = i;

    ll s[n+1];
    FOR(i,1,n) cin >> s[i];

    ll curr[n+1];
    FOR(i,1,n) curr[i] = i;

    if(equal(curr,s)){
        cout << "NO\n";
        return 0;
    }

    if(equal(p,t)){
        FOR(i,1,k){
            apply(p,curr);
            if(equal(curr,s) && i != k){
                cout << "NO\n";
                return 0;
            }
        }
        if(equal(curr,s)) cout << "YES\n";
        else cout << "NO\n";
        return 0;
    }

    bool found = 0;

    FOR(i,1,k){
        apply(p,curr);
        if(equal(curr,s) && !((k-i) & 1)) found = 1;
    }

    FOR(i,1,n) curr[i] = i;
    FOR(i,1,k){
        apply(t,curr);
        if(equal(curr,s) && !((k-i) & 1)) found = 1;
    }

    if(found) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}

