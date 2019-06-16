/**
* Nicely explained editorial with step-by-step observations:
* 		https://codeforces.com/blog/entry/21318
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
using namespace std; const int N = 130000 + 5, LOG = 17 + 1;

vector<int> g[N], g2[N], v; int timer, p[N][LOG], dist[N], t_in[N], t_out[N], mark[N];

bool anc(int a, int b){ return t_in[a] <= t_in[b] && t_out[b] <= t_out[a]; }
int lca(int u, int v){
    if(anc(u,v)) return u;
    if(anc(v,u)) return v;

    pool(i,17,0) if(!anc(p[u][i], v)) u = p[u][i];
    return p[u][0];
}
void dfs(int i, int prv){
	t_in[i]=++timer;
	p[i][0] = prv;
	loop(l,1,17) p[i][l]=p[p[i][l-1]][l-1];
	for(int j: g[i]) if(j!=prv) dfs(j, i);
	t_out[i]=++timer;
}
void dfs2(int i, int prv){
	dist[i]=dist[prv]+1;
	for(int j: g2[i]) if(j!=prv) dfs2(j, i);
}

signed main(){ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m; cin>>n>>m;
	loop(i,1,n-1){
		int u,v; cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	loop(i,1,m){ int x; cin>>x; v.push_back(x); }
	if(m==1){ cout<<v[0]<<'\n'<<"0\n"; return 0; }

	dfs(1, 1);

	int x=v[0]; loop(i,1,sz(v)-1) x=lca(x,v[i]);
	mark[x]=1;
	loop(i,0,sz(v)-1){
		int t=v[i];
		while(!mark[t] && t!=x){
			mark[t]=1;
			t=p[t][0];
		}
	}

	loop(i,1,n) for(int j: g[i]) if(mark[i]&&mark[j]) g2[i].push_back(j);

	dfs2(v[0], 0);
	int fst=max_element(dist+1, dist+n+1) - dist;

	memset(dist,0,sizeof(dist));
	dfs2(fst, 0);
	int scd=max_element(dist+1, dist+n+1) - dist;

	cout<<min(fst,scd)<<'\n'<<2*(count(mark+1,mark+n+1,1)-1) - (dist[scd]-1)<<'\n';

}
