/**
* First use BFS to find a correct route.
* Then just print the required move to go the next cell in the list you generated. Whenever you stay at the same place after a query,
* reverse the role of 'L' and 'R' if you went in either one, or 'U' and 'D'.
* You will never go in a dangerous cell this way, because(since you start at (1,1)) the first 'L' or 'R' you're going to print will be
* a moment where you are at the first or last column(since you only used 'U' or 'D' before it or nothing at all) and your left and right
* cells will be; one:out of bounds and the other:a correct normal cell.
* Same for going up/down.
* 
* Editorial: https://codeforces.com/blog/entry/52228
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
using namespace std; const int N = 100 + 5;

int dx[4]={0,0,1,-1} , dy[4]={1,-1,0,0} , nxt[4]={1,0,3,2};
string c[4]={"R","L","D","U"};
char grid[N][N]; int n,m,vis[N][N],vis2[N][N],d[N][N];

signed main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	loop(i,1,n) loop(j,1,m) cin>>grid[i][j];

	queue<pair<int,int>> q;
	vis[1][1]=1;
	q.push({1,1});
	while(!q.empty()){
		int i=q.front().F, j=q.front().S; q.pop();
		loop(c,0,3){
			int ii=i+dx[c] , jj=j+dy[c];
			if(ii<1 || n<ii) continue;
			if(jj<1 || m<jj) continue;
			if(vis[ii][jj] || grid[ii][jj]=='*') continue;

			vis[ii][jj]=1, d[ii][jj] = 1+d[i][j];
			q.push({ii, jj});
		}
	}

	pair<int,int> p; loop(i,1,n) loop(j,1,m) if(grid[i][j]=='F') p={i,j};

	vector<pair<int,int>> v;
	while(p!=mp(1,1)){
		vis2[p.F][p.S]=1;
		v.push_back(p);

		loop(c,0,3){
			int ii=p.F + dx[c] , jj=p.S + dy[c];
			if(ii<1 || n<ii) continue;
			if(jj<1 || m<jj) continue;
			if(!vis[ii][jj] || vis2[ii][jj]) continue;

			if(d[ii][jj] + 1 == d[p.F][p.S]){
				p = mp(ii,jj);
				break;
			}
		}
	}
	reverse(all(v));

	pair<int,int> cur={1,1};
	loop(i,0,sz(v)-1){
		int dir;
		loop(j,0,3) if(v[i].F-cur.F==dx[j] && v[i].S-cur.S==dy[j]) dir=j;
		cout<<c[dir]<<'\n'<<flush;
		int x,y; cin>>x>>y;
		if(mp(x,y)==cur){
			swap(c[dir],c[nxt[dir]]);
			--i;
		}
		else cur=v[i];
	}
}
