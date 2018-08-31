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
* Beware; if you copy the "NO I WON'T" from the output statement it will cause a WA because the apostrophe in it will be read as a different
* apostrophe than ' by the IDE(with a different ASCII number) so write it yourself.
* 
* Rest is pure implementation.
* 
* Cool java solution: https://github.com/ackoroa/UVa-Solutions/blob/master/UVa%2010058%20-%20Jimmi's%20Riddles/src/Main.java
*/

bool verb(string s){
    ll ind = -1;
    ROF(i,sz(s)-1,0) if(s[i] != 's'){
        ind = i;
        break;
    }
    string m(s.begin(),s.begin()+ind);
    return (m == "hate" || m == "love" || m == "know" || m == "like");
}

bool noun(string s){
    return (s == "tom" || s == "jerry" || s == "goofy" || s == "mickey" || s == "jimmy" || s == "dog" || s == "cat" || s == "mouse");
}

bool article(string s){
    return (s == "a" || s == "the");
}

bool actor(string s){
    vector<string>v;
    string m;
    istringstream iss(s);
    while(iss >> m) v.pb(m);

    if(sz(v) == 1) return noun(v[0]);

    if(sz(v) == 2) return article(v[0]) && noun(v[1]);

    return 0;
}

bool active_list(string s){
    vector<string>v,v2;
    string m,total;
    istringstream iss(s);
    while(iss >> m){
        if(m == "and"){
            v2.pb(total);
            total = "";
        }
        else total += " " + m;
    }
    v2.pb(total);

    if(v2.empty()) return 0;

    FOREACH(it,v2) if(!actor(*it)) return 0;

    return 1;
}

bool action(string s){
    vector<string>v;
    string m;
    istringstream iss(s);
    while(iss >> m) v.pb(m);

    ll ind = -1;
    FOR(i,0,sz(v)-1) if(verb(v[i])) ind = i;

    if(ind == -1) return 0;

    string a,b;
    FOR(i,0,ind-1) a += " " + v[i];
    FOR(i,ind+1,sz(v)-1) b += " " + v[i];

    return active_list(a) && active_list(b);
}

bool statement(string s){
    vector<string>v,v2;
    string m,total;
    istringstream iss(s);
    while(iss >> m){
        if(m == ","){
            v2.pb(total);
            total = "";
        }
        else total += " " + m;
    }
    v2.pb(total);

    if(v2.empty()) return 0;

    FOREACH(it,v2) if(!action(*it)) return 0;

    return 1;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string s;
    while(getline(cin,s)){
        if(statement(s)) cout << "YES I WILL\n";
        else cout << "NO I WON'T\n";
    }

    return 0;
}
