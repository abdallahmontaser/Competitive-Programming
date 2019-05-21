/**
* Explained solution: https://github.com/AliOsm/CompetitiveProgramming/blob/master/UVA/11997%20-%20K%20Smallest%20Sums.cpp
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
struct X{
	int val , p;
	bool operator<(const X &b) const{
		return val > b.val;
	}
};
int n , a[755][755];
void f(int ind){
	priority_queue<X> pq;
	for(int i=0; i<n; ++i) pq.push({a[0][i]+a[ind][0] , 0});
	for(int cnt=0; cnt<n; ++cnt){
		X x = pq.top(); pq.pop();
		a[0][cnt] = x.val;
		if(x.p + 1 < n) pq.push({x.val-a[ind][x.p]+a[ind][x.p + 1] , x.p + 1});
	}
}
signed main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while(cin >> n){
		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j) cin >> a[i][j];
			sort(a[i], a[i]+n);
		}
		for(int i=1; i<n; ++i) f(i);

		for(int i=0; i<n; ++i) cout << a[0][i] << ((i==n-1)?'\n':' ');
	}
return 0;
}
