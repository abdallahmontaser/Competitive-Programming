/**
  * Firstly possibleCells[t] contains every cell minus the ones mentionned in a message linked to the time 't'.
  * Then we'll do two sweeps, first from left to right then the opposite.
  * Each time, we verify the possibleCases[i] and reduce their number.
  * By taking the intersection between them and the cells resulting from a single breadth(BFS) of the previous/next time step. 
  * 
  * Another solution: https://github.com/WaleedAbdelhakim/Competitive-Programming/blob/master/UVA/707.cpp
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
using namespace std;
const int N = 100 + 5, N2 = 50000 + 5, LOG = 9 + 1, INF = 1e9;

int dx[] = {0, 0, -1, 1, 0}, dy[] = {-1, 1, 0, 0, 0};
set<pair<int, int>> possibleCells[N];

void intersect(set<pair<int, int>> &a, set<pair<int, int>> &b) {
	vector<pair<int, int>> toDelete;
	for (auto pair : b)
		if (a.find(pair) == a.end()) toDelete.pb(pair);

	for (auto pair : toDelete) b.erase(pair);
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, t, cases = 1;
	while (cin >> n >> m >> t && n != 0 && m != 0 && t != 0) {
		cout << "Robbery #" << cases++ << ":\n";

		loop(i, 1, t) {
			possibleCells[i].clear();
			loop(j, 1, n) loop(k, 1, m) possibleCells[i].insert(mp(j, k));
		}

		int messages;
		cin >> messages;
		while (messages--) {
			int _t, i1, j1, i2, j2;
			cin >> _t >> i1 >> j1 >> i2 >> j2;
			loop(i, i1, i2) loop(j, j1, j2) if (possibleCells[_t].find(mp(i, j)) != possibleCells[_t].end())
				possibleCells[_t].erase(mp(i, j));
		}

		loop(i, 2, t) {
			set<pair<int, int>> breadth;
			for (auto p : possibleCells[i - 1])
				loop(j, 0, 4) if (1 <= p.F + dx[j] && p.F + dx[j] <= n && 1 <= p.S + dy[j] && p.S + dy[j] <= m)
					breadth.insert(mp(p.F + dx[j], p.S + dy[j]));

			intersect(breadth, possibleCells[i]);
		}
		pool(i, t - 1, 1) {
			set<pair<int, int>> breadth;
			for (auto p : possibleCells[i + 1])
				loop(j, 0, 4) if (1 <= p.F + dx[j] && p.F + dx[j] <= n && 1 <= p.S + dy[j] && p.S + dy[j] <= m)
					breadth.insert(mp(p.F + dx[j], p.S + dy[j]));

			intersect(breadth, possibleCells[i]);
		}

		bool zero = 0, one = 0;
		loop(i, 1, t) zero |= (sz(possibleCells[i]) == 0), one |= (sz(possibleCells[i]) == 1);

		if (zero) cout << "The robber has escaped.\n";
		else if (one) {
			loop(i, 1, t) if (sz(possibleCells[i]) == 1)
					cout << "Time step " << i << ": The robber has been at " << possibleCells[i].begin()->F << "," << possibleCells[i].begin()->S << ".\n";
		}
    else cout << "Nothing known.\n";
		
    cout << "\n";
	}
}
