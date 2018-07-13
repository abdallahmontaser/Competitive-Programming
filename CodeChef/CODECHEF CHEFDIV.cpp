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
const ll N=1000002;
using namespace std;

/**
* This video explains it all: https://www.youtube.com/watch?time_continue=312&v=9kSxipsWu6M
*/

ll a,b;
vector<int>v[N];
int p[N];

ll solve(ll& n){
   priority_queue<int>q;
   ll x=n;

   ll ans=1;
   for(int i=0;i<v[n-a].size() && x!=1;++i){
      int pr=v[n-a][i];
      int cnt=0;
      while(x%pr==0) ++cnt,x/=pr;
      q.push(cnt+1);
      ans *= cnt+1;
   }

   if(x != 1) q.push(2) , ans*=2;

   ll last=ans;
   while(!q.empty()){
      int tmp=q.top();
      q.pop();

      last = (last/tmp)*(tmp-1);
      ans += last;

      if(tmp > 2) q.push(tmp-1);
   }

   return ans;
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   for(int i=2;i<N;++i) p[i]=1;
   for(int i=2;i<N;++i) if(p[i]) for(int j=i+i;j<N;j+=i) p[j]=0;

   cin >> a >> b;

   for(int i=2;i<N;++i) if(p[i]){
      ll j = ((a+i-1)/i)*i;
      while(j<=b){
         v[j-a].pb(i);
         j+=i;
      }
   }

   ll ans=0;
   for(ll i=a;i<=b;++i) ans += solve(i)-1;

   cout << ans << endl;

	return 0;
}
