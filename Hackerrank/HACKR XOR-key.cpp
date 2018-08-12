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

/**
* Solved with MO's algorithm with trie.
* Although the complexity is high, it still passes.
*/

ll nb[(1<<15)+5]; // nb[i] how many occurences of i are there in our current query.We only insert every number once in the trie.
ll a[N] , ans[50005];
pair<pair<ll,ll>,pair<ll,ll> >qu[50005];
ll block;

struct node{
    struct node *z , *o;
    ll n;
    node(){
        z=NULL;
        o=NULL;
        n=0;
    }
};
node* root = new node();

void add(ll x){
    ++nb[x];
    if(nb[x] > 1) return;

    node* c = root;
    ++c->n;
    ROF(i,15,0){
        if(x&(1<<i)){
            if(c->o == NULL) c->o = new node();
            c=c->o;
        }else{
            if(c->z == NULL) c->z = new node();
            c=c->z;
        }
        ++c->n;
    }
}

void del(ll x){
    --nb[x];
    if(nb[x] > 0) return;

    node *c = root , *prv;
    --c->n;
    ROF(i,15,0){
        prv = c;

        if(x&(1<<i)) c = c->o;
        else c = c->z;

        --c->n;
        if(c->n == 0){
            if(x&(1<<i)) prv->o = NULL;
            else prv->z = NULL;
            return;
        }
    }
}

ll query(ll x){
    node* c = root;
    ROF(i,15,0){
        if(x&(1<<i)){
            if(c->z != NULL) c=c->z;
            else x-=(1<<i) , c=c->o;
        }else{
            if(c->o != NULL) x+=(1<<i) , c=c->o;
            else  c=c->z;
        }
    }

    return x;
}

bool cmp(pair<pair<ll,ll>,pair<ll,ll> >a,pair<pair<ll,ll>,pair<ll,ll> >b){
    ll x = a.F.F / block , y = b.F.F / block;
    if(x != y) return x < y;
    
    if(x%2) return a.F.S < b.F.S;
    return a.F.S > b.F.S;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

    ll tc; cin >> tc;
    while(tc--){
        FOR(i,0,1<<15) if(nb[i]) nb[i]=1 , del(i);

        ll n,q; cin >> n >> q;
        FOR(i,1,n) cin >> a[i];
        block = sqrt(n);

        FOR(i,1,q){
            ll x,l,r; cin >> x >> l >> r;
            qu[i] = mp(mp(l,r),mp(x,i));
        }
        sort(qu+1,qu+q+1,cmp);

        ll cl = qu[1].F.F , cr=qu[1].F.S;
        FOR(i,cl,cr) add(a[i]);
        ans[qu[1].S.S] = query(qu[1].S.F);

        FOR(i,2,q){
            ll l = qu[i].F.F , r=qu[i].F.S;

            while(cl > l) --cl , add(a[cl]);
            while(cr < r) ++cr , add(a[cr]);
            while(cl < l) del(a[cl]) , ++cl;
            while(cr > r) del(a[cr]) , --cr;
            

            ans[qu[i].S.S] = query(qu[i].S.F);
        }

        FOR(i,1,q) cout << ans[i] << endl;
    }

    return 0;
}

