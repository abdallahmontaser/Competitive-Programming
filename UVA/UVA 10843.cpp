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
#define EPS 1e-9
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
#define endl '\n'

#define DUMPSTR_WNAME(os,name,a) do{(os) << "#DUMP " << (name) << " = " << (a) << "  ";}while(false)
#define dump(a) DUMPSTR_WNAME(cout, #a, (a))

#define FOREACH(it,x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define FOR(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);++i)
#define ROF(i,a,b) for(ll i=(ll)(a);i>=(ll)(b);--i)

const ld PI=3.141592653589793238L;
const ll N=300005;

using namespace std;

/**************************************************************************************************/

/**
* The answer is the number of possible trees(acyclic connected undirected graphs) with n nodes which is n^(n-2)
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

    ll tc; cin >> tc;
    FOR(t,1,tc){
        ll n; cin >> n;
        ll ans = 1;
        FOR(i,1,n-2) ans = (ans * n) % 2000000011;
        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}
