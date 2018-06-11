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

vector<string>v1,v2;

ll dp[1000][1000];

ll LCS(ll i,ll j){
   if(i==v1.size()||j==v2.size()) return 0;

   ll&ans=dp[i][j];
   if(ans!=-1) return ans;

   if(v1[i]==v2[j]) ans=1+LCS(i+1,j+1);
   else ans=max(LCS(i+1,j),LCS(i,j+1));

   return ans;
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   char ch1[1001],ch2[1001];

   ll tc=0;
   while(gets(ch1)){
      string s1(ch1);
      gets(ch2); string s2(ch2);
      v1.clear();
      v2.clear();

      ++tc;
      cout << setw(2) << setiosflags(ios::right) << tc << ". ";

      for(int i=0;i<s1.size();++i) if(!isalpha(ch1[i])&&!isdigit(ch1[i])) s1[i]=' ';
      for(int i=0;i<s2.size();++i) if(!isalpha(ch2[i])&&!isdigit(ch2[i])) s2[i]=' ';

      string tmp;

      istringstream iss1(s1);
      while(iss1 >> tmp) v1.pb(tmp);

      istringstream iss2(s2);
      while(iss2 >> tmp) v2.pb(tmp);

      if(!v1.size() || !v2.size()){
         cout << "Blank!\n";
         continue;
      }

      memset(dp,-1,sizeof(dp));

      cout << "Length of longest match: " << LCS(0,0) << endl;
   }

   return 0;

}
