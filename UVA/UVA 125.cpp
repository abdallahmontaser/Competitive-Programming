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
* I basically just loop over all pairs of intersections, and for each pair (i,j), I suppose the graph is acyclic(I ignore any cycle I find)
* and store the number of paths from i to j.Then, I go through all the intersections that have a path to j(the ones having a positive dp value),
* and check if they are part of a cycle.If there's one, then the answer for (i,j) is -1.Else it's dp[i].
* This is a O(N^4) solution.
* 
* Better solution in O(N^3): https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/UVA/UVA_125.txt
*/

ll n,m;
vector<ll>graph[30];
ll dp[30],vis[30];

ll solve(ll i,ll j){
   if(i==j) vis[i]=1 , dp[i]=1;

   if(vis[i]){
      if(dp[i]==-1) return 0;
      return dp[i];
   }
   vis[i]=1;

   ll ans=0;
   foreach(it,graph[i]) ans+=solve(*it,j);

   return dp[i]=ans;
}

bool f(ll i,ll j,bool first){
   if(i==j && !first) return 1;
   if(!vis[i]){
      vis[i]=1;
      foreach(it,graph[i]) if(f(*it,j,0)) return 1;
   }

   return 0;
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll tc = -1;
   while(cin >> m){
      ++tc;
      n=0;
      for(int i=0;i<30;++i) graph[i].clear();

      for(int i=0;i!=m;++i){
         ll x,y; cin >> x >> y;
         graph[x].pb(y);
         n=max(n,max(x,y));
      }

      ++n;

      cout << "matrix for city " << tc << endl;
      for(int i=0;i<n;++i) for(int j=0;j<n;++j){
         memset(dp,-1,sizeof(dp));
         memset(vis,0,sizeof(vis));

         ll ans;
         if(i==j){
            if(f(i,i,1)) ans=-1;
            else ans=0;
         }
         else ans=solve(i,j);
         
         for(int k=0;k<n;++k){
            memset(vis,0,sizeof(vis));
            if(dp[k] > 0 && f(k,k,1)) ans=-1;
         }

         cout << ans;
         if(j==n-1) cout << endl;
         else cout << " ";
      }
   }

   return 0;

}
