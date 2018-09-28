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
* Pure implementation.
* Here I verify that a sequence is valid before calculating it(but you can do both together).
* 
* Beware of the priority between the operators '+' and '*'.For example 5+4*3 should give 17 not 27.
*/

string s;
ll c[N];

bool is_valid(ll i, ll j){
    if(j < i) return 0;
    if(i == j) return isdigit(s[i]);

    if(s[i] == '*' || s[i] == '+') return 0;
    if(s[j] == '*' || s[j] == '+') return 0;
    if(s[i] == ')' || s[j] == '(') return 0;

    if(s[i] == '('){
        if(c[i] == j) return is_valid(i + 1, j - 1);
        return is_valid(i,c[i]) && is_valid(c[i] + 2, j) && (s[c[i] + 1] == '+' || s[c[i] + 1] == '*');
    }

    bool nbr = 1;
    FOR(k,i,j) if(!isdigit(s[k])) nbr = 0;
    if(nbr == 1) return 1;

    return (s[c[i] + 1] == '+' || s[c[i] + 1] == '*') && is_valid(c[i] + 2, j);
}

ll val(ll i, ll j){
    bool nbr = 1;
    FOR(ind,i,j) if(!isdigit(s[ind])) nbr = 0;
    if(nbr == 1){
        ll x = 0;
        FOR(k,i,j) x *= 10 , x += (ll)(s[k] - '0');
        return x;
    }
    
    if(c[i] == j) return val(i + 1, j - 1);
    
    if(s[c[i] + 1] == '+') return val(i, c[i]) + val(c[i] + 2, j);
    
    if(s[c[i] + 1] == '*'){
        ll ans = val(i, c[i]);
        ll k = c[i] + 1;
        while(k <= j){
            if(s[k] == '+') return ans + val(k + 1, j);
            else ans *= val(k + 1, c[k + 1]) , k = c[k + 1] + 1;
        }
        
        return ans;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n; cin >> n;
    while(n--){
        cin >> s;
        bool good = 1;

        FOR(i,0,sz(s) - 1) if(s[i] != '+' && s[i] != '*' && s[i] != '(' && s[i] != ')'){
            if(!isdigit(s[i])) good = 0;
        }

        stack<ll>st;
        FOR(i,0,sz(s) - 1){
            if(s[i] == '(') st.push(i);
            if(s[i] == ')'){
                if(st.empty() == 1){
                    good = 0;
                    break;
                }
                c[st.top()] = i;
                st.pop();
            }
        }

        if(st.empty() == 0) good = 0;

        FOR(i,0,sz(s) - 1) if(isdigit(s[i])){
            ll j = i;
            while(j + 1 <= sz(s) - 1 && isdigit(s[j + 1])) ++j;
            c[i] = j;
            i = j;
        }

        if(good == 0 || !is_valid(0,sz(s) - 1)){
            cout << "ERROR\n";
            continue;
        }

        cout << val(0, sz(s) - 1) << endl;
    }

    return 0;
}
