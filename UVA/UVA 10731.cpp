/**
  * Let's draw the graph of nodes {the answers} and of edges {(u,v) whenever an answer indicated a preference for u over v}.
  * Now if there's a path from node X to node Y, then X is preferred over Y. (it's clear that this covered transitivity)
  *
  * If this is true in a set of nodes: "for each pair within a given set, the answers indicate a contradictory preference"
  * then this set of nodes formes a StronglyConnectedComponent of the graph. The problem also asks for us to minimize the
  * number of these groups(SCCs of the graph). Meaning it wants for the sizes of these groups to be as big as possible.
  * It's clear that SCCs do, by definition, suffice that.
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
using namespace std; const int N = 26 + 5, N2 = 50000 + 5, LOG = 9 + 1, INF = 1e9;

vector<int> g[N]; bool marked[N];
vector<vector<int>> ans;

int dfs_nb, dfsIndex[N], lowest[N]; bool inStack[N]; stack<int> st;
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
		int cur;
		vector<int> v;
		do{
			cur = st.top();
			v.pb(cur);

			inStack[cur]=0;
			st.pop();
		}while(cur != i);

		ans.pb(v);
	}
}

signed main(){ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int nb;
	bool first=1;
	while(cin>>nb && nb != 0){
		if(!first) cout<<'\n';
		first = 0;

		loop(i,1,26) g[i].clear();
		ans.clear();
		set<int> nodes;
		loop(i,1,nb){
			char ch[10];
			loop(j,1,6) cin>>ch[j], nodes.insert(ch[j] - 'A' + 1);
			
			loop(j,1,5) g[ch[6] - 'A' + 1].pb(ch[j] - 'A' + 1);
		}

		loop(i,1,26) inStack[i]=0, dfsIndex[i]=-1;
		dfs_nb=0;
		while(sz(st)) st.pop();
		loop(i,1,26) if(nodes.count(i) && dfsIndex[i] == -1) tarjan(i);
		
		loop(i,0,sz(ans)-1) sort(all(ans[i]));
		sort(all(ans));

		loop(i,0,sz(ans)-1){
			loop(j,0,sz(ans[i])-1) cout<<char(ans[i][j] + 'A' - 1)<<" \n"[j==sz(ans[i])-1];
		}
	}
}
