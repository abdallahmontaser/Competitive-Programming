#include<bits/stdc++.h>
#define MOD (1000 * 1000 * 1000 + 7)
#define ll long long
#define ld long double
#define MAXN 100010
using namespace std;

/**
* The problem is equivalent to finding the number of integers x,y,z,t such that the sum of numbers from x to y multiplied by the sum of numbers from z to t
* equals a.So we store the occurence of every consecutive sum we have and go through the divisors of a and for each divisor d
* add the occurence of the sum of d by the occurence of the sum a/d.
* While taking care of the cases d=sqrt(a) and a=0.
*
* Editorial: http://codeforces.com/blog/entry/9657
*/

string s;
int pref[4001];
map<int,int> m;

int f(int x){
	return m[x];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int a; cin >> a;
    cin >> s;
    
    pref[0]=s[0]-'0';
    for(int i=1;i<s.size();++i) pref[i]=s[i]-'0'+pref[i-1];
    
    for(int i=0;i<s.size();++i) ++m[pref[i]];
    for(int i=0;i<s.size();++i) for(int j=i+1;j<s.size();++j) ++m[pref[j]-pref[i]];
    
    ll ans=0;
    
    if(!a){
    	cout << (ll)((ll)(s.size()+1)*s.size() - f(0)) * f(0);
    	return 0;
	}
    
    vector<int>v;
    for(int i=1;(ll)i*i<=a;++i) if(a%i==0) v.push_back(i);
    
    for(int i: v){
    	if((ll)i*i==a) ans += (ll)pow(f(i),2);
		else ans += (ll) 2*f(i)*f(a/i);
	}
    
    cout << ans;
    
    return 0;
}
