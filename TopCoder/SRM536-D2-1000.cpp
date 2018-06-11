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
     for(ll ii=i+k-2;ii<n;++ii){
        ll pp=p*(ii-i+2-(ii==n-1));
        ans=max(ans,(double)(sum(v,i,ii)/pp)+solve(v,n,ii+1,pp,k));
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
