/**
* Editorial: https://codeforces.com/blog/entry/23278
* Essentially the same solution as mine, but instead of doing DP in the second part I constructed prefix and suffix
* arrays to find the best total cost.
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

int n,x,y , a[1000123] , prime[50123];
LL pref[1000123],suff[1000123];

void fill(int x, set<int>& st){
	int tmp=x;
	for(int i=2; i*i<=tmp; ++i) if(x%i==0 && prime[i]){
		while(x % i == 0) x/=i;
		st.insert(i);
	}
	if(x!=1) st.insert(x);
}

signed main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	const LL INF = (LL)1e18;
	for(int i=2; i<=50000; ++i) prime[i]=1;
	for(int i=2; i<=50000; ++i) if(prime[i])
		for(int j=i+i; j<=50000; j+=i) prime[j]=0;
	
	cin>>n>>x>>y;
	for(int i=1; i<=n; ++i) cin>>a[i];

	set<int> st;
	for(int tmp=-1; tmp<=1; ++tmp) fill(a[1]+tmp, st), fill(a[n]+tmp, st);
	vector<int> pr(all(st));

	LL ans = INF;
	for(int t: pr){
		pref[0]=0;
		for(int i=1; i<=n; ++i){
			if(a[i]%t == 0) pref[i] = pref[i-1] - x;
			else if(((a[i]-1)%t == 0) || ((a[i]+1)%t == 0)) pref[i] = pref[i-1] + y - x;
			else pref[i] = INF;
		}
		for(int i=1; i<=n; ++i) pref[i] = min(pref[i] , pref[i-1]);

		suff[n+1]=(LL)x*n;
		for(int i=n; i>=1; --i){
			if(a[i]%t == 0) suff[i] = suff[i+1] - x;
			else if(((a[i]-1)%t == 0) || ((a[i]+1)%t == 0)) suff[i] = suff[i+1] + y - x;
			else suff[i] = INF;
		}
		for(int i=n; i>=1; --i) suff[i] = min(suff[i] , suff[i+1]);
		
		for(int i=0; i<=n; ++i)
			ans = min(ans, pref[i]+suff[i+1]);
	}
	cout<<ans<<'\n';

return 0;
}
