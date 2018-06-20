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
* I store all the numbers formed of 4 digits that verify the conditions(5040 = 10*9*8*7 numbers) and, for every guess, I only keep those
* who give the same number of bulls and cows as the answer of that guess then
* I do the same for the next guesses with only those numbers.
* At the end, either there's only one number left(meaning one number that verifies all the pair of (bulls,cows) with all the guesses
* so that must be the number of the thinker in the first place.Either there are many numbers who verify, so we need more data.
* Or there's no number that verifies them all, so there MUST be an incorrect data.
* 
* Editorial: http://codeforces.com/blog/entry/1385
*/

pair<ll,ll> f(string&a,string&b){
   ll x=0,y=0;
   for(int i=0;i<4;++i) if(a[i]==b[i]) ++x;
   for(int i=0;i<4;++i) for(int j=0;j<4;++j) if(b[j]==a[i]) ++y,j=4;

   return mp(x,y-x);
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   vector<string>v;
   string s="";
   for(char a='0';a<='9';++a)
      for(char b='0';b<='9';++b) if(b!=a)
         for(char c='0';c<='9';++c) if(c!=a && c!=b)
            for(char d='0';d<='9';++d) if(d!=a && d!=b && d!=c){
               s+=a , s+=b , s+=c , s+=d;
               v.pb(s);
               s="";
            }

   ll n; cin >> n;
   vector<string>v2;
   while(n--){
      string s2; ll x,y;
      cin >> s2 >> x >> y;

      foreach(it,v) if(f(*it,s2) == mp(x,y)) v2.pb(*it);

      swap(v,v2);
      v2.clear();
   }

   if(!v.size()) cout << "Incorrect data";
   else if(v.size()==1) cout << v[0];
   else cout << "Need more data";

   cout << endl;

   return 0;

}
