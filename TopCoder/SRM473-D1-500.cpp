/**
  * Notice that the statement didn't mention the radius of the circle or any information on it AT ALL.
  * That's because those informations don't matter at all.
  * The perimeter of the circle is divided in 'places' equal parts and that's it.
  * 
  * A triangle with 3 points on a circle will be 'right' if two of it's points form a radius.
  * Go through the points, see if the other end of the radius starting at that point has a red point in it(it'll be unique of course)
  * If so, any other third point will form a right triangle with those two, so we add "points-2" to the answer.
  * Notice that we'll end up with double the real number, so we must divide by 2 at the end.
  * The other end of the radius of the point at place 0 will be places/2, 1 will be places/2 + 1 etc...
  * Now you can see that if places is odd, the answer will be 0.
*/
#include <bits/stdc++.h>
#define LL long long
#define F  first
#define S  second
#define sz(x)  (int)(x).size()
#define all(x) x.begin(), x.end()
using namespace std;
const int N = 100000 + 5, inf = 1e9;

class RightTriangle {
	long long triangleCount(int places, int points, int a, int b, int c) {
		if (places % 2 == 1) return 0;
    
    set<int> left; for (int i = 0; i < places; ++i) left.insert(i);
    set<int> put;
		
    for (int i = 0; i < points; ++i) {
			int pos = (1LL * a * i * i + 1LL * b * i + c) % places;
			
      auto it = left.lower_bound(pos);
			if (it != left.end()) put.insert(*it), left.erase(it);
			else put.insert(*left.begin()), left.erase(left.begin());
		}
		LL ans = 0;
		for (int p: put) if (put.count(p + places / 2) || put.count(p - places / 2)) ans += points - 2;
		return ans >> 1;
	}
};
