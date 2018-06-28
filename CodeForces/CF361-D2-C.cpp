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
* Greedily, the array with maximum values that don't exceed mi-add[i](accumulation of di in position i) at each query of the second type,
* will either be the best solution(if it doesn't verify the queries then there doesn't exist a solution) or the only one.
* See the proof in the editorial below.
* 
* Editorial: http://codeforces.com/blog/entry/9529
*/

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll n,m; cin >> n >> m;
   ll add[n],ans[n];
   for(int i=0;i<n;++i) add[i]=0 , ans[i]=1e9;

   pair<pair<ll,ll>,pair<ll,ll> >q[m];
   for(int i=0;i<m;++i){
      ll t,l,r,x; cin >> t >> l >> r >> x;
      q[i] = mp(mp(t,l),mp(r,x));

      if(t==1) for(int i=l-1;i<=r-1;++i) add[i]+=x;
      else for(int i=l-1;i<=r-1;++i) ans[i]=min(ans[i],x-add[i]);
   }

   ll ans2[n];
   for(int i=0;i<n;++i) ans2[i]=ans[i];

   for(int i=0;i<m;++i){
      ll t=q[i].first.first , l=q[i].first.second;
      ll r=q[i].second.first , x=q[i].second.second;

      if(t==1) for(int i=l-1;i<=r-1;++i) ans2[i]+=x;
      else{
         ll m=ans2[l-1];
         for(int i=l-1;i<=r-1;++i) m=max(m,ans2[i]);
         if(m!=x){
            cout << "NO\n";
            return 0;
         }
   }
   }

   cout << "YES\n";
   for(int i=0;i<n;++i){
      cout << ans[i];
      if(i==n-1) cout << endl;
      else cout << " ";
   }

   return 0;

}
