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
* Each time I fix a length "len" so I'll allow only numbers with occurences "len" or "len"-1(to satisfy the first condition).
* Then, while this length gives me a better answer, I increment "len" compute the longest possible subsequence that verifies the second
* condition, using a dp[n][2^8] approach.dp[i][mask] represents the longest desired subsequence in array a[1..i] if only the numbers
* present in "mask" were taken(each one either "len" or "len"-1 times).
* 
* So at each index i.If a[i] is present in "mask" then I have to ignore it, else either I ignore it or take it.If I take it, I either take
* the first "len"-1 or the first "len" occurences of it starting from i.That's what the "f" function is for(dp2 is just for memoizing
* every possible result of the f function).
* 
* Thus the complexity will be O(max(len) * n * 2^8 + n*log(n)).
* len will not bypass n/8 which can reach 125, so that's 3,2 * 1e7 operations in the worst case.It would've been O(max(len)*n*2^8*log(n))
* if it wasn't for the memoization(the dp2 array), which is also passed in 1.5 seconds compared to 0.187 seconds for the first complexity.
* 
* Editorial: http://codeforces.com/blog/entry/49049
* 
* We can binary search for the best "len" (because if there's a sequence with positive length using a fixed "len") then there's also one
* for every "len"-1 , "len"-2 etc..
* The complexity becomes O(log(len) * n * 2^8 + n*log(n)).
*/

ll n,a[1000];
vector<ll> nb[8];
ll len;

ll dp[1000][256];

ll f(vector<ll>&t,ll& x){
   ll i=0,j=t.size();
   while(i<=j){
      ll mid=(i+j)/2;
      if(t[mid]==x) return mid;
      if(t[mid]>x) j=mid-1;
      else i=mid+1;
   }
}

ll solve(ll i,ll mask){
   if(i==n) return (len!=1 && mask!=255) ? -1000 : 0;

   ll& ans=dp[i][mask];
   if(ans != -1) return ans;

   ans = solve(i+1,mask);
   if((mask&(1<<a[i])) == 0){
      ll ind = f(nb[a[i]],i);
      if(len==1) ans = max(ans,solve(i+1,mask + (1<<a[i])));
      for(ll j=max(1ll,len-1);ind+j-1<nb[a[i]].size();++j) ans = max(ans,min(j,len) + solve(nb[a[i]][ind+j-1]+1,mask + (1<<a[i])));
   }

   return ans;
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   cin >> n;
   for(int i=0;i<n;++i) cin >> a[i] , --a[i] , nb[a[i]].pb(i);

   ll ans=0;
   memset(dp,-1,sizeof(dp));

   len = 1;
   while(solve(0,0)>ans){
      ans = solve(0,0);
      ++len;
      memset(dp,-1,sizeof(dp));
   }

   cout << ans << endl;

	return 0;
}
