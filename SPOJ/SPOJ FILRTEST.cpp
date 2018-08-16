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
const ll N=1000005;

using namespace std;

/******************************************************/

/**
* One must use either KMP or Z to find the longest substring that is both a suffix and a prefix of every string in the input in linear time.
* Let the length of that string be n and the length of that substring be m.
* Given K, we need to find the largest x such that we can make x strings.The length of a string repeated x times(having n,m as we discussed)
* is n + (x-1) * (n-m)
* 
* So: n + (x-1) * (n-m) <= K
* which means: x <= (K-n)/(n-m) + 1
*/

ll f[N];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

    ll n; string s;
    while(cin >> n >> s && n != -1){
        ll i = 1 , j = 0;
    	while(i < s.size()){
    		if(s[i] == s[j]){
    			f[i] = j+1;
    			++i , ++j;
			}
			else if(j) j = f[j-1];
			else f[i] = 0 , ++i;
		}

        if(n < s.size()) cout << "0\n";
		else cout << ((n - s.size()) / ((ll)s.size() - f[s.size()-1]) + 1) << endl;
    }

    return 0;
}

