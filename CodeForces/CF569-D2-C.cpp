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
const ll N=2000002;
using namespace std;

/**
* Use Sieve for finding prime numbers in N*log2(N)
* 
* Editorial: http://codeforces.com/blog/entry/19705
*/

ll prime[N],palind[N];

ll f(ll x){
   stringstream ss;
   ss << x;

   string s1 = ss.str();
   string s2(s1.begin(),s1.end());
   reverse(s2.begin(),s2.end());

   for(int i=0;i!=s1.size();++i) if(s1[i]!=s2[i]) return 0;
   return 1;
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   for(int i=0;i<N;++i) prime[i]=1;
   prime[0]=prime[1]=0;
   for(int i=2;i<N;++i) if(prime[i]) for(int j=i+i;j<N;j+=i) prime[j]=0;
   for(int i=1;i<N;++i) prime[i] += prime[i-1];

   palind[0]=0;
   for(int i=1;i<N;++i) palind[i] = f(i)+palind[i-1];

   ll p,q; cin >> p >> q;
   ll i=N-1;
   while(q*prime[i] > p*palind[i]) --i;

   cout << i << endl;

   return 0;

}
