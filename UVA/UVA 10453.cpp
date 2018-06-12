#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define endl '\n'
const ld PI =  3.141592653589793238L;
const ll N=100002;
using namespace std;

/**
* The "solve" function is the regular O(n^2) edit distance dp.
* Then, in the "solve2" function, I start again at (0,0) and at each time check which step gave me the optimal answer(which is dp[0][0]),
* and follow it.
*/

string s;
vector<ll>v;
bool mid;
ll dp[1000][1000];

ll solve(ll i,ll j){
   if(i>=j) return 0;

   ll& ans=dp[i][j];
   if(ans!=-1) return ans;

   if(s[i]==s[j]) ans = solve(i+1,j-1);
   else ans = 1+min(solve(i+1,j),solve(i,j-1));

   return ans;
}

void solve2(ll i,ll j){
   if(i==j) v.pb(i),mid=1;
   if(i>=j) return;

   if(s[i]==s[j]) v.pb(i),solve2(i+1,j-1);
   else if(solve(i,j)==1+solve(i+1,j)) v.pb(i),solve2(i+1,j);
   else{
      v.pb(j);
      solve2(i,j-1);
   }
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   while(cin >> s){
      memset(dp,-1,sizeof(dp));
      v.clear();
      mid=0;

      ll ans=solve(0,s.size()-1);

      solve2(0,s.size()-1);

      cout << ans << ' ';
      for(int i=0;i<v.size();++i) cout << s[v[i]];
      for(int i=v.size()-1-mid;i>=0;--i) cout << s[v[i]];
      cout << endl;
   }

   return 0;

}
