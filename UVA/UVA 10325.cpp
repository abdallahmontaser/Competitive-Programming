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
* Go over all possible subsets, and for each one, if there's an even number of elements in it; add n/lcm(elements) to the final answer
* otherwise substract it.
* 
* lcm(a,b) = a*b / gcd(a,b).
*/

map<ll,ll>M;
ll n,m;
vector<ll>a;

void solve(ll i,ll nn,ll c){
   if(i==m){
      M[c] += n/nn;
      return;
   }

   solve(i+1,nn,c);
   solve(i+1,nn*a[i]/__gcd(nn,a[i]),c+1);
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   while(cin >> n){
      M.clear();
      a.clear();
      cin >> m;
      ll x;
      for(int i=0;i!=m;++i) cin >> x , a.pb(x);

      vector<ll>v;
      solve(0,1,0);

      ll ans=0;
      for(int i=0;i<=a.size();++i) ans += (i%2==0) ? M[i] : -M[i];

      cout << ans << endl;
   }

   return 0;

}
