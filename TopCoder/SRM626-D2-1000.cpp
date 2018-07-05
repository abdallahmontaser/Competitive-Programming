#include<bits/stdc++.h>
#define MOD 1000000007
#define EPS 1e-9
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define endl '\n'
#define foreach(it,x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
const ld PI=3.141592653589793238L;
const ll N=300002;
using namespace std;

/**
* dp[i][j][ch] = minimum distance from "i" to "j" with "ch" charges left.You can compute this by trying all possible outgoing edges
* from i and adding the corresponding edge length(depending on whether you use a charge or not).
* 
* Alone, this dp approach will time out because if you keep choosing to traverse edges while not using any charges, you will go back to
* states that you already started computing, that's why the "done" array is for; I just return a big(dummy) value whenever I encounter
* a state that I'm in the process of answering. (Line 32)
* 
* If you're currently at node N, then the answer for your current state will not be bigger than 0, because you can just stop there. (Line 35)
*/

ll n;
vector<pair<ll,ll> >g[50];
ll dp[50][50][1001] , done[50][50][1001];

ll solve(ll i,ll p,ll ch){
   ll &d=done[i][p][ch] , &ans=dp[i][p][ch];
   if(d==2) return ans;
   if(d==1) return 1e9;

   d=1;
   ans=(i!=n-1)*1e9;
   foreach(it,g[i]){
      ans = min(ans,it->second + solve(it->first,i,ch));
      if(ch) ans = min(ans,-it->second + solve(it->first,i,ch-1));
   }

   d=2;
   return ans;
}

class NegativeGraphDiv2{
   public: ll findMin(int N, vector <int> s, vector <int> t, vector <int> weight, int charges){
      n = N;
      for(int i=0;i<s.size();++i) g[s[i]-1].pb(mp(t[i]-1,weight[i]));

      return solve(0,0,charges);
   };
};
