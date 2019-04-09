/**
* My solution is a bit long and has a complexity of O((n + q)*log^2(n)) with a big constant factor.
* The best solution I've found is in the second editorial here: https://codeforces.com/blog/entry/15513
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
int n;
int st[200123] , en[200123] , suff[200123] , nxt[200123][18];
int nn;
int seg1[600123] , seg2[600123];
void upd(int a[] , int i , int val){
      i += nn - 1;
      a[i] = val , i >>= 1;
      while(i > 0) a[i] = max(a[i << 1] , a[i << 1 | 1]) , i >>= 1;
}
int get(int a[] , int i){return a[i + nn- 1];}
int que(int a[] , int l , int r , int i = 1 , int x = 1 , int y = nn){
      if(l <= x && y <= r) return a[i];
      if(y < l || r < x) return 0;
      int mid = (x + y) >> 1;
      return max(que(a , l , r , i << 1 , x , mid) , que(a , l , r , i << 1 | 1 , mid + 1 , y));
}
int32_t main(){
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      cin >> n;
      nn = 1 << (int)ceil(log2(n));
      for(int i = 1; i <= n ; ++i){
            int p , l; cin >> p >> l;
            st[i] = p , en[i] = p + l;
            upd(seg2 , i , en[i]);
      }

      for(int i = n; i >= 1; --i){
            upd(seg1 , i , upper_bound(st + 1 , st + n + 1 , en[i]) - st - 1);
            upd(seg1, i , que(seg1 , i , get(seg1 , i)));
      }

      for(int j = 0; j <= 17; ++j) nxt[n + 1][j] = n + 1;

      for(int i = 1; i <= n; ++i) nxt[i][0] = get(seg1 , i) + 1;
      for(int j = 1; j <= 17; ++j) for(int i = 1; i <= n; ++i) nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];

      for(int i = n; i >= 1; --i){
            int j = nxt[i][0];
            if(j != n + 1) suff[i] = suff[j] + st[j] - que(seg2 , i , j - 1);
      }

      int q; cin >> q;
      while(q--){
            int l,r; cin >> l >> r;

            int rr;
            int lo = 0 , hi = n;
            while(lo <= hi){
                  int mid = (lo + hi) >> 1;

                  int cur = l , len = mid;
                  while(len > 0){
                        int x = __builtin_ctz(len);
                        cur = nxt[cur][x];
                        len -= (1 << x);
                  }

                  if(cur <= r) rr = cur , lo = mid + 1;
                  else hi = mid - 1;
            }

            cout << suff[l] - suff[rr] << '\n';
      }

      return 0;
}
