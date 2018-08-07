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
* Solution using trie.
* This is the same as the editorial: http://codeforces.com/blog/entry/54179
*/

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

ll pow(ll n){
    if(!n) return 1;
    ll x=pow(n/2);
    x*=x;
    if(n%2) x*=2;
    return x;
}

ll flip[19];
map<ll,ll>exist;

void add(ll x){
    node* c = root;
    ++c->n;
    ROF(i,18,0){
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

ll mex(){
    node *c = root;
    ll ans=0;

    ROF(i,18,0){
        if(flip[i] % 2){
            if(c->o == NULL) return ans;
            else if(c->z == NULL){
                if(c->o->n == pow(i)) return ans+(1<<i);
                else c=c->o;
            }
            else{
                if(c->o->n == pow(i)) c=c->z , ans+=(1<<i);
                else c=c->o;
            }

        }
        else{
            if(c->z == NULL) return ans;
            else if(c->o == NULL){
                if(c->z->n == pow(i)) return ans+(1<<i);
                else c=c->z;
            }
            else{
                if(c->z->n == pow(i)) c=c->o , ans+=(1<<i);
                else c=c->z;
            }
        }

    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll n,m; cin>>n>>m;
    while(n--){
        ll x; cin>>x;
        if(exist[x]) continue;
        exist[x]=1;
        add(x);
    }

    while(m--){
        ll x; cin>>x;
        FOR(i,0,18) if(x&(1<<i)) ++flip[i];
        cout<<mex()<<endl;
    }

    return 0;
}

