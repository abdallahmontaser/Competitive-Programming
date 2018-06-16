#include<bits/stdc++.h>
#define MOD 1000000007
#define EPS 1e-9
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define endl '\n'
#define foreach(it,x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
const ld PI =  3.141592653589793238L;
const ll N=1000002;
using namespace std;

/**
* Used a top-down approach.See the formula below in the 'solve' function for calculating the answer for a range i..j of matrices.
*/

ll n;
pair<ll,ll> a[11];
ll dp[11][11];

ll solve(ll i,ll j){
   if(i==j) return 0ll;

   ll&ans=dp[i][j];
   if(ans != -1) return ans;

   ans=1e18;
   for(int k=i;k<j;++k) ans=min(ans,solve(i,k)+solve(k+1,j)+a[i].first*a[k].second*a[j].second);

   return ans;
}

string f2(ll x){
   stringstream ss;
   ss << x;
   return ss.str();
}

string f(ll i,ll j){
   if(i==j) return "A"+f2(i);

   for(int k=i;k<j;++k) if(solve(i,j) == solve(i,k)+solve(k+1,j)+a[i].first*a[k].second*a[j].second)
      return "(" + f(i,k) + " x " + f(k+1,j) + ")";
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll tc=0; cin >> n;
   while(n){
      for(int i=1;i<=n;++i) cin >> a[i].first >> a[i].second;
      memset(dp,-1,sizeof(dp));
      solve(1,n);
      cout << "Case " << ++tc << ": " << f(1,n) << endl;
      cin >> n;
   }

   return 0;

}
