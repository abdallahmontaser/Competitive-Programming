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
* I stored all the notification ids(starting from one and incrementing at each event of the first type) in the set s.
* So after each event, I just print the size of the set.I also store the notification of the i-th application in a[i], such that
* start[i] represents the index of the first unread notification in a[i].
* I think the code for the three types of events is self-explanatory.The thing worth mentioning is to always update start[i] after
* an event of the second type for the i-th application.
* 
* So finally, for each notification(at most n) and in the worst case, I will insert it once in the set, pass by it once in it's vector a[]
* and erase it once from the set.Which is n + 2*n*log(n) operations = O(n*log(n)).
* The final complexity is O(n*log(n) + q).
* 
* Editorial: https://codeforces.com/blog/entry/46450
*/

set<ll>s;
vector<ll>a[N];
ll start[N];

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll n,q; cin >> n >> q;

   ll notif=1;
   while(q--){
      ll t,x; cin >> t >> x;

      if(t==1){
         a[x].pb(notif);
         s.insert(notif++);
      }

      if(t==2){
         for(int i=start[x];i<a[x].size();++i){
            set<ll>::iterator it=s.find(a[x][i]);
            if(it != s.end()) s.erase(it);
         }
         start[x]=a[x].size();
      }

      if(t==3){
         s.erase(s.begin(),s.lower_bound(x+1));
      }

      cout << s.size() << endl;
   }

   return 0;

}
