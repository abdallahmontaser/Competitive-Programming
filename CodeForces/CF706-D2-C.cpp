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
const ll N=100002;
using namespace std;

/**
* dp[i][0] = minimum cost for arranging the strings 1..i in a way that they are in ascending lexicographical order,
* and the i-th string isn't reversed.
* dp[i][1] = same, but when the i-th string is reversed.
*
* Editorial: 
*/

bool vis[2*N];
ll dp[2*N];

bool f(string&s1,string&s2){
   for(int i=0;i<min(s1.size(),s2.size());++i) if(s1[i]!=s2[i]) return s1[i] < s2[i];

   return s1.size() <= s2.size();
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll n; cin >> n;
   ll c[n];
   for(ll i=0;i<n;++i) cin >> c[i];

   vector<string>v;
   for(ll i=0;i<n;++i){
      string s; cin >> s;
      v.pb(s);
      reverse(s.begin(),s.end());
      v.pb(s);
   }

   *dp=0ll , dp[1]=c[0];
   for(int i=2;i<2*n;++i) dp[i] = 1e15;

   for(int i=2;i<2*n;++i) for(int j=2;j!=0;--j) if(f(v[i-j-i%2],v[i])) dp[i]=min(dp[i],dp[i-j-i%2]+(i%2)*c[i/2]);

   ll ans = min(dp[2*n-2],dp[2*n-1]);
   if(ans>=1e15) ans = -1;

   cout << ans << endl;

   return 0;

}
