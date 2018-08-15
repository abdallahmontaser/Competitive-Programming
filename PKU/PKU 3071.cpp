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
#define EPS 1e-9
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
* Draw the figure of the standard football standings i.e. a perfect binary tree rotated 90 degrees clockwise.
* For each "node" of this tree we need to calculate the probability of every team reaching it.Of course the tree is imaginary, we won't implement it.
* In every node i in the first level(left) the probability that the i_th team gets there is 1, and of all others is 0.
* Now when you have the probabilities for two "nodes" and we want to calculate those of their "parent"(binary tree terms) we will do it like this;
* for every team 1 <= i <= 2^n , start off at 0, and add all the probabilities Xij which represent the probability that team i will beat team j
* and arrive at that node.
* 
* Xij = (probability of team i reaching first node) * (probability of team j reaching second node) * p[i][j]
* Do this for all the teams twice(second time, inverse first node and second node - see lines 67 and 68).
*/

ld p[130][130];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

    ll n;
    while(cin >> n && n != -1){
        ll m = 1<<n;
        FOR(i,0,m-1) FOR(j,0,m-1) cin >> p[i][j];

        vector<vector<ld> >v(m,vector<ld>(m));
        FOR(i,0,v.size()-1) FOR(j,0,v[i].size()-1) v[i][j] = (i == j) ? (ld)1 : (ld)0;

        while(n--){
            vector<vector<ld> >t_v(1<<n,vector<ld>(m));

            FOR(i,0,v.size()-1){
                FOR(a,0,m-1) FOR(b,0,m-1){
                    t_v[i>>1][a] += v[i][a] * v[i+1][b] * p[a][b];
                    t_v[i>>1][b] += v[i][a] * v[i+1][b] * p[b][a];
                }
                ++i;
            }

            v.assign(t_v.begin(),t_v.end());
        }

        ll winner = 0;
        FOR(i,1,m-1) if(v[0][i] > v[0][winner]) winner = i;

        cout << winner + 1 << endl;
    }

    return 0;
}

