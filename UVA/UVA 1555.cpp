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
* If you change the formula to: H(i) = 2 * H(i-1) - H(i-2) + 2 you can see that if we fix the position of the second lamp, all the
* sequence of positions will be fixed.So we just need to find a good position for the second lamp so that the position of the last
* lamp is as low as possible( >= 0).
* 
* If you put it above the first one, the sequence will always continue to increase, so we won't.
* 
* Now it's not hard to see that binary search will work to find the best position of the second lamp from 0 to A(position of the first).
* 
* Because if you put it low you'll get a negative value somewhere in the sequence, and of the values(real values) that give no negative
* position, the lowest of them gives the lowest position of B(the last lamp).
* 
* A different solution: https://github.com/achrafmam2/CompetitiveProgramming/blob/master/UVA/1555.cc
*/

ld b;

bool f(ll n,ld u,ld v){
    ld w;
    FOR(i,3,n){
        w = 2.0 * v - u + 2.0 , u = v , v = w;
        if(w < 0) return 0;
    }

    b = w;
    return 1;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n; ld a;
    while(cin >> n >> a){
        ld i = 0 , j = a;

        FOR(cnt,1,30){
            ld mid = (i + j) / 2;

            if(f(n,a,mid)) j = mid;
            else i = mid;
        }

        cout << fixed << setprecision(2) << b << endl;
    }

    return 0;
}
