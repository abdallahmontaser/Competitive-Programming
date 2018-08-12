#include <iostream>
#include<iomanip>
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
const ll N=100005;
using namespace std;
//   <<>>

vector<string>w;
ll dp[1<<13][13];
ll LC[13][13]; // LC[i][j] = length of the longest string such that it is a suffix of words[i] and a prefix of words[j].
ll n;

bool check(string a,string b){ // checks if "b" is a substring of "a".
    FOR(l,0,a.size()-1) FOR(r,l+1,a.size()){
        string tmp(a.begin()+l,a.begin()+r);
        if(tmp == b) return 1;
    }
    return 0;
}

ll solve(ll mask,ll prev){
    if(mask + 1 == 1<<n) return 0;
    ll&ans = dp[mask][prev];
    if(ans != -1) return ans;

    ans = 1e9;
    if(prev == n) FOR(i,0,n-1) ans = min(ans , (ll)w[i].size()+solve(1<<i,i));
    else FOR(i,0,n-1) if((mask&(1<<i)) == 0) ans = min(ans , (ll)w[i].size()-LC[prev][i] + solve(mask|(1<<i),i));

    return ans;
}

string get(ll mask,ll prev){
    if(mask + 1 == 1<<n) return "";

    vector<pair<pair<ll,string>,ll> >v;
    FOR(i,0,n-1) if((mask&(1<<i)) == 0){
        string tmp;
        if(prev == n) tmp.assign(w[i].begin(),w[i].end());
        else  tmp.assign(w[i].begin()+LC[prev][i],w[i].end());

        ll x;
        if(prev == n) x = w[i].size() + solve(1<<i,i);
        else x = w[i].size()-LC[prev][i] + solve(mask|(1<<i),i);

        v.pb(mp(mp(x,tmp),i));
    }
    sort(v.begin(),v.end());

    return v[0].F.S + get(mask|(1<<v[0].S),v[0].S);
}

class JoinedString{
    public: string joinWords(vector <string> words){
        w.assign(words.begin(),words.end());
        while(true){ // erasing every string that is a substring of another string in the vector(otherwise the dp won't work, and it's harmless)
            ll found = 0;
            FOR(i,0,w.size()-1) FOR(j,0,w.size()-1) if(i!=j && check(w[i],w[j])){
                found = 1;
                w.erase(w.begin()+j);
                i = j = w.size();
            }
            if(!found) break;
        }

        n = w.size();
        FOR(i,0,n-1) FOR(j,0,n-1) if(i!=j){
            FOR(cnt,1,min(w[i].size(),w[j].size())-1){
                string a(w[i].end()-cnt,w[i].end());
                string b(w[j].begin(),w[j].begin()+cnt);
                if(a == b) LC[i][j] = cnt;
            }
        }

        memset(dp,-1,sizeof(dp));
        solve(0,n);

        return get(0,n);
    };
};

