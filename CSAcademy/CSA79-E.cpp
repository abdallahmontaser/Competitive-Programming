/**
* If we keep the sum of all the negative numbers, and work only with b[i] = abs(a[i]) for every i, the j_th subset sum will be
* j_th_subset_sum_of_b + negative_sum  for every j from 0 to 2^n - 1.
* Now we only need to find the smallest K subsets based on their sum.
* Below is a BFS approach(keeping only the index of the highest bit), I have no formal proof of it.
*/

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
#define ll long long
#define ld long double
#define all(x) x.begin(),x.end()
#define int long long
using namespace std;
int32_t main(){
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      int n,k; cin >> n >> k;
      ll neg = 0;
      int a[n + 1];
      for(int i = 1; i <= n; ++i){
            cin >>  a[i];
            if(a[i] < 0) neg += a[i] , a[i] *= -1;
      }
      sort(a + 1 , a + n + 1);

      cout << neg << '\n';
      priority_queue<pair<ll,int>> pq;
      pq.push(mp(-a[1] , 1));
      while(--k){
            ll sum = -pq.top().F;
            int i = pq.top().S;
            pq.pop();

            cout << sum + neg << '\n';

            if(i + 1 <= n){
                  pq.push(mp(-(sum + a[i + 1]) , i + 1));
                  pq.push(mp(-(sum - a[i] + a[i + 1]) , i + 1));
            }
      }

      return 0;
}
