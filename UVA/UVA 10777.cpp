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
* Let "a" be the sum of all abs(xi)*pi and "b" the sum of all pi that have negative xi.
* Then if b < 1 the answer will be a/(1-b) .
* Else it's impossible, since none of the doors take you to a safe place.
*/

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll tc; cin >> tc;
   for(int t=1;t<=tc;++t){
      ll n; cin >> n;

      ld a=0,b=0;
      while(n--){
         ld x,y; cin >> x >> y;
         a+=fabs(x)*y;
         if(x<0) b+=y;
      }

      cout << fixed << setprecision(2);
      cout << "Case " << t << ": ";

      if(b==(ld)1) cout << "God! Save me";
      else cout << a/(ld)(1-b);

      cout << endl;
   }

   return 0;

}
