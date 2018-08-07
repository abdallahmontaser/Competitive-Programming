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
* Used trie to solve it.
* This is the same solution as the editorial: http://codeforces.com/blog/entry/46510
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

void add(ll x){
    node* c = root;
    ++c->n;
    ROF(i,29,0){
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
    node *c = root , *prv;
    --c->n;
    ROF(i,29,0){
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
    ROF(i,29,0){
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

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    add(0);
    ll q; cin>>q;
    while(q--){
        string ch; ll x;
        cin>>ch>>x;
        if(ch == "+") add(x);
        if(ch == "-") del(x);
        if(ch == "?") cout<<query(x)<<endl;
    }

    return 0;
}

