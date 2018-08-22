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
* Construct an array prv - where prv[i] is the biggest index j such that j < i and t[j] = t[i] i.e. prv[i] is the previous occurence of t[i]
* and 0 if it's the first.
* Also store the indices of non rainy days in a set(for quick removal and search).
* 
* Now the solution for every rainy day i in pool t[i] is simply assigning the dragon to the lake t[i] in the earliest non rainy day AFTER
* prv[i].So between the rainy days before day i and day prv[i], the first one.
* 
* This can be found by lower_bound in a set.
*/

ll t[N] , ans[N];
ll prv[N] , curr[N];
set<ll>s;

bool solve(ll n,ll m){
    FOR(i,1,m) if(t[i] != 0){
        set<ll>::iterator it = s.lower_bound(prv[i]);
        if(it == s.end() || *it > i) return 0;
        ans[*it] = t[i];
        s.erase(it);
    }

    return 1;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll tc; cin >> tc;
    while(tc--){
        s.clear();
        ll n,m; cin >> n >> m;

        FOR(i,1,n) curr[i] = 0;
        FOR(i,1,m){
            ll x; cin >> x;
            t[i] = x;
            if(x == 0) s.insert(i) , ans[i] = 0;
            else prv[i] = curr[x] , curr[x] = i;
        }

        if(solve(n,m)){
            cout << "YES\n";
            FOR(i,1,m) if(t[i] == 0) cout << ans[i] << " ";
            cout << endl;
        }
        else cout << "NO\n";
    }

    return 0;
}
