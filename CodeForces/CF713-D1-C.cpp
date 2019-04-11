/**
* Badly explained editorial: https://codeforces.com/blog/entry/47094
* Good editorial of old (near exact) problem: https://codeforces.com/blog/entry/364
*/
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
#define ll long long
#define ld long double
#define all(x) x.begin(),x.end()
#define int long long
using namespace std;
int n;
int a[3012] , b[3012] , dp[3012][3012];
ll solve(int i , int j){
      ll& ans = dp[i][j];
      if(ans != -1) return ans;

      if(i == 1 && j == 1) return  ans = abs(a[i] - b[j]);
      if(i == 1) return ans = min(abs(a[i] - b[j]) , solve(i , j - 1));
      if(j == 1) return ans = abs(a[i] - b[j]) + solve(i - 1 , j);
      return ans = min(solve(i , j - 1) , abs(a[i] - b[j]) + solve(i - 1 , j));
}
int32_t main(){
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      cin >> n;
      for(int i = 1; i <= n; ++i) cin >> a[i] , a[i] -= i , b[i] = a[i];
      sort(b + 1 , b + n + 1);
      memset(dp,-1,sizeof(dp));
      cout << solve(n , n) << '\n';
      return 0;
}
