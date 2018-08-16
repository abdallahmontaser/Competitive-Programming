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

/******************************************************/

/**
* The answer to the problem is the minimum number of sequences that the array can be divided into such that they are non-decreasing in both
* length and weight.
* How about you first sort according to non-decreasin length? and if lengths are equal sort by non-decreasing weights?
* The problem is now reduced to finding the minimum number of non-decreasing subsequences in the newly sorted array of pairs.
*
* This can be done iteratively, while storing in a vector the current element of every subsequence(Greedy).
* 
* Go over the array(we only need to look at weights now).Look for the biggest element you stored before that is <= this weight(w) and replace
* it with w.The answer will be the number of elements in the vector(i.e. the number of subsequences you have chosen).
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

    ll tc; cin >> tc;
    while(tc--){
        ll n; cin >> n;
        pair<ll,ll> t[n+1];
        FOR(i,1,n) cin >> t[i].F >> t[i].S;
        sort(t+1,t+n+1);

        vector<ll>v;

        FOR(i,1,n){
            bool found = 0;
            FOR(j,0,v.size()-1) if(v[j] <= t[i].S){
                found = 1;
                v[j] = t[i].S;
                break;
            }

            if(!found) v.pb(t[i].S);
        }

        cout << v.size() << endl;
    }

    return 0;
}
