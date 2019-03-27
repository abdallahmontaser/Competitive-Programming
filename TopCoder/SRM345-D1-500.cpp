#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
#define ll long long
using namespace std;

/**
* There's a proven greedy strategy.
* 
* Editorial: https://community.topcoder.com/tc?module=Static&d1=match_editorials&d2=srm345
* 
* Another explanation: https://github.com/MedoN11/CompetitiveProgramming/blob/master/TopCoder/SRM345-D1-500.java
*/

class StoneGame{
	public: int getScore(vector <int> treasure, vector <int> stones){
		vector<int> v;
    
		int nb = 0 , sum = 0;
		for(int i = 0; i < sz(stones); ++i){
			if(stones[i] == 1) v.pb(treasure[i]);
			else nb += stones[i] , sum += treasure[i];
		}
		
		int ans = ((nb + sz(v)) % 2 == 1) ? sum : 0;

		sort(v.begin() , v.end());
		for(int i = sz(v) - 1; i >= 0; i -= 2) ans += v[i];

		return ans;
	}
};
