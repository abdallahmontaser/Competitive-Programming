#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
const long double EPS = 1e-12L;
const int N = 200005 , MOD = 1000000007;
using namespace std;

/**
* The graph, where nodes are our voters and an edge (u,v) means that u and v can not be both satisfied, is bipartite.
*
* After constructing this graph, notice that our answer is the (max_# of voters such that no two of them are connected by an edge).
* This can also be seen as (total_# of voters - min_# of voters such that for every edge, we pick atleast one of it's endpoints).
* The last term is the "minimum vertex cover" of a graph.
* 
* According to the famous Konig's theorem in a bipartite graph; the "minmum vertex cover" = the "maximum bipartite matching".
* 
* Finally, the maximum bipartite matching of a bipartite graph is it's maximum flow from S to T where S and T are two dummy nodes
* and there are edges from S to all the nodes of the first half of the graph and from all the nodes of the second half to T.
* 
* Following is Dinic's algorithm for computing the max_flow.
* We output (n - max_flow).
*/

struct edge{
	int nxt , f , cap , rev;
};

vector<edge> g[505];
int level[505];
int s , t;

void addE(int a , int b , int c){
	edge e;
	e.nxt = b , e.f = 0 , e.cap = c , e.rev = sz(g[b]);
	g[a].pb(e);
	
	e.nxt = a , e.f = 0 , e.cap = 0 , e.rev = sz(g[a]);
	g[b].pb(e);
}

bool bfs(){
	memset(level,-1,sizeof(level));
	
	queue<int> q;
	q.push(s);
	level[s] = 0;

	while(q.empty() == 0){
		for(edge e: g[q.front()]) if(level[e.nxt] == -1 && e.f < e.cap){
			level[e.nxt] = level[q.front()] + 1;
			q.push(e.nxt);
		}
		
		q.pop();
	}
	return level[t] != -1;
}

int send_flow(int curr, int curr_f){
	if(curr == t) return curr_f;

	for(edge &e: g[curr]) if(level[e.nxt] == level[curr] + 1 && e.f < e.cap){
		int tmp_f = send_flow(e.nxt , min(curr_f , e.cap - e.f));

		if(tmp_f > 0){
			e.f += tmp_f;
			g[e.nxt][e.rev].f -= tmp_f;

			return tmp_f;
		}
	}

	return 0;
}

int max_flow(){
	int f = 0;
	while(bfs() == 1)
		while(int tmp_f = send_flow(s , 1) != 0)
			f += tmp_f;
	
	return f;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int tc; cin >> tc;
	while(tc--){
		int c,d,n; cin >> c >> d >> n;
		s = n + 1 , t = n + 2;
		for(int i = 1; i <= n + 2; ++i) g[i].clear();

		vector<pair<string,string>> v(n);
		for(int i = 1; i <= n; ++i) cin >> v[i - 1].F >> v[i - 1].S;

		for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j)
			if(v[i - 1].F[0] == 'C' && (v[i - 1].F == v[j - 1].S || v[i - 1].S == v[j - 1].F))
				addE(i , j , 1);

		for(int i = 1; i <= n; ++i){
			if(v[i - 1].F[0] == 'C') addE(s , i , 1);
			else addE(i , t , 1);
		}

		cout << n - max_flow() << '\n';
	}

    return 0;
}
