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
* Editorial: https://codeforces.com/blog/entry/2426
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n,k,p; cin >> n >> k >> p;

    if(k == 0){
        while(p--) cout << ".";
        return 0;
    }

    if(k == 1){
        while(p--){
            ll i; cin >> i;
            cout << ((i == n) ? "X" : ".");
        }
        return 0;
    }

    ll nb;
    if(2 * k >= n) nb = 2 * k - n;
    else if((n - 2 * k) & 1) nb = 1;
    else nb = 0;

    while(p--){
        ll i; cin >> i;

        if(i + nb > n) cout << "X";
        else if(i + (k - nb) * 2 + nb > n) cout << (((i & 1) == ((n - nb) & 1)) ? "X" : ".");
        else cout << ".";
    }

    return 0;
}
