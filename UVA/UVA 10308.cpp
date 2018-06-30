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
* The given graph is a tree, you need to find it's diameter.
* The diameter of any tree can be computed by starting a regular DFS(keeping track of the maximum distance found) at any node,
* and finding the furthest node from it, then doing the same for that node, and return the second distance.
*/

bool vis[10000];
map<pair<ll,ll>,ll>dist;
ll node,best;

void dfs(vector<ll>*g,ll x,ll d){
   if(d>best) best=d,node=x;

   foreach(it,g[x]) if(!vis[*it]){
      vis[*it]=1;
      dfs(g,*it,d+dist[mp(x,*it)]);
   }
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   //freopen("t.txt","r",stdin); freopen("d.txt","w",stdout);
   // <<>>

   char ch[50];
   while(gets(ch)){
      vector<ll>g[10002];

      while(ch){
         string s(ch);
         istringstream iss(s);
         ll x,y,d; iss >> x >> y >> d;
         g[x].pb(y);
         g[y].pb(x);
         dist[mp(x,y)]=dist[mp(y,x)]=d;

         gets(ch);
      }

      node=1,best=-1;
      vis[node]=1;
      dfs(g,node,0);

      for(int i=1;i<=10000;++i) vis[i]=0;
      best=-1;
      vis[node]=1;
      dfs(g,node,0);

      cout << best << endl;
   }

   return 0;

}
