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
#define FOREACH(it,x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define FOR(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);++i)
#define ROF(i,a,b) for(ll i=(ll)(a);i>=(ll)(b);--i)

const ld PI=3.141592653589793238L;
const ll N=300005;

using namespace std;

/**
* Editorial: https://csacademy.com/contest/archive/task/gcd-rebuild/solution/
*/

ll lcm(ll x,ll y){
    return (x / __gcd(x,y)) * y;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

    ll n,m; cin >> n >> m;
    ll mat[n+1][m+1]; FOR(i,1,n) FOR(j,1,m) cin >> mat[i][j];

    ll a[n+1];
    FOR(i,1,n){
        a[i] = 1;
        FOR(j,1,m) a[i] = lcm(a[i],mat[i][j]);
        if(a[i] > 1e9){cout << "-1\n"; return 0;}
    }

    ll b[m+1];
    FOR(j,1,m){
        b[j] = 1;
        FOR(i,1,n) b[j] = lcm(b[j],mat[i][j]);
        if(b[j] > 1e9){cout << "-1\n"; return 0;}
    }

    FOR(i,1,n) FOR(j,1,m) if(mat[i][j] != __gcd(a[i],b[j])){cout << "-1\n"; return 0;}

    FOR(i,1,n) cout << a[i] << ((i == n) ? "\n" : " ");
    FOR(j,1,m) cout << b[j] << ((j == m) ? "\n" : " ");

    return 0;
}



