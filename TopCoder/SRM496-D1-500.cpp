#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
const long double PI = 3.141592653589793238L , EPS = 1e-12L;
const int N = 200005 , MOD = 1000000007;
using namespace std;

/**
* Editorial: http://apps.topcoder.com/wiki/display/tc/SRM+496
*/

bool vis[105];
vector<int> g[105];

int dfs(int x, int &nb){
	++nb;
	vis[x] = 1;
	for(int y: g[x]) if(vis[y] == 0) return dfs(y, nb);

	return x;
}

class OneDimensionalBalls{
	public: long long countValidGuesses(vector<int> firstPicture, vector<int> secondPicture){
		int n = sz(firstPicture) , m = sz(secondPicture);

		set<int> dist;
		for(int i = 0; i < m; ++i){
			int d = abs(firstPicture[0] - secondPicture[i]);
			if(d == 0) continue;

			dist.insert(d);
		}

		long long ans = 0;
		for(int d: dist){
			memset(vis, 0, sizeof(vis));
			for(int j = 0; j < n + m; ++j) g[j].clear();

			for(int a = 0; a < n; ++a) for(int b = 0; b < m; ++b)
				if(abs(firstPicture[a] - secondPicture[b]) == d) g[a].pb(b + n) , g[b + n].pb(a);

			long long tans = 1;
			for(int a = 0; a < n; ++a) if(vis[a] == 0 && sz(g[a]) == 1){
				int nb = 0;
				if(dfs(a, nb) < n) tans = 0;
			}
			for(int b = 0; b < m; ++b) if(vis[b + n] == 0 && sz(g[b + n]) == 1){
				int nb = 0;
				if(dfs(b + n, nb) >= n) tans *= ((nb >> 1) + 1);
			}

			for(int a = 0; a < n; ++a) if(sz(g[a]) == 0) tans = 0;

			cout << tans << "  ";
			ans += tans;
		}

		return ans;
	}
};
