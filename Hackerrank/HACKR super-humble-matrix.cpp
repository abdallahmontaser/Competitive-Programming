#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define endl '\n'
const ld PI =  3.141592653589793238L;
const ll N=1000002;
using namespace std;

ll fact[N];

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll n,m; cin >> n >> m;

   *fact=1;
   for(ll i=1;i!=N;++i) fact[i]=(i*fact[i-1])%MOD;

   ll ans=1;
   for(int i=1;i<=min(n,m);++i) ans=(ans*fact[i])%MOD;

   for(int i=min(n,m)+1;i<=max(n,m);++i) ans=(ans*fact[min(n,m)])%MOD;

   for(int i=max(n,m)+1,j=min(n,m);j&&i<=n+m-1;++i) ans=(ans*fact[--j])%MOD;

   cout << ans << endl;

   return 0;

}

