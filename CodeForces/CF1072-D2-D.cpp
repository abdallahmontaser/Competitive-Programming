/**
 * Editorial: https://codeforces.com/blog/entry/62612
 * Mine is the same, I just used BFS for the two parts and not DP.
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

bool vis[2001][2001];
char c[4001];
struct element{
	int len;
	char c;
	int i,j;
	int k;
	bool operator<(const element &b) const{
		if(len != b.len) return len > b.len;
		if(c != b.c) return c > b.c;
		return k < b.k;
	}
};

signed main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,k; cin>>n>>k;
	char ch[n+1][n+1];
	for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) cin>>ch[i][j];
	for(int i=1; i<=2*n-1; ++i) c[i]='z'+1;

	priority_queue<element> pq;
	pq.push({1, ch[1][1], 1, 1, k});
	if(k>0 && ch[1][1]!='a') pq.pop() , pq.push({1, 'a', 1, 1, k-1});

	while(!pq.empty()){
		element cur=pq.top(); pq.pop();
		if(vis[cur.i][cur.j] || c[cur.len]<cur.c) continue;
		vis[cur.i][cur.j] = 1;
		c[cur.len] = cur.c;

		if(cur.i + 1 <= n){
			int t_k = cur.k;
			char t_ch = ch[cur.i+1][cur.j];
			if(t_k>0 && t_ch!='a') --t_k, t_ch='a';
			pq.push({cur.len+1, t_ch, cur.i+1, cur.j, t_k});
		}
		if(cur.j + 1 <= n){
			int t_k = cur.k;
			char t_ch = ch[cur.i][cur.j+1];
			if(t_k>0 && t_ch!='a') --t_k, t_ch='a';
			pq.push({cur.len+1, t_ch, cur.i, cur.j+1, t_k});
		}
	}
	string ans;
	for(int len=1; len<=2*n-1; ++len) ans+=string(1,c[len]);
	cout<<ans<<'\n';

return 0;
}
