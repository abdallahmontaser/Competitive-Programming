/**
* Editorial: https://codeforces.com/blog/entry/8903
*/
#include <bits/stdc++.h>
#define ULL unsigned long long
#define LL long long
#define LD long double
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define loop(i,a,b) for(int i=a;i<=b;++i)
#define pool(i,a,b) for(int i=a;i>=b;--i)
using namespace std; const int N = 130000 + 5, LOG = 17 + 1;

signed main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//<>
	int n; cin>>n;
	int g=0,mx=0;
	loop(i,1,n){ int x; cin>>x; g=__gcd(g,x); mx=max(mx,x); }
	cout<<((mx/g-n)%2 ? "Alice\n" : "Bob\n");

}
