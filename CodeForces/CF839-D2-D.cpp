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
* My solution is the same as the one described in the editorial: http://codeforces.com/blog/entry/53815 (the 2nd method)
*/

pair<ll,ll> nb[1000001];
ll exist[1000001];

ll pow(ll n){
   if(!n) return 1ll;
   ll x = pow(n/2);
   x=(x*x)%MOD;
   if(n%2) x=(x*2)%MOD;
   return x;
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll n; cin >> n;
   while(n--){
      ll x; cin >> x;
      ++exist[x];
   }

   for(int i=0;i<=1000000;++i) nb[i].first=i;
   for(int i=2;i<=1000000;++i){
      nb[i].second += exist[i];
      for(int j=2*i;j<=1000000;j+=i) nb[i].second += exist[j];
   }

   ll ans=0;
   for(int i=2;i<=1000000;++i) if(nb[i].second){
      ans += ((nb[i].first*nb[i].second)%MOD * pow(nb[i].second-1))%MOD;
      ans %= MOD;
      for(int j=2*i;j<=1000000;j+=i) nb[j].first -= nb[i].first;
   }

   cout << ans << endl;

	return 0;
}
