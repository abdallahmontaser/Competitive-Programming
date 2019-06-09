/**
* A graph with N*M <= 1e6 nodes, where edges have either 0 or 1 as weights, and you're asked to compute the shortest path 50 times.
* Dijkistra will give us O(50 * N*M * log(N*M)) which is too much. But because we only have binary weights, we can use something called
* 0-1 BFS to achieve linear computations on each query.
* 
* See this: https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/UVA/UVA_11573.txt
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
using namespace std; const int N = 1000000 + 5;

int dx[]={-1,-1, 0, 1, 1, 1, 0, -1};
int dy[]={0 , 1, 1, 1, 0,-1,-1, -1};
int grid[N], vis[N]; vector<pair<int,int>> g[N];
int n,m;

void dfs(int i){
	for(int x: {-1,0,1}) for(int y: {-1,0,1}){
		if(!x && !y) continue;
		int nxt_row = (i-1)/m+1 + x;
		int nxt_col=(i-1)%m+1 + y;

		if(1<= nxt_row && nxt_row <=n)
		if(1<= nxt_col && nxt_col <=m)
		g[i].push_back({(nxt_row-1)*m + nxt_col , !(x==dx[grid[i]]&&y==dy[grid[i]])});
	}
}

signed main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	loop(i,1,n) loop(j,1,m){
		char ch; cin>>ch;
		grid[(i-1)*m+j]=ch-'0';
	}
	loop(i,1,n*m) dfs(i);
	int queries; cin>>queries;
	loop(cur,1,queries){
		int a,b,c,d; cin>>a>>b>>c>>d;
		int s=(a-1)*m+b , t=(c-1)*m+d;
		deque<pair<int,int>> q; q.push_front({s,0});
		while(q.front().F != t){
			int x=q.front().F, d=q.front().S; q.pop_front();
			if(vis[x]==cur) continue;
			vis[x]=cur;
			for(auto y: g[x]) if(vis[y.F] != cur){
				if(!y.S) q.push_front({y.F, d});
				else q.push_back({y.F, d+1});
			}
		}
		cout<<q.front().S<<'\n';
	}
}
