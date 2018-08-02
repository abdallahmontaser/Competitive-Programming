#include<bits/stdc++.h>
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
* Go through all the possible combinations of rows and columns, and find out in each case the minimum number of flips needed to make them palindrome
* and return the minimum answer for all combinations that have enough number of rows and columns.
* Observe that for some given rows and columns(part of the matrix), you can divide the cells into groups of at most 4 whose final state(0 or 1) will only
* will be the same and will only depend of each others' current states.Let me explain, consider this matrix where n=4 and m=4;
* 
* 1 0 0 0
* 0 0 1 1
* 0 1 1 0
* 1 0 1 0
* 
* And consider the case where we need to make row 1 and columns 1 and 3 palindrome, so the part of the matrix we need now is:
* 
* 1 0 0 0
* 0 . 1 .
* 0 . 1 .
* 1 . 1 .
* 
* For example cells (0,0), (0,3), (3,0) are in one group and cells (0,1), (0,2) and (2,2) are together in another group.
* Find out all the groups and for each one compute the minimum number of operations needed to make all cells in it equal, then add up.
* 
* Complexity - O(N * M * 2^(N+M))
*/

ll nr,nc;

ll solve(vector<string>&A){
   ll ans=1e9;
   ll n=A.size(),m=A[0].size();

   FOR(mask,0,(1<<(n+m))-1){
      ll t1=0; FOR(x,0,n-1) if(mask&(1<<x)) ++t1;
      ll t2=0; FOR(x,0,m-1) if(mask&(1<<(x+n))) ++t2;
      if(t1<nr || t2<nc) continue;

      set<set<pair<ll,ll> > >s;
      FOR(i,0,n-1) FOR(j,0,m-1){
         bool a=mask&(1<<i) , b=mask&(1<<(n-1-i)) , c=mask&(1<<(n+j)) , d=mask&(1<<(n+m-1-j));
         if(!a && !c) continue;

         set<pair<ll,ll> >ss;
		
         ss.insert(mp(i,j));
         if(a || (c&&b&&d)) ss.insert(mp(i,m-1-j));
         if(c || (a&&d&&b)) ss.insert(mp(n-1-i,j));
        
         if((!a&&!b) || (!c&&!d)){
			s.insert(ss);
			continue;
		}
		
         if(a+b+c+d>=3 || (a+b+c+d==2 && (!a || !c))) ss.insert(mp(n-1-i,m-1-j));

         s.insert(ss);
      }

      ll tmp_ans=0;
      foreach(i,s){
         ll tmp_n=0;
         foreach(j,*i) if(A[j->first][j->second] == '0') ++tmp_n;
         tmp_ans += min(tmp_n,(ll)(*i).size()-tmp_n);
      }

      ans = min(ans,tmp_ans);
   }

   return ans;
}

class PalindromeMatrixDiv2{
   public: int minChange(vector <string> A, int rowCount, int columnCount){
      nr=rowCount , nc=columnCount;

      return solve(A);
   }
};
