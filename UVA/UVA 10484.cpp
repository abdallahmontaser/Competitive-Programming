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
* First, store the prime numbers from 2 to 100(we'll need them because ANY number can be written as a product of prime numbers).
* For i=1 to N, add the occurence of each prime number in the prime decomposition of i, which means; at each step
* add to nb[x] the power of the x_th prime number(see the vector "primes") in the decomposition of i.
* Now it's easy to see that EVERY factor of N! can be obtained by calculating the product of every prime x in the "primes" vector raised
* to the power of any integer p(0 <= p <= nb[x]).
*
* Now, if d can be written as a product of only the prime numbers < 100, then we continue, else the answer will be 0.(see line 59)
* 
* Then, for d to have atleast one factor of N! as a multiple, it needs to divide N!.So we substract all the occurences of every prime
* number x in the decomposition of d, from nb[x].
* d will divide N! if and only if nb[x] >= 0 for every prime number x(see the max trick in line 60).
*
* Now that we have guaranteed that the answer is atleast 1.We can easily observe that the number of different factors of N! that are divisible
* by d are the product of nb[x]+1 for each prime number x.
*
* Try to look at the vector "nb" (after adding and substracting) as the prime decomposition of N! / d.
*/

vector<ll>nb,primes;

bool f(ll x){
   for(int i=2;i*i<=x;++i) if(x%i==0) return 0;
   return 1;
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   for(int i=2;i<=100;++i) if(f(i)) primes.pb(i);
   nb.resize(primes.size());

   ll n,d; cin >> n >> d;
   while(n || d){
      d=abs(d);
      for(int i=0;i<nb.size();++i) nb[i]=0;

      for(int i=2;i<=n;++i){
         ll tmp=i;
         for(int j=0;j<primes.size();++j) while(tmp % primes[j] == 0) tmp/=primes[j] , ++nb[j];
      }

      for(int j=0;j<primes.size();++j) while(d % primes[j] == 0) d/=primes[j] , --nb[j];

      ll ans = (d==1);
      foreach(it,nb) ans *= max(0ll,*it+1);

      cout << ans << endl;

      cin >> n >> d;
   }

   return 0;

}
