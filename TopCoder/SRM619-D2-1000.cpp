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
* Editorial: https://apps.topcoder.com/wiki/display/tc/SRM+619
*/

class EmployManager{
    public: int maximumEarnings(vector<int> value, vector<string> earning){
        ll ans1 = 0 , ans2 = 0 , n = value.size();
        FOR(i,0,n-1){
            ll sum = 0;
            FOR(j,0,n-1) sum += earning[i][j] - '0';

            ans1 += max(0ll , sum - value[i]);
            ans2 -= sum;
        }

        return ans1 + ans2 / 2;
    };
};
