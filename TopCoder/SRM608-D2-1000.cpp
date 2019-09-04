/**
  * I'll do my best to explain the proof with maybe 50% intuition and 50% formulas, it is by no means of full mathematical correctness.
  *
  *
  * The number of possible walks of length L in a graph is the sum of possible walks of length L starting at a node Xi, for
  * all Xi.
  * So the total number is bounded if and only if numberOfWalks(Xi,L) is bounded for every node Xi.
  *
  * Now comes the important observation.
  * Focus on one node X; let's look at the number of edges to neighbours Yi such that you can go back from Yi to X.
  *
  * If it's 0, then the number of walks of length L starting at X(in the formula) calls other nodes who call other nodes, but with no going back to X(because our number=0)
        That means it's a sum of things(depending on the length) with no products or stuff like that.
  * By the way, sum is good (= polynomials) but products are bad(= exponentials)
  *
  * If it's 1, then the formula numberOfWalks(X,L) will go back to calling numberOfWalks(X,L2) such that L2 < L but this kind
        of loop won't produce exponential formulas because it's finite.
  *
  * If it's > 1 however(let's say 2 for example), there will be combinations of those neighbours..
  * I found a formula for this case, that proves it's an unbounded function in this case. In other words, that if our number > 1   ===>  Unbounded.
  * The other way is explained in the cases above.
  * Suppose we have a node X having two neighbours Y1 and Y2, and Y1 can go back to X with a path of length l1, Y2 with l2.
  * We will then have: numberOfWalks(X,l1 + 1 + l2 + 1) = ... some_stuff ... + 2*numberOfWalks(X,0)
  *     we have the last term because you can go from X to Y1(+1) then back to X(+l1) then to Y2(+1) then back to X(+l2).
  *     and we have it multiplied by 2, because you can do this particular walk in two ways, by combining X->Y1->X->Y2->X or inversing Y1 and Y2.
  * You can see that the number becomes bigger with more neighbours being able to go back to X.
  * So this also gives us: numberOfWalks(X,(l1 + 1 + l2 + 1) * N) = ... some_stuff ... + 2*numberOfWalks(X,(l1 + 1 + l2 + 1) * (N-1))
  *
  * That ->, is an exponential function. I know one when I see one!
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

int canReach[N][N], vis[N];

class BigOEasy {
  public:
	int n;
	void dfs(int i, vector<string> &graph) {
		if (vis[i]) return;
		vis[i] = 1;
		loop(j, 1, n) if (graph[i - 1][j - 1] == 'Y') dfs(j, graph);
	}
	string isBounded(vector<string> graph) {
		n = sz(graph);
		loop(i, 1, n) {
			memset(vis, 0, sizeof(vis));
			dfs(i, graph);
			loop(j, 1, n) if (vis[j]) canReach[i][j] = 1;
		}
		bool bounded = 1;
		loop(i, 1, n) {
			int nb = 0;
			loop(j, 1, n) if (graph[i - 1][j - 1] == 'Y') nb += canReach[j][i];
			if (nb > 1) bounded = 0;
		}
		if (bounded) return "Bounded";
		return "Unbounded";
	}
};
