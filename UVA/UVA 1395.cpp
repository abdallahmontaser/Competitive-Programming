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
#define FOREACH(it,x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define FOR(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);++i)
#define ROF(i,a,b) for(ll i=(ll)(a);i>=(ll)(b);--i)
const ld PI=3.141592653589793238L;
const ll N=100005;
using namespace std;
//   <<>>

/**
* You need to understand how Kruskal's MST algorithm works(or understand how any other one works if you're going to use it).
* Say we start by the first edge e1(one with lowest weight), it's not hard to see that the MST algorithm will return the best slimness in any MST THAT HAS e1.
* That's because it's going to process edges by non-decreasing order of weights and try to construct an MST as soon as possible, so because
* it will also try to minimize the total sum of the weights of edges it uses, it will also minimize the maximum of them(again, given that it has e1).
* So for any MST that has e1, we have the best answer.
* 
* Now loop over the edges and at each one ei, start by taking it and get the maximum edge in the MST that has ei.The best answer for any MST that has ei
* will be that maximum - weight(ei).
* 
* If at any edge, we can't construct an MST(we can't connect all the nodes) then you can stop there(Line 95).
* If no MST was found, return -1.
* 
* The complexity for finding an MST in a graph with n nodes and m edges is O(n*log(m)).Given that we're sorting the edges in O(m*log(m)) and finding the MST at most m times,
* the final complexity will be - O(m*n*log(m)).
*/

ll rep[101],sz[101];
vector<pair<ll,pair<ll,ll> > >e;
ll n,m;
ll ans;

ll find(ll x){
    while(x != rep[x]) x=rep[x];
    return x;
}

void unite(ll x,ll y){
    if(sz[x]<sz[y]) swap(x,y);

    rep[y]=x;
    sz[x]+=sz[y];
}

bool MST(ll ind){
    ll mx=0,mn=1e5;
    FOR(i,ind,e.size()-1){
        ll u=e[i].second.first , v=e[i].second.second , w=e[i].first;
        u=find(u) , v=find(v);

        if(u != v) unite(u,v) , mx=max(mx,w) , mn=min(mn,w);
    }

    if(sz[find(1)] != n) return 0; // we couldn't connect all the nodes

    if(ans == -1 || ans > mx-mn) ans = mx-mn;
    return 1;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m;
    while(n || m){
        e.clear();

        while(m--){
            ll x,y,d; cin>>x>>y>>d;
            e.pb(mp(d,mp(x,y)));
        }
        sort(e.begin(),e.end());

        ans=-1;
        FOR(ind,0,e.size()-1){
            FOR(i,1,n) rep[i]=i , sz[i]=1;
            if(!MST(ind)) break;
        }

        cout<<ans<<endl;
        cin>>n>>m;
    }

    return 0;
}
