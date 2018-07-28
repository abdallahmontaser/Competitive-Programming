#include<bits/stdc++.h>
#define MOD 1000000007
#define EPS 1e-15
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define endl '\n'
#define foreach(it,x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define FOR(i,a,b) for(ll i=(ll)a;i<=(ll)b;++i)
#define FOR_(i,a,b,c) for(ll i=(ll)a;i<=(ll)b;i+=(ll)c)
const ld PI=3.141592653589793238L;
const ll N=100005;
using namespace std;

/**
* This is a regular s-t max_flow problem with a super source and a super sink.
* 
* See this if you still don't know how to construct the graph:
* https://github.com/BRAINOOOO/CompetitiveProgramming/blob/master/UVA/V-7/UVA%20753.Cpp
*/

map<string,ll>id;

ll total;
ll s,t;
ll vis[505];
ll cap[505][505];
vector<ll>path;

ll get_path(ll i,ll curr_flow){
   vis[i] = 1;

   if(i == t)  return curr_flow;

   for(int j=1;j<=total;++j) if(!vis[j] && cap[i][j]>0){
      ll res = get_path(j,min(curr_flow,cap[i][j]));
      if(res>0) {
         path.pb(j);
         return res;
      }
   }

   return 0;
}

ll max_flow(){
   ll ans=0;
   while(1){
      path.clear();
      memset(vis,0,sizeof(vis));
      ll res = get_path(s,1e9);

      if(!res) break;

      path.pb(s);
      reverse(path.begin(),path.end());

      for(int i=0;i<path.size()-1;++i){
         cap[path[i]][path[i+1]] -= res;
         cap[path[i+1]][path[i]] += res;
      }
      ans += res;
   }

   return ans;
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll tc; cin>>tc;
   while(tc--){
      memset(cap,0,sizeof(cap));
      id.clear();
      total=0;

      ll n,m,k;

      cin>>n;
      vector<ll>v1;
      FOR(i,1,n){
         string st; cin>>st;
         if(!id[st]) id[st]=++total,v1.pb(id[st]);
      }

      cin>>m;
      vector<ll>v2;
      FOR(i,1,m){
         string st1,st2; cin>>st1>>st2;
         if(!id[st1]) id[st1]=++total,v2.pb(id[st1]);
         if(!id[st2]) id[st2]=++total;

         ++cap[id[st1]][id[st2]];
      }

      cin>>k;
      FOR(i,1,k){
         string st1,st2; cin>>st1>>st2;
         if(!id[st1]) id[st1]=++total;
         if(!id[st2]) id[st2]=++total;
         cap[id[st1]][id[st2]]+=1000;
      }

      s=++total , t=++total;

      foreach(it,v1) ++cap[*it][t];

      foreach(it,v2) ++cap[s][*it];

      cout<<m-max_flow()<<endl;
      if(tc) cout<<endl;
   }

	return 0;
}
