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
*My approach was dp+memoization.I sorted the array in increasing order and begin looping from the start.
*At each index i: I loop from j=i+k-2 to j=n-1,
*and each time I compute the result of merging the j-i+1(from i to j) companies with the rest which is one company; the result of merging all the remaining companies
*i.e. companies from j+1 to n-1.Then I take the max and return it, also storing in the process the denominator.
*This works when I sort the array in this order because of the observation, that for any order chosen for the array, the final look of it after the merge
*will be in the form of consecutive groups of adjacent companies of size atleast k-1(last group must be of size >= k) divided by the product
*of the number of companies in it multiplied by the number of companies in each previous group.So the denominator gets bigger with every group,
*that's why the optimal answer will be in the case where the smallest numbers come in last, and the biggest in first.The only thing remaining
*is to figure out how many companies in each group; which is the job of the recursive dp function(solve).
*/

class MergersDivTwo{
	public:
	double dp[51][N];

  double sum(vector<double>v,ll l,ll r){
     double ans=0;
     for(int i=l;i!=r+1;++i) ans+=v[i];
     return ans;
  }

  double solve(vector<double>v,ll n,ll i,ll p,double k){
     if(i==n) return (double)0;
     if(n-i<k) return (double)-1e9;

     double& ans=dp[i][p];
     if(ans!=-1e10) return ans;

     ans=(double)-1e9;
     for(ll j=i+k-2;j<n;++j){
        ll pp=p*(j-i+2-(j==n-1));
        ans=max(ans,(double)(sum(v,i,j)/pp)+solve(v,n,j+1,pp,k));
     }

     return ans;
  }
  
  double findMaximum(vector <int> revenues, int k){
    for(int i=0;i!=51;++i) for(int j=0;j!=N;++j) dp[i][j]=(double)-1e10;
    vector<double>v(revenues.begin(),revenues.end());
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    return solve(v,v.size(),0,1ll,k);
  }
};
