#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define y1 Y1
#define endl '\n'
#define foreach(it,x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
const ld PI =  3.141592653589793238L;
const ll N=100002;
using namespace std;

/**
* If one of the two endpoints of our segment is inside the rectangle, we return "T".
* Else we check for each one of the 4 segments of the rectangle if it intersects with our segment.
*/

ld x1,y1,x2,y2;

bool f3(ld mid,ld i,ld j){ // is 'mid' between 'i' and 'j' ??
   return min(i,j)<=mid && mid<=max(i,j);
}

bool f1(ld y,ld a,ld b){ // does our segment intersect with the vertical segment: [(a,y) ; (b,y)] ??
   ld x = ((y-y1)/(y2-y1))*(x2-x1) + x1;
   return f3(x,a,b) && f3(x,x1,x2) && f3(y,y1,y2);
}

bool f2(ld x,ld a,ld b){ // does our segment intersect with the vertical segment: [(x,a) ; (x,b)] ??
   ld y = ((x-x1)/(x2-x1))*(y2-y1) + y1;
   return f3(y,a,b) && f3(y,y1,y2) && f3(x,x1,x2);
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   int tc; cin >> tc;
   while(tc--){
      cin >> x1 >> y1 >> x2 >> y2;

      ld a,b,c,d; cin >> a >> b >> c >> d;

      bool ans;
      if(f3(x1,a,c) && f3(y1,b,d)) ans=1;
      else if(f3(x2,a,c) && f3(y2,b,d)) ans=1;
      else if(x1==x2){
         if(!f3(x1,a,c)) ans=0;
         else if(!f3(b,y1,y2) && !f3(d,y1,y2)) ans=0;
         else ans=1;
      }
      else if(y1==y2){
         if(!f3(y1,b,d)) ans=0;
         else if(!f3(a,x1,x2) && !f3(c,x1,x2)) ans=0;
         else ans=1;
      }
      else{
         ld aa=min(a,c) , cc=max(a,c);
         ld bb=min(b,d) , dd=max(b,d);
         ans = f1(bb,aa,cc) | f1(dd,aa,cc) | f2(aa,bb,dd) | f2(cc,bb,dd);
      }

      if(ans) cout << "T\n";
      else cout << "F\n";
   }

   return 0;

}
