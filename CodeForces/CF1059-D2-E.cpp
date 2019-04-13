/**
* Editorial: https://codeforces.com/blog/entry/62238
* I recommend just reading the second (greedy) solution.
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
using namespace std;
int n,L,w[100123],p[100123][17],lvl[100123],best[100123];
vector<int> g[100123];
ll S,sum[100123][17];
int dfs(int i){
      if(lvl[i] != 0) return lvl[i];
      return lvl[i] = 1 + dfs(p[i][0]);
}
int solver(int i){
      int ans = 0 , t_best = -1;
      for(int j: g[i]){
            ans += solver(j);
            if(t_best == -1 || lvl[best[j]] < lvl[t_best]) t_best = best[j];
      }
      if(t_best != -1 && lvl[t_best] <= lvl[i]) best[i] = t_best;
      else ++ans;
      return ans;
}
int32_t main(){
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      cin >> n >> L >> S;
      for(int i = 1; i <= n; ++i) cin >> w[i];
      if(S < *max_element(w + 1 , w + n + 1)){cout << "-1\n"; return 0;}
      p[1][0] = 1;
      for(int i = 2; i <= n; ++i){
            cin >> p[i][0];
            sum[i][0] = w[p[i][0]];
            g[p[i][0]].pb(i);
      }
      for(int j = 1; j <= 16; ++j) for(int i = 1; i <= n; ++i) p[i][j] = p[p[i][j - 1]][j - 1];
      for(int j = 1; j <= 16; ++j) for(int i = 1; i <= n; ++i) sum[i][j] = sum[i][j - 1] + sum[p[i][j - 1]][j - 1];
      lvl[1] = 1;
      for(int i = 2; i <= n; ++i) dfs(i);
      for(int i = 1; i <= n; ++i){
            int cur = i , h = 1 , s = w[cur];
            for(int j = 16; j >= 0; --j) if(h + (1 << j) <= L && s + sum[cur][j] <= S)
                  h += (1 << j) , s += sum[cur][j] , cur = p[cur][j];

            best[i] = cur;
      }
      cout << solver(1) << '\n';
      return 0;
}

