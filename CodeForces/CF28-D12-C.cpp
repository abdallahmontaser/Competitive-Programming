/**
* Editorial: https://codeforces.com/blog/entry/676
*/
#include <bits/stdc++.h>
#define ULL unsigned long long
#define LL long long
#define LD long double
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define loop(i,a,b) for(int i=a;i<=b;++i)
#define pool(i,a,b) for(int i=a;i>=b;--i)
using namespace std; const int N = 50 + 5, LOG = 17 + 1;

int n,m,a[N]; LD C[N][N]; LD dp[N][N][N], p1[N][N], p2[N][N];

LD solve(int i, int j, int k){
	if(j==0) return k;
	LD& ans=dp[i][j][k]; if(ans!=(LD)-1) return ans;
	ans=0;
	loop(x,0,i)
    if(j!=1 || x==i)
		  ans += p1[j][x]*p2[j][i-x]*C[i][x]*solve(i-x, j-1, max(k,(x+a[j]-1)/a[j]));
	return ans;
}

signed main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//<>
	cin>>n>>m;
	loop(i,1,m)cin>>a[i];
	loop(j,1,50){
		p1[j][0]=1; loop(nb,1,50) p1[j][nb]=1./(LD)j * p1[j][nb-1];
		p2[j][0]=1; loop(nb,1,50) p2[j][nb]=((LD)(j-1)/(LD)j) * p2[j][nb-1];
	}
	loop(i,0,50){
		C[i][0]=1;
		loop(j,1,i) C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	loop(i,0,50) loop(j,0,50) loop(k,0,50) dp[i][j][k]=-1;
	cout<<fixed<<setprecision(20)<<solve(n,m,0)<<'\n';

}
