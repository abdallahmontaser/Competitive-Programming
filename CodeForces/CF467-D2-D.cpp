/**
  * Let's stick to one case with all the letters since cases don't matter.
  * We have a list of words(all in uppercase) and we want to minimize the total number of 'R's in them, then minimize their total length.
  * Using, of course, the synonyms. Let's construct a graph and assign a number to every word and make it a node of our graph.
  * If A can be replaced with B, then we add an edge from A to B.Also let's assign to each node a pair of values(r, len) where
  * r is the number of occurences of the letter 'R' in it, and len is it's length. That way, the default min() over two pairs will
  * work nicely(prioritizing the minimizing of the number of 'R's THEN the total length) and so the observation to see is that
  * the final answer is the sum of the answers of each string in the essay(an answer is also a pair of (r, len) ) and so each answer
  * for the strings is independant. Now for each string, we go through the graph and take the minimum of the pairs of the nodes that
  * it can reach. Then we end by summing the pairs( (a,b) + (c,d) = (a+c,b+d) ).
  *
  * But since the graph's form is random, there can be cycles and loops, that won't let the normal O(N) dfs work even by storing the
  * answer for already computed nodes. That's why we use SCC-compression and assign the best pair of every node in the same SCC to that
  * node. Then our graph is a DAG and we dfs our way to the answer!
  *
  * Editorial(in russian but the translation is readable): http://codeforces.ru/blog/entry/13870
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
#define all(x) x.begin(), x.end()
#define loop(i, a, b) for (int i = a; i <= b; ++i)
#define pool(i, a, b) for (int i = a; i >= b; --i)
#define int long long
using namespace std;
const int N = 300000 + 5, N2 = 50000 + 5, LOG = 9 + 1, INF = 1e9;

int nb;
map<string, int> id;
map<int, pair<int, int>> val, valCmp;
vector<int> g[N], tmp_g[N];
int vis[N];

int nbDfs, nbCmp, dfsIndex[N], lowest[N], cmp[N];
bool inStack[N];
stack<int> st;
void tarjan(int i) {
	dfsIndex[i] = lowest[i] = ++nbDfs;
	st.push(i);
	inStack[i] = 1;

	for (int j : g[i]) {
		if (dfsIndex[j] == -1) {
			tarjan(j);
			lowest[i] = min(lowest[i], lowest[j]);
		} else if (inStack[j] == 1) {
			lowest[i] = min(lowest[i], lowest[j]);
		}
	}

	if (dfsIndex[i] == lowest[i]) {
		++nbCmp;
		int cur;
		do {
			cur = st.top();
			cmp[cur] = nbCmp;

			inStack[cur] = 0;
			st.pop();
		} while (cur != i);
	}
}

void init(string &s) {
	loop(i, 0, sz(s) - 1) s[i] = toupper(s[i]);
	if (id[s] == 0) {
		id[s] = ++nb;
		val[id[s]] = {count(all(s), 'R'), sz(s)};
	}
}

void dfs(int i) {
	pair<int, int> &cur = valCmp[i];
	if (vis[i]) return;
	vis[i] = 1;

	for (int j : g[i]) {
		if (vis[j] == 0) dfs(j);
		cur = min(cur, valCmp[j]);
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<string> essay;
	loop(i, 1, n) {
		string s;
		cin >> s;
		init(s);
		essay.pb(s);
	}

	int syn;
	cin >> syn;
	loop(i, 1, syn) {
		string a, b;
		cin >> a >> b;
		init(a), init(b);
		g[id[a]].pb(id[b]);
	}

	loop(i, 1, nb) dfsIndex[i] = -1;
	loop(i, 1, nb) if (dfsIndex[i] == -1) tarjan(i);

	loop(i, 1, nbCmp) valCmp[i] = {INF, INF};
	loop(i, 1, nb) valCmp[cmp[i]] = min(valCmp[cmp[i]], val[i]);

	loop(i,1,nb) for(int j: g[i]) tmp_g[cmp[i]].pb(cmp[j]);
	swap(g, tmp_g);

	pair<int, int> ans = {0, 0};
	for (string s : essay) {
		int cur = cmp[id[s]];
		dfs(cur);
		ans.F += valCmp[cur].F;
		ans.S += valCmp[cur].S;
	}

	cout << ans.F << ' ' << ans.S << '\n';
}
