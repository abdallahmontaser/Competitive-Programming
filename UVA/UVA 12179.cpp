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
#define FOR_(i,a,b) for(ll i=(ll)(a);i>=(ll)(b);--i)
const ld PI=3.141592653589793238L;
const ll N=100005;
using namespace std;
//   <<>>

/**
* The couple must always choose the shortest path between them, because any other longer path will increase the probability of getting
* a total cost > their budget.
* So compute the shortest distance between each pair (i,j) ; i!=j using BFS in O(n^2) or Floyd-Warshall in O(n^3).
* Then for each couple return the probability that the total cost of the journey(which is the shortest path between them) is <= their budget.
* 
* Let that be equal to p.
* p = (number of ways we can get a total cost <= their budget) / (number of ways of getting a total cost)
* 
* Let the numerator be equal to a and the denominator to b, and let the shortest distance between them be equal to d.
* b is obviously equal to R^d because in each step(edge) you choose one of R numbers(each with equal probability) and add it.
* a can be calculated using DP - dp[r][d][m] is the number of ways you can get a total cost <= m if there are d steps and you choose one of r numbers in each step.
* 
* But since m can reach 10000, this won't work.
* Unless you notice that the maximum value obtainable by summing d numbers is d*r, so if m > d*r you can set m = d*r.
* That will give us a dp array having maximum values in each dimention as follows: 30 , 99 , 2970
*
* a and b are both very large numbers, so you'll need to use double or long double.
* 
* In line 98 I'm dividing by b, but if my answer is <= 0.0009 then I'll stop because my answer will be considered correct by the problem checker(read the output section).
*/

ld dp[31][100][2971];
bool done[31][100][2971];
ld solve(ll r,ll d,ll m){
    if(d==0 && m>=0) return 1;
    if(d==0 || m<=0) return 0;

    ld&ans = dp[r][d][m];
    bool&dd = done[r][d][m];
    if(dd) return ans;

    ans=0;
    FOR(i,1,r) ans += solve(r,d-1,m-i);

    dd=1;
    return ans;
}

ll dist[101][101];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll tc; cin>>tc;
    FOR(t,1,tc){
        cout<<"Case "<<t<<endl;
        ll n,r; cin>>n>>r;

        FOR(i,1,n) FOR(j,1,n){
            char ch; cin>>ch;
            if(ch=='Y') dist[i][j]=1;
            else dist[i][j]=1e9;
        }

        FOR(k,1,n) FOR(i,1,n) FOR(j,1,n) dist[i][j] = min(dist[i][j] , dist[i][k]+dist[k][j]);

        ll c; cin>>c;
        while(c--){
            ll x,y,m; cin>>x>>y>>m;
            m = min(m,r*dist[x][y]);

            ld ans = solve(r,dist[x][y],m);

            ll nb=dist[x][y];
            while(nb-- && ans>0.0009) ans /= (ld)r;

            cout<<fixed<<setprecision(3)<<ans<<endl;
        }

        if(t!=tc) cout<<endl;
    }

    return 0;
}


