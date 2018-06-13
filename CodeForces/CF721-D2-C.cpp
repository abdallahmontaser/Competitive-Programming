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
* Editorial: http://codeforces.com/blog/entry/47457
*/

ll n,m,T;
bool ok[5000],done[5000];
vector<pair<int,int> >graph[5000];
vector<pair<int,pair<int,int> > >dp[5000];

vector<pair<int,pair<int,int> > > dfs(int x){
   if(done[x]) return dp[x];

   vector<pair<int,pair<int,int> > >tmp;
   if(x==n-1) tmp.pb(mp(0,mp(1,n))) , ok[x]=1;
   if(!graph[x].size()){
      done[x]=1;
      return dp[x] = tmp;
   }

   vector<pair<int,pair<int,int> > >tmp2;
   for(int i=0;i!=graph[x].size();++i){
      tmp2 = dfs(graph[x][i].first);

      if(!ok[graph[x][i].first]) continue;
      ok[x]=1;

      for(int j=0;j!=tmp2.size();++j){
         tmp2[j].first += graph[x][i].second;
         ++tmp2[j].second.first;
         tmp2[j].second.second = graph[x][i].first;
      }

      tmp.insert(tmp.begin(),tmp2.begin(),tmp2.end());
   }

   done[x]=1;
   return dp[x]=tmp;
}

void dfs2(int x){
   vector<pair<int,pair<int,int> > >&v = dp[x];

   pair<int,pair<int,int> > ans = mp(0,mp(0,0));
   foreach(it,v) if((*it).first <= T && ((*it).second).first > ans.second.first) ans=*it;

   if(!x) cout << ans.second.first << endl;
   cout << x+1;
   if(x!=n-1) cout << ' ',dfs2(ans.second.second);
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   cin >> n >> m >> T;

   for(int i=0;i!=m;++i){
      int u,v,t; cin >> u >> v >> t;
      if(u==n || v==1) continue;
      graph[u-1].pb(mp(v-1,t));
   }

   dfs(0);

   dfs2(0);

   return 0;

}
