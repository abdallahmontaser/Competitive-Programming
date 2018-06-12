#include<bits/stdc++.h>
#define MOD (1000 * 1000 * 1000 + 7)
#define ll long long
#define ld long double
#define MAXN 100010
using namespace std;

/**
* If q is prime or equal to 1 then the first player will win without making any move, so we print 1 0.
* Else if all divisors of q are prime, then obviously we can only choose a prime and so the second player will win.
* Else we the first player can win by choosing the smallest non-prime divisor of q as it will only have prime divisors for the second player to choose from.
* 
* Editorial: http://codeforces.com/blog/entry/3905
*/

vector<bool> prime;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    ll x; cin >> x;
    
    prime.resize(sqrt(x)+1,1);
    
    for(int i=2;i<prime.size();++i) if(prime[i]) for(int j=i*2;j<prime.size();j+=i) prime[j]=0;
    
    vector<ll> v;
    for(int i=2;(ll)i*i<=x;++i) if(x%i == 0) v.push_back(i);
    
    if(!v.size()) cout << "1\n0";
    else{
    	ll found=x;
    	
		for(int y: v) if(!prime[y]){
			cout << "1\n" << y;
			return 0;
		}
    	
		for(int y: v) if((x/y)%y == 0){found=min(found,(ll)y*y); break;}
		for(int y: v) for(int z: v) if(y!=z && x%(y*z)==0) found=min(found,(ll)y*z);
		
		if(found == x) cout << "2";
		else cout << "1\n" << found;
    }
    
    return 0;
}
