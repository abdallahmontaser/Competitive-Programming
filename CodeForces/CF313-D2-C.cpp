#include<bits/stdc++.h>
#define MOD 1000000007
#define EPS 1e-9
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define endl '\n'
#define foreach(it,x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
const ld PI =  3.141592653589793238L;
const ll N=1000002;
using namespace std;

/**
* The answer is the sum of ranges [1..x] for each power of 4 from 1=4^0 to 4^n.
* So to maximize this, all we need to do is (greedily) sort the numbers in descending order and return the previous sum.
* 
* Editorial: http://codeforces.com/blog/entry/7826
*/

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll n; cin >> n;
   ll a[n]; for(int i=0;i<n;++i) cin >> a[i];
   sort(a,a+n);
   reverse(a,a+n);

   ll sum=0,tmp=0,p=1;
   for(int i=0;i<n;++i){
      tmp+=a[i];
      if(i+1==p) sum+=tmp , p*=4;
   }

   cout << sum << endl;

   return 0;

}
