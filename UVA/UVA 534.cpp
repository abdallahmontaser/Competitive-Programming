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
* Used the same trick/recurrence used in the Bellman-Ford algorithm that calculates shortest paths(and finds negative cycles) in graphs.
* dist[i] represents minmax value(the answer to our problem) from i to the final stone(stone 2).
* All values are initialised to oo = 1e9(except for the final stone).
* So for n-1 times, I loop over all pairs of stones (i,j) and update the answer from i to j.
* 
* We will need at most n-1 times, and the proof behind that isn't hard to prove.Read on the Bellman-Ford algorithm.
* Or just imagine the worst case, which is when the optimal route will be from stone 1 -> 3 -> 4 -> 5 -> ... -> n -> 2.
* In the first iteration we need to go till n, to update it with 2, then till n-1 to update it with n then ... until, in the n-1th iteration
* We update 1 with 3.So that's n-1 iterations(Same proof for Bellman-Ford's negative cycle finding).
*/

pair<ld,ld> a[200];

ld f(ll i,ll j){
   ld x1=a[i].first , x2=a[j].first;
   ld y1=a[i].second , y2=a[j].second;
   
   return (ld)sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll n; cin >> n;
   ll tc=0;
   while(n){
      ++tc;
      for(int i=0;i<n;++i) cin >> a[i].first >> a[i].second;

      ld dist[n];
      for(int i=0;i<n;++i) dist[i]=(ld)1e9;
      dist[1]=(ld)0;

      for(int cnt=1;cnt<=n-1;++cnt){
         for(int i=0;i<n;++i) for(int j=0;j<n;++j) dist[i]=min(dist[i],max(f(i,j),dist[j]));
      }

      cout << "Scenario #" << tc << endl << "Frog Distance = ";
      cout << fixed << setprecision(3) << dist[0];
      cout << endl << endl;

      cin >> n;
   }

   return 0;

}
