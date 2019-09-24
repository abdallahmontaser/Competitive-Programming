/**
* I'm going to state the proof I made for why this works, but I'm not sure 100% it proves it.
* Here's another solution: https://github.com/jebouin/CompetitiveProgramming/blob/master/UVA/UVA%2010982.cpp
* 
* The problem is about dividing the nodes from 1 to n into two groups, such that the edges between nodes of
* different groups are at least half the total number of edges.
* If the graph is bipartite, by dividing it correctly we can get rid of all the edges.
* Now what if it isn't? To say it simply, my solution is just the regular bipartite graph coloring algorithm,
* coloring every node either with 1 or 2, then printing one of the groups at the end.
* 
* A graph is not bipartite iff there exists a cycle with an odd number of nodes, in that case(if we color the
* graph in the best way) we will only lose one of the edges in that cycle. That is why it's always possible
* to do the asked.
* Let me re-explain. Let the number of edges we'll be able to get rid of be X. We just want X >= half of M
* If the graph is bipartite then X = total number of edges.
* Else, for each odd cycle, we will lose 1 edge, meaning subtract one from X.
* 
* Why will X still be >= half of M at the end? Because odd cycles will have number of edges = {3, 5, 7....}
* 
* So for each odd cycle(any other form in the graph isn't harmful) it's like adding the number of edges in it
* and subtracting 1. At worst, if the whole graph is filled with odd cycles of length 3, we will have 2/3 * M.
* Which is obviously more than half.
* I did my best! :D but I'm still not 100% sure about some things.
* To clarify some other cases, some odd cycles in the graph can share some edges. To explain, suppose we have
* an odd cycle of 3 nodes; 1-2  2-3  3-1
* I explained the case for when the second odd cycle will be completely out of that one, (4-5  5-6  6-7) for example
* But we can obtain another odd cycle by adding only (5-1 5-2) that is, 1 node. Or adding two nodes only.
* That's one issue, the other one is that I was worried that, yes there may be eventually a good coloring and it's always possible
* but what if my algorithm doesn't find it? At the end as you see below, it's completely random how the coloring will be,
* I can swap lines 47 and 48 and it will change it completely!
* That was my thinking process :D
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
vector<int> g[N]; int vis[N];
void dfs(int i, int color){
	vis[i] = color;
	for(int j: g[i]) if(!vis[j]) dfs(j,3-color);
}
signed main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin>>tc;
	loop(t,1,tc){
		cout<<"Case #"<<t<<": ";
		loop(i,1,100) g[i].clear();
		memset(vis,0,sizeof(vis));
		int n,m; cin>>n>>m;
		loop(i,1,m){
			int a,b; cin>>a>>b;
			g[a].push_back(b), g[b].push_back(a);
		}
		loop(i,1,n) if(!vis[i]) dfs(i,1);
		vector<int> ans;
		loop(i,1,n) if(vis[i]==1) ans.push_back(i);
		cout<<sz(ans)<<'\n';
		loop(i,0,sz(ans)-1) cout<<ans[i]<<" \n"[i==sz(ans)-1];
	}
}
