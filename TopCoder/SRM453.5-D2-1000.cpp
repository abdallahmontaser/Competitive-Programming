/**
* Editorial: https://apps.topcoder.com/wiki/display/tc/SRM+453.5
* 
* Basic dynamic programming.
* dp[0][A][B][C] = the minimum product you can get if you're at position B, the last chosen element is A, and there are C choices left.
* dp[1][A][B][C] = the maximum product ...
* I've added the first boolean dimension to ease writing the functions, and to make generalised functions to handle min/max operations
* like the f() function. The g() function handles overflows.
*/
#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define loop(i,a,b) for(int i=a;i<=b;++i)
#define pool(i,a,b) for(int i=a;i>=b;--i)
using namespace std; const int N=50;
int n,d;
LL dp[2][N+1][N+1][11];
bool done[2][N+1][N+1][11];
const LL inf[2] = {1e18L, -1e18L};

LL f(bool mx, LL a, LL b){ return ((mx==1) ? max(a,b) : min(a,b)); }
LL g(bool mx, LL a, LL b){
	if(log(fabs(a))+log(fabs(b)) > log(inf[0])) return inf[mx];
	return a*b;
}
LL solve(vector<int>& v, bool mx, int prv, int cur, int left){
	if(!left) return 1;
	if(cur==n || cur-prv > d) return inf[mx];
	LL& ans = dp[mx][prv][cur][left];
	if(done[mx][prv][cur][left]) return ans;
	
	ans=inf[mx];
	if(v[cur] > 0) ans = f(mx, ans, g(mx, v[cur], solve(v,mx,cur,cur+1,left-1)));
	if(v[cur] < 0) ans = f(mx, ans, g(mx, v[cur], solve(v,1-mx,cur,cur+1,left-1)));
	ans = f(mx, ans, solve(v, mx, prv, cur+1, left));

	done[mx][prv][cur][left]=1;
	return ans;
}

class TheProduct{
public:
	long long maxProduct(vector <int> numbers, int k, int maxDist){
		memset(dp,-1,sizeof(dp));
		n=sz(numbers) , d=maxDist;
		LL ans = solve(numbers,1,n,0,k);
		if(find(all(numbers),0) != end(numbers)) ans=max(ans,0LL);
		return ans;
	}
};

signed main(){
freopen("in.txt","r",stdin);
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
}
