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
* Since we're only allowed to remove elements from the last, the answer is n-(longest x such that a[1..x] is a subsequence of b[1..n]).
* 
* Editorial: http://codeforces.com/blog/entry/4540
/*

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll n; cin >> n;
   ll a[n]; for(int i=0;i<n;++i) cin >> a[i];
   ll b[n]; for(int i=0;i<n;++i) cin >> b[i];

   ll i=0,j=0;
   while(true){
      if(j==n) break;
      if(a[i]==b[j]) ++i,++j;
      else ++j;
   }

   cout << n-i << endl;

   return 0;

}
