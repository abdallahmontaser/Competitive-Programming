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
#define EPS 1e-15
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
//   <<>>

/**
* Let dp[i] be equal to the number of ways to divide the string s[i..s.size()] into words from the set.
* Add all the strings of the set to a trie, and at each state i find out all the strings(of the set) that are prefixes of s[i..s.size()]
* and store them, then use them in the recurrence of the dp formula.Doing that with a trie will take at most O(L) operations where L is the
* maximum length a string in the set can have, which is 100.So it will pass.
*/

string s;
ll dp[N];

struct node{
    struct node* t[26];
    bool end;
    node(){
        FOR(i,0,25) t[i] = NULL;
        end=0;
    }
};
node* root;

void add(string ss){
    node* c = root;
    FOR(i,0,ss.size()-1){
        if(c->t[ss[i]-'a'] == NULL) c->t[ss[i]-'a'] = new node();
        c = c->t[ss[i]-'a'];
        if(i == ss.size()-1) c->end = 1;
    }
}

void query(vector<ll>&v,ll ind){
    node* c = root;
    FOR(i,ind,s.size()-1){
        if(c->t[s[i]-'a'] == NULL) return;
        c = c->t[s[i]-'a'];
        if(c->end) v.pb(i);
    }
}

ll solve(ll i){
    if(i == s.size()) return 1;
    ll&ans = dp[i];
    if(ans != -1) return ans;

    ans = 0;
    vector<ll>v;
    query(v,i);
    FOREACH(it,v) ans = (ans + solve(*it + 1)) % 20071027;

    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

    ll tc=0;
    while(cin >> s){
        ++tc;
        root = new node();

        ll n; cin >> n;
        while(n--){
            string t; cin >> t;
            add(t);
        }

        memset(dp,-1,sizeof(dp));
        cout << "Case " << tc << ": " << solve(0) << endl;
    }

    return 0;
}

