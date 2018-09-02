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
* Editorial for same exact solution: https://codeforces.com/blog/entry/18126
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n; cin >> n;

    ll t[n+1];
    FOR(i,1,n) cin >> t[i];

    ll L[n+1] , R[n+1];
    stack<ll>st;
    FOR(i,1,n){
        while(!st.empty() && t[st.top()] >= t[i]) st.pop();
        if(st.empty()) L[i] = 0;
        else L[i] = st.top();

        st.push(i);
    }

    while(!st.empty()) st.pop();
    ROF(i,n,1){
        while(!st.empty() && t[st.top()] >= t[i]) st.pop();
        if(st.empty()) R[i] = n + 1;
        else R[i] = st.top();

        st.push(i);
    }

    ll ans[n+1];
    FOR(i,1,n) ans[i] = 0;
    FOR(i,1,n) ans[R[i] - L[i] - 1] = max(ans[R[i] - L[i] - 1] , t[i]);

    ll mx = 0;
    ROF(i,n,1) ans[i] = max(ans[i] , mx) , mx = max(mx , ans[i]);

    FOR(i,1,n) cout << ans[i] << ((i == n) ? "\n" : " ");

    return 0;
}
