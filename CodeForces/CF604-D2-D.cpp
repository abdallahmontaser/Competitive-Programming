/**
* Editorial: https://codeforces.com/blog/entry/21885
*/
#include <bits/stdc++.h>
#define ULL unsigned long long
#define ll(x) ((long long)x)
#define LL long long
#define LD long double
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define loop(i,a,b) for(int i=a;i<=b;++i)
#define pool(i,a,b) for(int i=a;i>=b;--i)
using namespace std; const int N = 1000000 + 5, LOG = 17 + 1, MOD = 1000000007;

vector<int> g[N]; int vis[N];

void dfs(int i){
	vis[i]=1;
	for(int j: g[i]) if(!vis[j]) dfs(j);
}
int pow(int x, int n){
	if(n==0) return 1;
	int y=pow(x, n/2);
	y = ll(y*y)%MOD; if(n&1) y=ll(y*x)%MOD;
	return y;
}

signed main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int p,k; cin>>p>>k;
	if(k<=1){ cout<<pow(p,p-(k==0))<<'\n'; return 0; }
	loop(i,1,p-1) g[ll(i*k)%p].push_back(i);
	int nb=0;
	loop(i,1,p-1) if(!vis[i]) ++nb, dfs(i);
	cout<<pow(p,nb)<<'\n';

}
