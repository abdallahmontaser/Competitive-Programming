#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define endl '\n'
const ld PI =  3.141592653589793238L;
const ll N=100002;
using namespace std;

/**
* Loop over all elements in the array and suppose that the current a[i] is the middle element of a correct geometric progression,
* we should then(if a[i] is divisible by k) add to our answer;
* the product of the number of occurences of a[i]/k to the left of i by the number of occurences of
* a[i]*k to the right of i.This can be done with maps.
*
* Editorial: http://codeforces.com/blog/entry/19604
*/

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll n,k; cin >> n >> k;
   ll a[n]; for(int i=0;i!=n;++i) cin >> a[i];

   map<ll,ll>p_occ,s_occ;
   for(int i=0;i!=n;++i) ++s_occ[a[i]];

   ll ans=0;
   for(int i=0;i!=n;++i){
      --s_occ[a[i]];

      if(a[i]%k==0) ans += p_occ[a[i]/k] * s_occ[a[i]*k];

      ++p_occ[a[i]];
   }

   cout << ans << endl;

   return 0;

}
