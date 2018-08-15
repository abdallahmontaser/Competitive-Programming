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
* Editorial: https://codeforces.com/blog/entry/48501
*/

bool cmp(pair<ll,ll>&a,pair<ll,ll>&b){return (a.S - a.F > b.S - b.F);}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

    ll n,a,b,k; cin >> n >> a >> b >> k;

    vector<pair<ll,ll> >v;
    ll last = 1;
    FOR(i,1,n){
        char ch; cin >> ch;
        if(ch == '0') continue;

        v.pb(mp(last,i-1));
        last = i+1;
    }
    v.pb(mp(last,n));

    ll nb = 0;
    FOR(i,0,v.size()-1) nb += (v[i].S - v[i].F + 1) / b;

    if(nb < a){
        cout << "0\n";
        return 0;
    }

    sort(v.begin(),v.end(),cmp);

    vector<ll>ans;
    ll curr = v[0].F - 1;
    FOR(i,0,v.size()-1){
        --nb;
        curr += b;

        ans.pb(curr);
        if(nb < a) break;

        if(curr + b > v[i].S) curr = v[i+1].F - 1;
        else --i;
    }

    cout << ans.size() << endl;
    FOREACH(it,ans) cout << *it << " ";

    return 0;
}
