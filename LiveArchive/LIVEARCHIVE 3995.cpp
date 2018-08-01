#include<bits/stdc++.h>
#define MOD 1000000007
#define EPS 1e-15
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define endl '\n'
#define foreach(it,x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define FOR(i,a,b) for(ll i=(ll)a;i<=(ll)b;++i)
#define FOR_(i,a,b,c) for(ll i=(ll)a;i<=(ll)b;i+=(ll)c)
const ld PI=3.141592653589793238L;
const ll N=100005;
using namespace std;

/**
* Solved by dp and bitmasks.
* You traverse the board row by row, going from column 0 to n-1 in each row while keeping the mask that represents what cells were chosen
* in the previous row.
* In the same time, you need to change this mask with the cells you put in the current row so when you finish all n-1 columns and move to the next row
* the mask you currently have will represent the chosen cells in your current row. How?
* When you're on state (i,j,mask), the first part of your current mask from 0 to j-1 will represent the current row, and the other part
* will represent the previous row.At each column j, you update the jth bit in your mask according to the CURRENT row, and continue.
*
* But you will need to keep track if the cell (i-1,j-1) has been chosen or not and the (j-1)th bit has been changed to represent (i,j-1) now .. ?
* That's what the boolean d is for.
*/

ll n;
ll dp[15][15][2][1<<15];
vector<vector<ll> >v;

ll solve(ll i,ll j,bool d,ll mask){
   if(j==n) return solve(i+1,0,0,mask); // row i is completed, start over from row i+1
   if(i==n) return 0; // last row completed; we're done.

   ll&ans=dp[i][j][d][mask];
   if(ans != -1) return ans;

   if( (j && (mask&1<<(j-1))) || d || (mask&(1<<j)) || (mask&(1<<(j+1))) ) // : if respectively one of (i,j-1) or (i-1,j-1) or (i-1,j) or (i-1,j+1) is occupied
      // then we can't choose cell (i,j)
      return ans = solve(i,j+1,(mask&(1<<j))>0,mask&(~(1<<j)));
   
   // else we ty either to choose it or not
   return ans = max(v[i][j]+solve(i,j+1,0,mask|(1<<j)) , solve(i,j+1,0,mask));
} 

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   string s;
   while(getline(cin,s)){
      v.clear();
      do{
         if(s.empty()) break;
         vector<ll>tmp_v;
         ll x;
         istringstream iss(s);
         while(iss>>x) tmp_v.pb(x);
         v.pb(tmp_v);
      }while(getline(cin,s));

      n=v.size();
      memset(dp,-1,sizeof(dp));

      cout<<solve(0,0,0,0)<<endl;
   }

   return 0;
}
