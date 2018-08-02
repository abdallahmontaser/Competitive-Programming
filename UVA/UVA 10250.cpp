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
* If you didn't find the solution re-read the problem statement carefully.
* Just rotate each tree 90 degrees around the center of the two trees of the input.
*/

void f(ld&x,ld&y){ // rotates(x,y) 45 degrees around the origin
   ld a=x,b=y;
   ld t=sqrt(2);
   x=(a-b)/t , y=(a+b)/t;
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ld x1,y1,x2,y2;
   while(cin>>x1>>y1>>x2>>y2){
      ld x=(x1+x2)/2 , y=(y1+y2)/2; // (x,y) is their center
      x1-=x , x2-=x;
      y1-=y , y2-=y;

      FOR(i,1,2) f(x1,y1) , f(x2,y2);

      cout<<fixed<<setprecision(10)<<x1+x<<' '<<y1+y<<' '<<x2+x<<' '<<y2+y<<endl;
   }

	return 0;
}
