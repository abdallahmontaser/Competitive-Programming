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
* a state that I'm in the process of answering. (Line 46)
* 
* If you run out of charges, the optimal answer will be to find the shortest path from the current node to N, that's what the "dist" array
* is for(calculated using the Floyd-Warshall algorithm). (Line 42)
*
* If you're currently at node N, then the answer for your current state will not be bigger than 0, because you can just stop there. (Line 49)
*/

ll n;
vector<pair<ll,ll> >g[50];
ll dp[50][50][1001] , done[50][50][1001];
ll dist[50][50];

void floyd(){
   for(int i=0;i<n;++i) for(int j=0;j<n;++j) if(i!=j) dist[i][j]=1e9;

   for(int i=0;i<n;++i) foreach(it,g[i]) dist[i][it->first] = min(dist[i][it->first],it->second);

   for(int i=0;i<n;++i) for(int j=0;j<n;++j) for(int k=0;k<n;++k) dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
}

ll solve(ll i,ll p,ll ch){
   if(!ch) return dist[i][n-1];

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

      floyd();

      return solve(0,0,charges);
   };
};
