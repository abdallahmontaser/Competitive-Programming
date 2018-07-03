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
* It's not hard to see that the answer is the maximum number of sets such that their intersection is empty and for each set,
* the nodes in it and their numbers are all the nodes of the graph.
* First we find all these possible sets(one at a time).Cover[mask]=1 if mask verifies the above.
*
* Then, using dp(in the solve function) we compute the maximum number of disjoint sets x such that cover[x]=1.
*/

bool cover[1<<16];
ll dp[1<<16];

ll solve(ll mask){
   if(!mask) return 0;

   ll&ans=dp[mask];
   if(ans!=-1) return ans;

   ans=0;
   for(int i=mask;i>0;i=(i-1)&mask) if(cover[i]) ans=max(ans,1+solve(mask&~i));

   return ans;
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll n; cin >> n;
   ll tc=0;
   while(n){
      cout << "Case " << ++tc << ": ";
      memset(cover,0,sizeof(cover));
      memset(dp,-1,sizeof(dp));

      vector<ll>neighbour[n];
      for(int i=0;i<n;++i){
         ll m; cin >> m;
         while(m--){ll x; cin >> x; neighbour[i].pb(x);}
      }

      for(int mask=0;mask<(1<<n);++mask){
         set<ll>s;
         for(int i=0;i<n;++i) if(mask&(1<<i)){
            s.insert(i);
            foreach(j,neighbour[i]) s.insert(*j);
         }
         if(s.size()==n) cover[mask]=1;
      }

      cout << solve((1<<n)-1) << endl;

      cin >> n;
   }

	return 0;
}
