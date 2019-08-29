/**
  * Observations made in order of clarity:
  *     First, it's easy to see that an answer with many nodes can be better than an answer with fewer(see third test case)
  *     Second, there are some nodes that must be included, in order for the "reaching priority" to be verified, and the rest can or can not be added.
  *     Third, once the needed ones are found and looking at the formula for the average of numbers, the optimal way to decrease this average
  *          is to loop on the rest of values(starting from the smallest? or order doesn't matter?), and add the ones that are less than the current average.
  * The algorithm is clear then, we find the necessary nodes by finding the SCCs that have no edge going to them from another SCC
  * and pick the minimum value only in them(also because we're only picking the must-have ones for now and the minimum would be the best).
  * Then we loop through and add the rest in an optimal way.
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
const int N = 50 + 5, N2 = 50000 + 5, LOG = 9 + 1, INF = 1e9;

int nbDfs = 0, nbCmp = 0, dfsIndex[N], lowest[N], cmp[N];
bool inStack[N];
stack<int> st;
bool canReachCmp[N];

class AntarcticaPolice {
  public:
	int n;
	void tarjan(int i, vector<string> &roads) {
		dfsIndex[i] = lowest[i] = ++nbDfs;
		st.push(i);
		inStack[i] = 1;

		loop(j, 1, n) if (roads[i - 1][j - 1] == 'Y') {
			if (dfsIndex[j] == -1) {
				tarjan(j, roads);
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

	double minAverageCost(vector<int> costs, vector<string> roads) {
		n = sz(costs);
		loop(i, 1, n) dfsIndex[i] = -1;
		loop(i, 1, n) if (dfsIndex[i] == -1) tarjan(i, roads);

		loop(i, 1, n) loop(j, 1, n) if (roads[i - 1][j - 1] == 'Y' && cmp[i] != cmp[j]) canReachCmp[cmp[j]] = 1;

		vector<int> toDelete;
		int sumVal = 0, nbVal = 0;
		loop(i, 1, nbCmp) if (!canReachCmp[i]) {
			int mn = INF;
			loop(j, 1, n) if (cmp[j] == i) mn = min(mn, costs[j - 1]);

			sumVal += mn, ++nbVal;
			toDelete.pb(mn);
		}

		sort(all(costs));
		for(int x: toDelete) costs.erase(find(all(costs),x));
		loop(i, 0, sz(costs) - 1) if (sumVal > nbVal * costs[i]) sumVal += costs[i], ++nbVal;

		return sumVal / (LD)nbVal;
	}
};
