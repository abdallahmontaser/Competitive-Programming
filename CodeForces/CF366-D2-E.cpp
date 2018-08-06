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
#define endl '\n'
#define foreach(it,x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define FOR(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);++i)
#define ROF(i,a,b) for(ll i=(ll)(a);i>=(ll)(b);--i)
const ld PI=3.141592653589793238L;
const ll N=100005;
using namespace std;
//   <<>>

/**
* Notice that to get the maximum distance between any two notes (k1,k2), we only need to compare the distance between at most 4 positions in each note.
* i.e. for every note x, we only store at most 4 pairs (i,j) such that t[i][j] = x.Those 4 are the closest to these four positions: (1,1) , (1,m) , (n,1) and (n,m).
*
* Editorial for another solution: http://codeforces.com/blog/entry/9704
*/

ll n,m,s,k;
pair<ll,ll>t[10][4];

ll dist(pair<ll,ll>&x,pair<ll,ll>&y){
    return abs(x.first-y.first) + abs(x.second-y.second);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m>>k>>s;

    vector<pair<ll,ll> >v[k+1];
    FOR(i,1,n) FOR(j,1,m){
        ll x; cin>>x;
        v[x].pb(mp(i,j));
    }

    pair<ll,ll>x[4];
    x[0]=mp(1,1) , x[1]=mp(1,m) , x[2]=mp(n,1) , x[3]=mp(n,m);

    FOR(i,1,k) if(!v[i].empty()){
        FOR(j,0,3){
            t[i][j] = v[i][0]; FOR(ind,1,v[i].size()-1) if(dist(x[j],v[i][ind]) < dist(x[j],t[i][j])) t[i][j]=v[i][ind];
        }
    }

    ll ans=0,last=0;
    FOR(i,1,s){
        ll curr; cin>>curr;
        if(last) FOR(j1,0,3) FOR(j2,0,3) ans=max(ans , dist(t[last][j1] , t[curr][j2]));
        last = curr;
    }

    cout<<ans<<endl;

    return 0;
}
