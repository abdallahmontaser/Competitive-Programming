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

/**
*I just calculated the expected maximum by summing from i=1 to m the term:
* ( i*(i^n - (i-1)^n) ) / m^n
*/

ld power(ld x,ll n){
   if(!n) return (ld)1;
   ld y=power(x,(ll)n/2);
   y=(y*y);
   if(n%2) y*=x;
   return y;
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ld n,m; cin >> m >> n;

   ld ans=0;
   for(ld i=1;i<=m;++i) ans += i*(power(i/m,n)-power((i-1)/m,n));

   cout << ans << endl;

   return 0;

}
