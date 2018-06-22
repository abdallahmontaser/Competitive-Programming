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
* Still getting WA.
*/

map<ll,ll>M;
ll n;
vector<ll>a;

void solve(ll i,ld nn,vector<ll>v){
   if(i==a.size()){
      ll nn2=nn;
      M[v.size()] += nn2;
      return;
   }

   solve(i+1,nn,v);
   v.pb(a[i]);
   solve(i+1,(ld)nn/a[i],v);
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   while(cin >> n){
      M.clear();
      a.clear();
      ll m; cin >> m;
      ll tmp_a[m]; for(int i=0;i!=m;++i) cin >> tmp_a[i];

      sort(tmp_a,tmp_a+m);

      for(int i=0;i!=m;++i){
         ll x=tmp_a[i];
         bool found=0;
         for(int j=0;j<a.size();++j) if(x%a[j]==0) found=1;
         if(!found) a.pb(x);
      }

      vector<ll>v;
      solve(0,(ld)n,v);

      ll ans=0;
      for(int i=0;i<=a.size();++i) ans += (i%2==0) ? M[i] : -M[i];

      cout << ans << endl;
   }

   return 0;

}
