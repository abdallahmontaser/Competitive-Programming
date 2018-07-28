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
* I solved it using max_flow min_cut.
* Make a super source, link it to all the numbers in the first set, and link all the numbers in the second set to a super sink.
* For every (a,b) such that a is in the first set and b is in the second, and a divides b add the edge (a,b).
* When you think about it, we want the minimum NUMBER of VERTICES to delete so we can disconnect the source and the sink.
* But the min_cut is about the minimum COST of EDGES to delete in order to disconnect s and t.So I added capacities on each node(every number
* from the first or the second set) equal to 1(can be done by adding an extra node attached to every node).
* And to make sure that the min_cut algorithm doesn't count the edges (a,b) such that b divides a, I put the capacity of these edges to oo.
* So now the min_cut will return what we need.
*/

ll s,t,total;
ll a[110],b[110];
map<ll,ll> vis;
vector<map<ll,ll> >cap;
vector<ll>path;

ll get_path(ll i,ll curr_flow){
   vis[i] = 1;

   if(i == t)  return curr_flow;

   foreach(j,cap[i]) if(!vis[j->first] && j->second > 0){
      ll res = get_path(j->first,min(curr_flow,j->second));
      if(res>0) {
         path.pb(j->first);
         return res;
      }
   }

   return 0;
}

ll max_flow(){
   ll ans=0;
   while(1){
      path.clear();
      vis.clear();
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

   ll tests; cin>>tests;
   FOR(tc,1,tests){
      ll n; cin>>n;
      FOR(i,1,n) cin>>a[i];

      ll m; cin>>m;
      FOR(i,1,m) cin>>b[i];

      cap.resize(2*n+2*m+4);
      FOR(i,1,2*n+2*m+3) cap[i].clear();

      s=2*n+2*m+1;
      t=2*n+2*m+2;

      FOR(i,1,n){
         ++cap[s][i];
         ++cap[i][i+n];
         FOR(j,1,m)
            if(!b[j] || (a[i] && b[j]%a[i]==0)) cap[i+n][j+2*n]+=1e9;
      }

      FOR(i,1,m){
         ++cap[i+2*n][i+2*n+m];
         ++cap[i+2*n+m][t];
      }

      cout<<"Case "<<tc<<": "<<max_flow()<<endl;
   }

	return 0;
}
