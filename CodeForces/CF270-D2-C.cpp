#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define endl '\n'
#define foreach(it,x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
const ld PI =  3.141592653589793238L;
const ll N=100002;
using namespace std;

/**
* Loop from i=1 to i=n-1(0-indexed) and find out for every i, how many squares of type i should we add(if we should add at all) so all
* squares of type i-1 (I used log2 for this).
* 
* Then in the end, we have the number of squares of the biggest type.And we need to find out the minimum side length("b") such that one square
* of that length can fit a[n-1] squares of side length k[n-1].This is possible when (2^b)² >= (2^k[n-1])² * a[n-1]
* Finally, since I've been using log2 on every a[i], I should find the minimum "b" such that: b >= a[n-1]/2 + k[n-1]
*
* Be careful, b should always be > k[n-1](see where I started my bsearch).Costed me a WA.
* 
* Editorial: http://codeforces.com/blog/entry/6596
*/

ll bsearch(ld x,ll i,ll j){
   ll ans;
   while(i<=j){
      ll mid=(i+j)/2;
      if(mid<x) i=mid+1;
      else j=mid-1,ans=mid;
   }
   return ans;
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll n; cin >> n;
   pair<ld,ld> t[n];
   for(int i=0;i<n;++i) cin >> t[i].first >> t[i].second;

   sort(t,t+n);

   t[0].second = (ld)log2(t[0].second);
   for(int i=0;i<n-1;++i) t[i+1].second = max((ld)log2(t[i+1].second) , (ld)t[i].second-2*(t[i+1].first-t[i].first));

   cout << bsearch((ld)t[n-1].second/2 + t[n-1].first,t[n-1].first+1,1e18) << endl;

   return 0;

}
