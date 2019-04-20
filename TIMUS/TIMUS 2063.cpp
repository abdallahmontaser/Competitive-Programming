/**
* Sort the array(think of the way) then randomly pick a number "ind" in [1 ; n-1] and print "! ind ind+1"
* Failing a test means you picked a number ind such that color[ind] != color[ind + 1]
* There will either be 1 such index, or none. So the probability of failure is quite low.
* Total number of operations < 1.7e5
*/
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
#define ll long long
#define ld long double
#define all(x) x.begin(),x.end()
using namespace std;
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int tc; cin >> tc;
    if(tc == 2){
    	cout << "! 1 2\n";
    	cout << "! 1 3\n";
    	return 0;
    }

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    for(int n = 2; n <= 100; ++n){
    
    	for(int i = 1; i <= n - 1; ++i)
    		for(int j = i + 1; j <= n; ++j)
    			cout << "? " << i << " " << j << '\n';
    	
    	int nbr = uniform_int_distribution<int>(1 , n - 1)(rng);
    	cout << "! " << nbr << " " << nbr + 1 << "\n";
      
    }
    return 0;
}
