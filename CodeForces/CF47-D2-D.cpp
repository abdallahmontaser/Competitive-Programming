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
const ll N = 100005;

using namespace std;

/**************************************************************************************************/

/**
* First find all the possible key variants that do not contradict the first system response, then loop from the second response to the last
* while deleting any present key variant that contradicts the current system response.
*/

ll n,m;
pair<string,ll> a[11];
vector<vector<ll>>v;

void solve(vector<ll>t,ll i,ll nb){
    if(i + nb - 1 > n - 1) return;

    if(nb == 0){
        v.pb(t);
        return;
    }

    t.pb(0);
    FOR(j,i,n - 1){
        t[sz(t) - 1] = j;
        solve(t,j + 1,nb - 1);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n >> m;
    FOR(i,1,m) cin >> a[i].F >> a[i].S;

    string s;
    FOR(i,1,m) if(a[i].S == 0) s = a[i].F;
    if(s != ""){
        FOR(i,0,n - 1) s[i] = ((s[i] == '1') ? '0' : '1');
        bool valid = 1;
        FOR(i,1,m){
            ll nb = 0;
            FOR(j,0,n - 1) nb += (a[i].F[j] == s[j]);
            if(nb != a[i].S) valid = 0;
        }

        FOR(i,1,m) if(s == a[i].F) valid = 0;

        cout << valid << endl;
        return 0;
    }

    vector<ll>tmp;
    solve(tmp,0,a[1].S);

    set<string>st;
    FOREACH(it,v){
        string s = a[1].F;
        FOR(j,0,n - 1) s[j] = ((s[j] == '1') ? '0' : '1');
        FOREACH(it2,*it) s[*it2] = a[1].F[*it2];

        st.insert(s);
    }

    FOR(i,2,m){
        set<string>tmp;

        FOREACH(it,st){
            ll nb = 0;
            FOR(j,0,n - 1) nb += ((*it)[j] == a[i].F[j]);

            if(nb == a[i].S) tmp.insert(*it);
        }

        swap(st, tmp);
    }

    cout << sz(st) << endl;

    return 0;
}
