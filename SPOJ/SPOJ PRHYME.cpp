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
const ll N=1000005;
using namespace std;
//   <<>>

/**
* Sorted all the strings in such a way(see cmp() function) that compares starting from the end - i.e. strings with common suffixes will be close to each other.
* Then I found the longest common suffix of each query string with all the strings in the wordlist using trie(deleted the string itself from the trie if it exists).
* Now from all the strings having this length as common suffix(lcs) with the query string, I need to take the smalles one(lexicographically).
* First I find the range of these strings(they will be neighbours because they are sorted based on suffix) and I take the minimum of them.
* I do this with a segment tree(range minimum query).
* But that's not it, what if the minimum of the strings in that range is the query string itself? that can't be the rhyme !
* So have the segment tree return the minimum and the second to minimum string in that range, and check(Line 162).
*/

map<string,bool>exist;
pair<string,string> seg[N];
ll n,nn;
string last = "{";

struct node{
    struct node* t[26];
    ll n;
    node(){
        FOR(i,0,25) t[i] = NULL;
        n=0;
    }
};
node* root = new node();

void add(string s){
    node* c = root;
    ++c->n;
    ROF(i,s.size()-1,0){
        ll ch = s[i]-'a';
        if(c->t[s[i]-'a'] == NULL) c->t[s[i]-'a'] = new node();
        c = c->t[s[i]-'a'];
        ++c->n;
    }
}

void del(string s){
    node *c = root , *prv;
    --c->n;
    ROF(i,s.size()-1,0){
        prv = c;

        c = c->t[s[i]-'a'];

        --c->n;
        if(c->n == 0){
            prv->t[s[i]-'a'] = NULL;
            return;
        }
    }
}

ll query(string s){
    node* c = root;
    ll ans = 0;
    ROF(i,s.size()-1,0){
        if(c->t[s[i]-'a'] == NULL) return ans;
        c = c->t[s[i]-'a'];
        ++ans;
    }

    return ans;
}

pair<string,string> getMin(ll l,ll r,ll i=0,ll start=0,ll end=nn-1){
    pair<string,string> ans = mp(last,last);
    if(start > r || end < l) return ans;
    if(l <= start && end <= r) return seg[i];

    ll mid = (start + end)/2;
    pair<string,string> left = getMin(l,r,2*i+1,start,mid);
    pair<string,string> right = getMin(l,r,2*i+2,mid+1,end);

    vector<string>tmp;
    tmp.pb(left.F) , tmp.pb(left.S);
    tmp.pb(right.F) , tmp.pb(right.S);
    sort(tmp.begin(),tmp.end());

    return mp(tmp[0],tmp[1]);
}

bool cmp(string a,string b){
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    return a < b;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

    string s;
    vector<string>v;
    while(getline(cin,s)){
        if(s.empty()) break;
        if(!exist[s]) v.pb(s);
        exist[s] = 1;
    }

    sort(v.begin(),v.end(),cmp);

    n = v.size();
    nn = pow(2,ceil(log2(n)));

    FOR(i,nn-1,nn-1+n-1) add(v[i-nn+1]) , seg[i].F = v[i-nn+1] , seg[i].S = last;
    FOR(i,nn-1+n,2*nn-2) seg[i].F = seg[i].S = last;

    ROF(i,nn-2,0){
        vector<string>tmp;
        tmp.pb(seg[2*i+1].F)  , tmp.pb(seg[2*i+1].S);
        tmp.pb(seg[2*i+2].F)  , tmp.pb(seg[2*i+2].S);
        sort(tmp.begin(),tmp.end());

        seg[i] = mp(tmp[0] , tmp[1]);
    }

    while(cin >> s){
        if(exist[s]) del(s);
        ll lcs = query(s); // length of the Longest Common Suffix
        if(exist[s]) add(s);
        string ss(s.end()-lcs,s.end());

        ll start = lower_bound(v.begin(),v.end(),ss,cmp) - v.begin();
        ll end = upper_bound(v.begin(),v.end(),last+ss,cmp) - v.begin();

        pair<string,string> ans = getMin(start,end-1);
        if(ans.F != s) cout << ans.F << endl;
        else cout << ans.S << endl;
    }

    return 0;
}

