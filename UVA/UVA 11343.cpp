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

struct point{ld x,y;};

bool between(ld mid,ld ii,ld jj){ // is 'mid' inside [i,j] ??
   ld i=min(ii,jj),j=max(ii,jj);
   return (i<mid||fabs(mid-i)<EPS) && (mid<j||fabs(mid-j)<EPS);
}

bool f3(ld x,ld a,ld b,point p1,point p2){  // does the segment [p1,p2] intersect with the vertical segment: [(a,y) ; (b,y)] ??
   ld y = ((x-p1.x)/(p2.x-p1.x))*(p2.y-p1.y) + p1.y;
   return between(y,a,b) && between(y,p1.y,p2.y) && between(x,p1.x,p2.x);
}

bool f2(point a1,point a2,point b1,point b2){
   ld ma=(a2.y-a1.y)/(a2.x-a1.x) , mb=(b2.y-b1.y)/(b2.x-b1.x);

   if(fabs(ma*(b1.x-a1.x)+a1.y - b1.y) >= EPS) return 0; // b1 isn't aligned with a1 and a2
   if(fabs(ma*(b2.x-a1.x)+a1.y - b2.y) >= EPS) return 0; // b2 isn't aligned with a1 and a2

   // the four points are aligned, so we need to check if the two segments intersect, which can be done by checking
   // if b1 is between a1 and a2, or if b2 is between a1 and a2 or
   // if a1 is between b1 and b2, or if a2 is between b1 and b2.

   return between(a1.x,b1.x,b2.x) || between(a2.x,b1.x,b2.x) || between(b1.x,a1.x,a2.x) || between(b2.x,a1.x,a2.x);
}

bool f(point a1,point a2,point b1,point b2){
   if(a1.x==a2.x && b1.x==b2.x){ // two vertical segments
      if(a1.x != b1.x) return 0;
      return between(a1.y,b1.y,b2.y) || between(a2.y,b1.y,b2.y) || between(b1.y,a1.y,a2.y) || between(b2.y,a1.y,a2.y);
   }

   if(a1.x==a2.x) return f3(a1.x,a1.y,a2.y,b1,b2); // [a1,a2] is vertical
   if(b1.x==b2.x) return f3(b1.x,b1.y,b2.y,a1,a2); // [b1,b2] is vertical

   ld ma=(a2.y-a1.y)/(a2.x-a1.x) , mb=(b2.y-b1.y)/(b2.x-b1.x);

   if(fabs(ma-mb) < EPS) return f2(a1,a2,b1,b2); // [a1,a2] is parallel to [b1,b2]

   ld x = ((ma*a1.x-a1.y) - (mb*b1.x-b1.y)) / (ma-mb);
   ld y = ma*(x-a1.x) + a1.y;

   return between(x,a1.x,a2.x) && between(y,a1.y,a2.y) && between(x,b1.x,b2.x) && between(y,b1.y,b2.y);
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll tc; cin >> tc;
   while(tc--){
      ll n; cin >> n;
      pair<point,point> a[n];
      for(int i=0;i<n;++i) cin >> a[i].first.x >> a[i].first.y >> a[i].second.x >> a[i].second.y;

      ll ans=0;
      for(int i=0;i<n;++i){
         bool tmp=0;
         for(int j=0;j<n;++j) if(i!=j) tmp |= f(a[i].first,a[i].second,a[j].first,a[j].second);
         if(!tmp) ++ans;
      }

      cout << ans << endl;
   }

   return 0;

}
