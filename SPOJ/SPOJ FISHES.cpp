/**
* Explained idea here: https://github.com/tanmoy13/CompetitveProgramming/blob/master/Online-Judge-Solutions/SPOJ/FISHES%20-%20Finding%20Fishes.cpp
* This is O(r * c²) as well(using precalculation of tab[][][] to simplify the loops on the corners of the box),
* but O(r² * c²) will pass on SPOJ.
*/
#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define int long long
using namespace std;
int a[105][105] , v[505];
int prf[105][105] , tab[105][105][105];

signed main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tests; cin >> tests;
	for(int tc=1; tc<=tests; ++tc){
		cout<<"Case #"<<tc<<":\n";
		int r,c,h,k,t; cin>>r>>c>>h>>k>>t;
		for(int i=1; i<=r; ++i) for(int j=1; j<=c; ++j) cin>>a[i][j];
		int t_v[t+1][k+1] , t_x[t+1];
		for(int i=1; i<=t; ++i){
			cin>>t_x[i];
			for(int j=1; j<=k; ++j) cin>>t_v[i][j];
		}
		for(int j=1; j<=k; ++j){
			v[j]=0;
			for(int i=1; i<=t; ++i) v[j] += t_x[i]*t_v[i][j];
		}
		
		for(int i=1; i<=r; ++i)
		for(int j=1; j<=c; ++j)
			prf[i][j] = v[a[i][j]] + prf[i-1][j] + prf[i][j-1] - prf[i-1][j-1];

		for(int j1=0; j1<c; ++j1) for(int j2=j1+1; j2<=c; ++j2){
			tab[j1][j2][r] = prf[r][j2]-prf[r][j1];
			for(int i=r-1; i>=1; --i)
				tab[j1][j2][i] = max(prf[i][j2]-prf[i][j1] , tab[j1][j2][i+1]);
		}

		int ans=-2e18;
		for(int i1=0; i1<r; ++i1)
		for(int j1=0; j1<c; ++j1)
		for(int j2=j1+1; j2<=c; ++j2)
			ans = max(ans , tab[j1][j2][i1+1] - prf[i1][j2] + prf[i1][j1]);

		cout<<h+ans<<'\n';
	}
return 0;
}
