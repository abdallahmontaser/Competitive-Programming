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
const ll N = 300005;

using namespace std;

/**************************************************************************************************/

/**
* Use two arrays; l and r such that l[i] is the number of the box that is left of the i_th box (r for right).
* l[1] and r[n] are both equal to 0(they need to be equal because of the 4th query, read next).
* For the 4th query, simply swap the two arrays.
* 
* For the other arrays, it's not hard to figure out how to adapt the arrays to the changes.
* You need to know in the end the number of the first box.For that I maintained two values; first and last initilized to 1 and n.
* Then you adapt them with every query.
* 
* At last you just keep going right of the "first" box and sum the numbers whose index is odd.
*/

ll n , m;
ll first , last;

void modif(ll t,ll x,ll y,vector<ll>&l,vector<ll>&r){
    if(t == 1 && l[y] != x){
        if(first == x) first = r[x];
        else if(first == y) first = x;
        if(last == x) last = l[x];

        if(r[y] == x){
            ll a = l[y] , b = r[x];

            r[a] = x , l[b] = y;
            r[y] = b , l[y] = x;
            l[x] = a , r[x] = y;
        }
        else{
            ll a = l[x] , b = r[x] , c = l[y];

            r[a] = b , l[b] = a;
            r[c] = x , l[y] = x;
            l[x] = c , r[x] = y;
        }
    }

    else if(t == 2 && r[y] != x){
        if(first == x) first = r[x];
        if(last == x) last = l[x];
        else if(last == y) last = x;

        if(l[y] == x){
            ll a = l[x] , b = r[y];

            r[a] = y , l[b] = x;
            r[y] = x , l[y] = a;
            l[x] = y , r[x] = b;
        }
        else{
            ll a = l[x] , b = r[x] , c = r[y];

            r[a] = b , l[b] = a;
            l[c] = x , r[y] = x;
            l[x] = y , r[x] = c;
        }
    }

    else if(t == 3){
        if(first == x || first == y) first = x + y - first;
        if(last == x || last == y) last = x + y - last;

        if(l[y] == x){
            ll a = l[x] , b = r[y];

            r[a] = y , l[b] = x;
            r[y] = x , l[y] = a;
            l[x] = y , r[x] = b;
        }
        else if(r[y] == x){
            ll a = l[y] , b = r[x];

            r[a] = x , l[b] = y;
            r[y] = b , l[y] = x;
            l[x] = a , r[x] = y;
        }
        else{
            ll a = l[x] , b = r[x];
            ll c = l[y] , d = r[y];

            r[a] = y , l[b] = y;
            r[c] = x , l[d] = x;
            l[x] = c , r[x] = d;
            l[y] = a , r[y] = b;
        }
    }

}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll tc = 0;
    while(cin >> n >> m){
        first = 1 , last = n;
        vector<ll> l(n+1) , r(n+1);
        FOR(i,1,n) l[i] = i - 1 , r[i] = i + 1;
        r[n] = 0;

        FOR(i,1,m){
            ll t; cin >> t;
            if(t == 4) swap(l , r) , swap(first , last);
            else{
                ll x,y;
                cin >> x >> y;
                modif(t,x,y,l,r);
            }
        }

        ll sum = 0;
        FOR(i,1,n){
            sum += (i % 2) * first;
            first = r[first];
        }

        cout << "Case " << ++tc << ": " << sum << endl;
    }

    return 0;
}
