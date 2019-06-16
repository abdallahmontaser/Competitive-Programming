/**
* First I use multi-source bfs to find out the mn[i,j]=minimum distance from every (i,j) to an enemy base.
* Then I computed the maximum possible 'minimum separation' by adding, from x = MAX to 0, the nodes that have mn[i,j]=x and
* stopping when the start and end node become connected by any path(that's found using dsu).
* Then I compute the shortest distance using BFS and considering only the nodes that I added in the dsu part.
* 
* I did all of this to ensure I have a linear complexity; O(N + X*Y) per test case. Since I wasn't sure if O(X*Y*log(N)) would pass
* If it does, using binary search on the 'minimum separation' would be easier. This passes in 0.2 sec.
* 
* Another solution using only 2 BFS: https://github.com/ahmedsamir221/CompetitiveProgramming/blob/master/UVA/UVA%2012128.cpp
* Although I'm confident it's worst case complexity should be O((X*Y)²). Idk it passes in 1 sec.
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
using namespace std; const int N = 1000 + 5, LOG = 17 + 1, MOD = 1000000007;

vector<pair<int,int>> v[N+N]; int dx[]={0,0,-1,1}, dy[]={-1,1,0,0}, vis[N][N], vis2[N][N];
pair<int,int> rep[N][N]; int sz[N][N];

pair<int,int> find(pair<int,int> x) {
	if(x == rep[x.F][x.S]) return x;
	return rep[x.F][x.S] = find(rep[x.F][x.S]);
}
void unite(pair<int,int> x , pair<int,int> y){
	x=find(x),y=find(y);
	if(x==y) return;
	if(sz[x.F][x.S] < sz[y.F][y.S]) swap(x, y);
	sz[x.F][x.S] += sz[y.F][y.S];
	rep[y.F][y.S] = x;
}

signed main(){ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin>>tc;
	while(tc--){
		int nb,n,m; cin>>nb>>n>>m;
		pair<int,int> st, en; cin>>st.F>>st.S>>en.F>>en.S;
		loop(i,0,n-1) loop(j,0,m-1){
			vis[i][j]=-1;
			rep[i][j]={i,j}, sz[i][j]=1;
		}

		queue<pair<int,pair<int,int>>> q;
		while(nb--){ int x,y; cin>>x>>y; q.push({0,{x,y}}); vis[x][y]=0; }
		while(!q.empty()){
			int d=q.front().F, x=q.front().S.F, y=q.front().S.S; q.pop();
			loop(c,0,3){
				int xx = x+dx[c], yy = y+dy[c];
				if(min(xx, yy)<0 || n <= xx || m <= yy || vis[xx][yy]!=-1) continue;
				q.push({d+1, {xx, yy}});
				vis[xx][yy]=d+1;
			}
		}

		loop(i,0,n-1+m-1) v[i].clear();
		loop(i,0,n-1) loop(j,0,m-1){
			v[vis[i][j]].push_back({i,j});
			vis[i][j]=-1;
		}
		int separate = n-1 + m-1 + 1;
		while(find(st) != find(en)){
			--separate;
			for(auto p: v[separate]){
				vis[p.F][p.S] = 1;
				loop(c,0,3){
					int xx = p.F+dx[c], yy = p.S+dy[c];
					if(min(xx, yy)<0 || n <= xx || m <= yy) continue;
					if(vis[xx][yy] == -1) continue;
					unite({xx,yy}, p);
				}
			}
		}
		cout<<separate<<' ';

		loop(i,0,n-1) loop(j,0,m-1) vis2[i][j]=-1;
		queue<pair<int,pair<int,int>>> q2; q2.push({0,st}); vis2[st.F][st.S]=1;
		while(true){
			if(q2.front().S == en){ cout<<q2.front().F<<'\n'; break; }

			int d=q2.front().F, x=q2.front().S.F, y=q2.front().S.S; q2.pop();
			loop(c,0,3){
				int xx = x+dx[c], yy = y+dy[c];
				if(min(xx, yy)<0 || n <= xx || m <= yy) continue;
				if(vis[xx][yy]==-1 || vis2[xx][yy]!=-1) continue;
				q2.push({d+1, {xx, yy}});
				vis2[xx][yy]=1;
			}
		}
	}
}
