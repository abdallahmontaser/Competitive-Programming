#include<bits/stdc++.h>
#define MOD 1000000007
#define EPS 1e-9
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define endl '\n'
#define foreach(it,x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
const ld PI=3.141592653589793238L;
const ll N=300002;
using namespace std;

/**
* The answer is 0 if the sequence is already sorted, and x (= the number of different permutations of the sequence) otherwise.
* 
* Editorial: https://www.hackerrank.com/challenges/lazy-sorting/editorial
*/

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll n; cin >> n;
   ll a[n];
   map<ll,ll>m;
   for(int i=0;i<n;++i) cin >> a[i] , ++m[a[i]];

   ll fact[19]; *fact=1;
   for(int i=1;i<=18;++i) fact[i]=i*fact[i-1];

   ll ans=fact[n];
   for(int i=1;i<=100;++i) ans/=fact[m[i]];

   if(is_sorted(a,a+n)) cout << "0\n";
   else cout << ans << endl;

   return 0;

}
