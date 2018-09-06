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
* We first find the best answer is the first partition contains the whole array and the second is empty.
* Then we go through all elements, and compute the answer for the case when the second partition contains only that element.
* 
* Even better and shorter greedy solution: https://codeforces.com/blog/entry/5765?#comment-111215
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n,h; cin >> n >> h;
    ll t[n + 1] , t2[n + 1]; FOR(i,1,n) cin >> t[i] , t2[i] = t[i];
    sort(t2 + 1 , t2 + n + 1);

    if(n == 2){
        cout << "0" << endl << "1 1" << endl;
        return 0;
    }

    ll ans , best = -1;
    FOR(i,1,n){
        ll a,b,c,d;

        if(t[i] == t2[1]) a = 2 , b = 3;
        else if(t[i] == t2[2]) a = 1 , b = 3;
        else a = 1 , b = 2;

        if(t[i] == t2[n]) c = n - 1 , d = n - 2;
        else if(t[i] == t2[n - 1]) c = n , d = n - 3;
        else c = n , d = n - 1;

        ll tmp[4];
        tmp[0] = t2[a] + t2[b];
        tmp[1] = t2[c] + t2[d];
        tmp[2] = t[i] + t2[a] + h;
        tmp[3] = t[i] + t2[c] + h;

        sort(tmp , tmp + 4);

        if(best == -1 || best > tmp[3] - tmp[0]) best = tmp[3] - tmp[0] , ans = i;
    }

    if(best > t2[n] + t2[n - 1] - t2[1] - t2[2]) best = t2[n] + t2[n - 1] - t2[1] - t2[2] , ans = -1;

    cout << best << endl;
    FOR(i,1,n) cout << ((i == ans) ? "2 " : "1 ");
    cout << endl;

    return 0;
}
