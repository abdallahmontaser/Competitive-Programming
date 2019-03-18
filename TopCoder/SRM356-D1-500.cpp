#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
const long double PI = 3.141592653589793238L , EPS = 1e-12L;
const int N = 200005 , MOD = 1000000007;
using namespace std;

int mask1[N] , mask2[N];

class MarriageProblemRevised{
	public: int neededMarriages(vector<string> preferences){
		int n = sz(preferences);
		int m = sz(preferences[0]);

		for(int msk = 0; msk <= (1 << n) - 1; ++msk){
			for(int i = 0; i < n; ++i) if(msk & (1 << i))
				for(int j = 0; j < m; ++j) if(preferences[i][j] == '1') mask1[msk] |= (1 << j);
		}

		for(int msk = 0; msk <= (1 << m) - 1; ++msk){
			for(int j = 0; j < m; ++j) if(msk & (1 << j))
				for(int i = 0; i < n; ++i) if(preferences[i][j] == '1') mask2[msk] |= (1 << i);
		}

		for(int i = 0; i < n; ++i) if(mask1[(1 << i)] == 0) return -1;

		int ans = n + m;
		for(int a = 0; a <= (1 << n) - 1; ++a) for(int b = 0; b <= (1 << m) - 1; ++b){
			if((a | mask2[b]) != (1 << n) - 1) continue;
			if((b | mask1[a]) != (1 << m) - 1) continue;

			ans = min(ans , __builtin_popcount(a) + __builtin_popcount(b));
		}

		return ans;
	}
};
