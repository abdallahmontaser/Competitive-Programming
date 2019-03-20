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
* Editorial: https://apps.topcoder.com/wiki/display/tc/SRM+463
*/

class Nisoku{

	public: double theMax(vector <double> cards){
		sort(cards.begin(), cards.end());
		double ans = 0;
		
        
		for(int nb = 0; nb <= sz(cards); nb += 2){
			
			double tans = 1.0L;
			for(int i = 0 , j = nb - 1; i < j; ++i , --j) tans *= cards[i] + cards[j];

			for(int i = nb; i < sz(cards); ++i) tans *= cards[i];

			ans = max(ans , tans);
		}

		return ans;
	}
};
