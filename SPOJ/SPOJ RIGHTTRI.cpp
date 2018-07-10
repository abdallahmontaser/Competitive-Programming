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
* For every point p, I looped through all the other points q!=p and stored all the vectors (p,q) in unit form.
* Then for every (p,q) I find the number of perpendicular vectors to it using binary search.
* A perpendicular vector to a vector (x,y) will be either (y,-x) or (-y,x).You need to only count one of them or divide the answer by 2
* when you finish looping on all points q.
* 
* Complexity: O(N²log(N))
* 
* See better solution(same complexity): https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/SPOJ/SPOJ_RIGHTTRI.cpp
*/

struct point{
   ld x,y;

	friend bool operator <(const point& A, const point& B) {
		return A.x < B.x - EPS || (A.x - B.x < EPS && A.y < B.y - EPS);
	}
};

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll n; cin >> n;
   point a[n]; for(int i=0;i<n;++i) cin >> a[i].x >> a[i].y;

   ll ans=0;
   for(int i=0;i<n;++i){
      vector<point>v;
      for(int j=0;j<n;++j) if(j!=i){
         ld xx = a[j].x-a[i].x , yy = a[j].y-a[i].y;
         ld d = sqrt(xx*xx + yy*yy);

         point p;
         p.x = xx/d , p.y = yy/d;
         v.pb(p);
      }

      sort(v.begin(),v.end());

      for(int j=0;j<v.size();++j){
         ld xx = v[j].x , yy = v[j].y;
         point p; p.x=yy , p.y=-xx;
         ans += upper_bound(v.begin(),v.end(),p)-lower_bound(v.begin(),v.end(),p);
      }
   }

   cout << ans << endl;

	return 0;
}
