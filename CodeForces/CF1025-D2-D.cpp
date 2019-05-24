/**
* Not that hard, but many didn't code O(n^3) fearing it won't pass, it passed with ease.(memory must be o(n²) though)
* More details in the editorial and comments: https://codeforces.com/blog/entry/61323
*/
#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
using namespace std;

int n, a[705], g[705][705], dp[705][705][2];
int possible(int i, int j, bool k){
	if(i>j) return 1;
	int &ans=dp[i][j][k];
	if(ans != -1) return ans;

	int prev = ((k==0)?i-1:j+1);
	for(int cnt=i; cnt<=j; ++cnt)
		if(g[prev][cnt] && possible(i,cnt-1,1) && possible(cnt+1,j,0))
			return ans=1;
	return ans=0;
}

signed main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; ++i) cin>>a[i];
	for(int i=0; i<=n; ++i) for(int j=1; j<=n; ++j)
		g[i][j]=(__gcd(a[i],a[j]) > 1);
	for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) for(int k:{0,1})
		dp[i][j][k]=-1;
	if(possible(1,n,0)) cout<<"Yes\n";
	else cout<<"No\n";
 
return 0;
}
