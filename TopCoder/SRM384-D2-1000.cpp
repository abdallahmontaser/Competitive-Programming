#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <iterator>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#include <limits>
#include <math.h>
#include <stdio.h>
#include <string.h>
#define MOD 1000000007
#define EPS 1e-15
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define endl '\n'
#define foreach(it,x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define FOR(i,a,b) for(ll i=(ll)a;i<=(ll)b;++i)
#define FOR_(i,a,b,c) for(ll i=(ll)a;i<=(ll)b;i+=(ll)c)
const ld PI=3.141592653589793238L;
const ll N=100005;
using namespace std;

/**
* I believe the comments in the code are enough to understand.
* 
* Just one thing;
* if Alan can't win in some pile, the "minimum number of turns for him to win in that pile" will be equal to 1e9(dummy value) a.k.a. infinity.
*/

ll f[10005]; // f[x] is sqrt(x) rounded
ll dp1[10005] , dp2[10005];

ll solve1(ll x){ // Suppose Alan can win in the pile with x sticks - return minimum number of turns to win
   if(x==0) return 1e9;
   if(x==1) return 1;

   ll& ans=dp1[x];
   if(ans != -1) return ans;

   ans=1e9;
   FOR(i,1,f[x]){
      ll tmp=0;
      FOR(j,1,f[x-i*i]) tmp=max(tmp,1+solve1(x-i*i-j*j));
      ans=min(ans,1+tmp);
   }

   return ans;
}

ll solve2(ll x){ // Suppose Alan is guaranteed to lose in the pile with x sticks - return maximum number of turns before losing
   if(x==0) return 0;

   ll& ans=dp2[x];
   if(ans != -1) return ans;

   ans=0;
   FOR(i,1,f[x]){
      ll tmp=1e9;
      FOR(j,1,f[x-i*i]) tmp=min(tmp,1+solve2(x-i*i-j*j));
      ans=max(ans,1+tmp);
   }

   ans=min(ans,(ll)1e9);
   return ans;
}

class PowerGame{
   public: string winner(int size0, int size1){
      ll a=size0 , b=size1;
      ll curr=0;
      FOR(i,0,10000){
         if(i==curr*curr) f[i]=curr++;
         else f[i]=f[i-1];
      }

      memset(dp1,-1,sizeof(dp1));
      memset(dp2,-1,sizeof(dp2));
      ll n1=1e9 , n2=1e9;

      if(solve1(a) == 1e9) n2=solve2(a); // There is no way Alan can win in the first pile, so he delays it as much as possible
      else n1=solve1(a); // He can win in the first pile, so he tries to win as soon as possible

      if(solve1(b) == 1e9) n2=min(n2,solve2(b)); // There is no way Alan can win in the second pile, so he delays it as much as possible
      else n1=min(n1,solve1(b)); // He can win in the second pile, so he tries to win as soon as possible

      string s1;
      if(n1 < n2) s1 = "Alan will win after ";
      else s1 = "Bob will win after ";
      ostringstream oss;
      oss<<min(n1,n2);
      string s2=oss.str();
      string s3=" moves";

      return s1+s2+s3;
   };
};
