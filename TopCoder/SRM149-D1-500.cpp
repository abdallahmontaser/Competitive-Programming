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
* dp[i] = number of different ways we can divide the string s[i..n] giving that the string s[1..i-1] is divided.
* If there's one correct division, the vector v will store the ending position of each portion of the string "message", which will
* help us print our answer(as shown in the loop in the restore function).
*/

map<string,bool>m;
vector<ll>v;

ll dp[51];

ll solve(string s,ll i){
   if(i==s.size()) return 1;

   ll& ans=dp[i];
   if(ans!=-1) return ans;

   ans=0;
   for(int j=i;j<s.size();++j){
      string ss(s.begin()+i,s.begin()+j+1);
      if(m[ss]&&solve(s,j+1)) v.pb(j),++ans;
   }

   return ans;
}

class MessageMess{
   public: string restore(vector <string> dictionary, string message){
      memset(dp,-1,sizeof(dp));
      for(int i=0;i!=dictionary.size();++i) m[dictionary[i]]=1;

      v.pb(-1);
      solve(message,0);

      if(dp[0] == 0) return "IMPOSSIBLE!";
      if(dp[0] >= 2) return "AMBIGUOUS!";

      string s="";
      for(int i=1;i<v.size();++i){
         string ss(message.begin()+v[i-1]+1,message.begin()+v[i]+1);
         s+=ss;
         if(i!=v.size()-1) s.append(" ",1u);
      }

      return s;
   }
};
