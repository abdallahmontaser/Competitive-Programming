#include<bits/stdc++.h>
#define MOD (1000 * 1000 * 1000 + 7)
#define ll long long
#define ld long double
#define MAXN 200010
using namespace std;

/**
* I tried all the possible LCM(n,n-1,x) for every possible x <= n-2 and took the maximum.Same for (n-1,n-2,x).
* 
* Editorial(better solution): http://codeforces.com/blog/entry/5592
*/

ll f(int N,int i){
	int j=i/__gcd(N,i);
	return (ll) N * (N-1) * (j/__gcd(N-1,j));
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int N; cin >> N;
    ll ans;
    
    if(N<3) ans=N;
    else{
        ans=1;
        for(int i=1;i<=N-2;++i) ans=max(ans,f(N,i));
        for(int i=1;i<=N-3;++i) ans=max(ans,f(N-1,i));
    }
    
    cout << ans;
    
    return 0;
}
