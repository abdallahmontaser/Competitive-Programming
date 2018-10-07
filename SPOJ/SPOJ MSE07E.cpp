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
#define dump(a) DUMP_NAME(#a, (a));

#define FOREACH(it,x) for(__typeof__((x).begin()) it = (x).begin();it!=(x).end();++it)
#define FOR(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);++i)
#define ROF(i,a,b) for(ll i=(ll)(a);i>=(ll)(b);--i)

const ld PI = 3.141592653589793238L;
const ll N = 200005;

using namespace std;

/**************************************************************************************************/

/**
* First compute the total number of references in a data set.If it's even then there's no corruption.
* If it's odd then there's one element that is repeated an odd number of times.
* 
* Using binary search, every time we divide our range in two halves [low;mid] and [mid+1;high], we compute the same thing for [low;mid]
* If it's odd then the element we're looking for is in that half, else it's in the other.
* Keep doing that until we find the element(when low = high) then the total number of references in [low;mid] will be the count of that
* element(since mid = high) which will be odd.
*/

bool blank(string &s){
    FOREACH(it, s) if(*it != ' ' && *it != '\n' && *it != '\r') return 0;
    return 1;
}

ll nb(ll a,ll b,ll c,ll d,ll x,ll z){ // the number of elements in the form x + k*z (k is some integer) in the intersection of [a;b] and [c;d]
    if(a > d || b < c) return 0;

    a = max(a, c);
    b = min(b, d);

    if((a - x) % z != 0) a += z - (a - x) % z;
    b -= (b - x) % z;

    return (b - a) / z + 1;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("grant.in","r",stdin);
    //freopen("grant.out","w",stdout);

    string s;
    vector<string>v;
    while(getline(cin, s)) v.pb(s);

    ll ind = 0;
    while(1){
        while(ind <= sz(v) - 1 && blank(v[ind]) == 1) ++ind;
        if(ind == sz(v)) break;

        vector<pair<ll,pair<ll,ll>>>data;
        ll total = 0;
        while(ind <= sz(v) - 1 && blank(v[ind]) == 0){
            istringstream iss(v[ind]);
            ll x,y,z; iss >> x >> y >> z;

            data.pb(mp(x,mp(y,z)));
            if(x <= y) total += (y - x) / z + 1;

            ++ind;
        }
    
        if((total & 1) == 0){
            cout << "no corruption" << endl;
            continue;
        }
        
        ll low = 1 , high = 1e12;
        while(low <= high){
            ll cnt = 0;

            ll mid = (low + high) >> 1;
            FOR(i,0,sz(data) - 1){
                ll st = data[i].F , en = data[i].S.F;
                ll z = data[i].S.S;

                if(st > en) continue;

                cnt += nb(st,en,low,mid,st,z);
            }

            if(low == high){
                cout << low << " " << cnt << endl;
                break;
            }

            if((cnt & 1) == 1) high = mid;
            else low = mid + 1;
        }


    }

    return 0;
}
