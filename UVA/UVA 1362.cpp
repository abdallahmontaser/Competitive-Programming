#include<bits/stdc++.h>
#define MOD 1000000000
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
* Not AC yet.
* My problem is, for example, with "AAAAAAAAA".My program divides it like this: "A A A A A A A A A" but you can divide it like this:
* "A AAA A AAA A".
*/

string s;
pair<ll,ll> dp[300][300];

ll power(int p){
   if(!p) return 1ll;
   ll x=power(p/2);
   x=(x*x)%MOD;
   if(p%2) x=(2*x)%MOD;
   return x;
}

pair<ll,ll> solve(ll i,ll j){
   if(s[i]!=s[j]) return mp(0,0);
   if(j==i+1) return mp(0,0);
   if(j<=i+2) return mp(1,1);

   pair<ll,ll>& ans=dp[i][j];
   if(ans.first != -1) return ans;

   vector<ll>v; v.pb(i);
   for(int k=i+1;k<=j;++k) if(s[k]==s[i] && k!=v[v.size()-1]+1 && k!=j-1) v.pb(k);

   ans = solve(i+1,j-1);
   if(!ans.second) return mp(0,0);
   for(int n=v.size()-2,p=0 ; n > 0 ; --n,++p){
      ll tmp = ( (solve(i+1,v[n]-1).first * solve(v[n]+1,j-1).first)%MOD * power(p))%MOD;
      if(!solve(i+1,v[n]-1).second || !solve(i+1,v[n]-1).second) return mp(0,0);
      ans.first=(ans.first+tmp)%MOD;
   }

   return ans;
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>
   
   while(cin >> s){
      for(int i=0;i<300;++i) for(int j=0;j<300;++j) dp[i][j]=mp(-1,-1);
      cout << solve(0,s.size()-1).first << endl;
   }

   return 0;

}
