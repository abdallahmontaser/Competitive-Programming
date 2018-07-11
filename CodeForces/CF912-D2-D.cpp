#include<bits/stdc++.h>
#define MOD 1000000007
#define EPS 1e-15
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define endl '\n'
#define foreach(it,x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
const ld PI=3.141592653589793238L;
const ll N=100002;
using namespace std;

/**
* Let M be the matrix where Mij is the number of scoops that will have the fish (i,j) in them.
* The final answer will be the sum of the K biggest elements in it, divided by (n-r+1)*(m-r+1).
* The K biggest elements can be found by doing BFS on M(beware of overflow; do not put a pair in the queue more than once!).
*
* Editorial(better explanation with an extra solution): http://codeforces.com/blog/entry/56920
*/

ll n,m;
ll r,k;

ll f(pair<ll,ll>a){
   ll x=min(n-r+1,min(a.first,n-a.first+1));
   ll y=min(m-r+1,min(a.second,m-a.second+1));

   return min(r,x)*min(r,y);
}

bool ok(pair<ll,ll>a){
   if(!a.first || !a.second) return 0;
   if(a.first==n+1 || a.second==m+1) return 0;
   return 1;
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   cin >> n >> m >> r >> k;

   set<pair<ll,ll> >s,s2;
   priority_queue<pair<ll,pair<ll,ll> > >q;

   pair<ll,ll>a = mp((n+1)/2,(m+1)/2);

   q.push(mp(f(a),a));
   s.insert(a);
   while(s2.size()!=k){
      a = q.top().second;
      s2.insert(a);
      q.pop();

      pair<ll,ll>b = a;
      ++b.first; if(s.find(b)==s.end()&&ok(b)) q.push(mp(f(b),b)) , s.insert(b);
      b.first-=2; if(s.find(b)==s.end()&&ok(b)) q.push(mp(f(b),b)) , s.insert(b);
      ++b.first,++b.second; if(s.find(b)==s.end()&&ok(b)) q.push(mp(f(b),b)) , s.insert(b);
      b.second-=2; if(s.find(b)==s.end()&&ok(b)) q.push(mp(f(b),b)) , s.insert(b);
   }

   ld ans1=0;
   foreach(it,s2) ans1 += f(*it);

   ld ans2=(n-r+1)*(m-r+1);

   cout << fixed << setprecision(9) << ans1/ans2;

	return 0;
}
