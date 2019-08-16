/**
  * Find the strongly connected components of the graph.
  * Then for every edge (u,v) where u and v are not in the same SCC, mark the SCC of u.
  * Sinks are the nodes in the unmarked SCCs.
  * Why? Because the nodes in the marked SCCs clearly have a path to atleast on node in a different SCC. And because that
  * node is in a different SCC, it has no way back to them(or else they would be in the same SCC) so they are not sinks.
  * It's clear that the other way around is also correct; a node in an SCC having no edges going out to another SCC is a sink.
  * 
  * Another code and explanation: https://github.com/BRAINOOOO/CompetitiveProgramming/blob/master/Spoj/SPOJ%20BOTTOM.Cpp
*/
#include <bits/stdc++.h>
#define ULL unsigned long long
#define LL long long
#define LD long double
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define loop(i,a,b) for(int i=a;i<=b;++i)
#define pool(i,a,b) for(int i=a;i>=b;--i)
#define int long long
using namespace std; const int N = 5000 + 5, N2 = 50000 + 5, LOG = 9 + 1, INF = 1e9;

vector<int> g[N]; bool marked[N];

int dfs_nb, cmp_nb, dfsIndex[N], lowest[N], cmp[N]; bool inStack[N]; stack<int> st;
void tarjan(int i){
	dfsIndex[i] = lowest[i] = ++dfs_nb;
	st.push(i); inStack[i]=1;

	for(int j: g[i]){
		if(dfsIndex[j] == -1){
			tarjan(j);
			lowest[i] = min(lowest[i], lowest[j]);
		}else if(inStack[j] == 1){
			lowest[i] = min(lowest[i], lowest[j]);
		}
	}

	if(dfsIndex[i] == lowest[i]){
		++cmp_nb;
		int cur;
		do{
			cur = st.top();
			cmp[cur] = cmp_nb;

			inStack[cur]=0;
			st.pop();
		}while(cur != i);
	}
}

signed main(){ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m;
	while(cin>>n && n != 0 && cin>>m){
		loop(i,1,n) g[i].clear();
		loop(i,1,m){
			int u,v; cin>>u>>v;
			g[u].pb(v);
		}

		loop(i,1,n) inStack[i]=0, dfsIndex[i]=-1;
		dfs_nb=cmp_nb=0;
		while(sz(st)) st.pop();
		loop(i,1,n) if(dfsIndex[i] == -1) tarjan(i);

		loop(i,1,n) marked[i]=0;
		loop(i,1,n) for(int j: g[i]) if(cmp[i] != cmp[j]) marked[cmp[i]] = 1;
		
		vector<int> ans;
		loop(i,1,n) if(!marked[cmp[i]]) ans.pb(i);
		
		loop(i,0,sz(ans)-1) cout<<ans[i]<<" \n"[i==sz(ans)-1];
	}
}
