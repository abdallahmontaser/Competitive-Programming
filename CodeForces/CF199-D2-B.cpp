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
* It's easy to see that the answer is between 0 and 4 = maximum number of possible countours(number of circles we have).
* So we check if it's possible to draw the contour of each of our four circles(in the two rings).
* 
* For every one of the four circles, compare it with the other ring.
* Either the ring is completely inside this circle, or the circle is completely inside the ring, or the circle and the ring do not
* share any common area.In these three cases, we can add this circle's countour to our answer, else no.
* 
* Editorial: http://codeforces.com/blog/entry/4764
*/

struct circle{ ld x,y,r; };

bool f(circle a,circle b,circle c){
   ld d=(ld)sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
   if(d <= b.r-a.r) return 1;
   if(d <= a.r-c.r) return 1;
   if(d >= a.r+c.r) return 1;
   return 0;
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   circle t[4];

   cin >> t[0].x >> t[0].y >> t[0].r >> t[1].r;
   t[1].x=t[0].x , t[1].y=t[0].y;

   cin >> t[2].x >> t[2].y >> t[2].r >> t[3].r;
   t[3].x=t[2].x , t[3].y=t[2].y;

   ll ans=0;
   for(int i=0;i<4;++i){
      ll j,k;
      if(i==0||i==1) j=2,k=3;
      else j=0,k=1;

      if(f(t[i],t[j],t[k])) ++ans;
   }

   cout << ans << endl;

   return 0;

}
