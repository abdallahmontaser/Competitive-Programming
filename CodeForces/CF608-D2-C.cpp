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
* ans[i] = number of objects destroyed in range [0,i] if the the object i is activated.
* After computing that, we try all possible cases; for i in [0,n-1], if the object that will be put to the right will destroy this object
* and not the one before it(the ith object will be the last object to be destroyed by the added object) or not.And we choose the minimum
* number of total objects destroyed.
* 
* Editorial: http://codeforces.com/blog/entry/22256
*/

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll n; cin >> n;
   pair<ll,ll> a[n];
   for(ll i=0;i<n;++i) cin >> a[i].first >> a[i].second;
   sort(a,a+n);

   ll ans[n];
   for(int i=0;i<n;++i){
      if(a[i].first-a[i].second <= a[0].first) ans[i]=i;
      else{
         ll x=0,y=i;
         ll t;
         while(x<=y){
            ll mid=(x+y)/2;
            if(a[i].first-a[i].second > a[mid].first) x=mid+1;
            else t=mid , y=mid-1;
         }

         ans[i] = i-t+ans[t-1];
      }
   }

   ll f_ans = n;
   for(int i=1;i<=n;++i) f_ans=min(f_ans,n-i+ans[i-1]);

   cout << f_ans << endl;

   return 0;

}
