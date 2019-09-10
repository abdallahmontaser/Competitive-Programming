/**
  * Polygons can be convex and convave, your functions must all work for both.
*/
#include <bits/stdc++.h>
#define ULL unsigned long long
#define LL long long
#define LD long double
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define loop(i, a, b) for (int i = a; i <= b; ++i)
#define pool(i, a, b) for (int i = a; i >= b; --i)
using namespace std;
const int N = 100 + 5, INF = 1e9;

const LD EPS = 1e-9;
#define fCMP(A, B) ((fabs(A - B) < EPS) ? 0 : ((A < B) ? -1 : 1))
class point {
  public:
	LD X, Y;
	LD norm() { return sqrtl(X * X + Y * Y); }
	bool operator==(point other) { return fCMP(X, other.X) == 0 && fCMP(Y, other.Y) == 0; }
	point operator+(point other) { return point{X + other.X, Y + other.Y}; }
	point operator-(point other) { return point{X - other.X, Y - other.Y}; }
	LD crossProduct(point other) { return X * other.Y - other.X * Y; }
	bool ccw(point p1, point p2) { return fCMP((p1 - *this).crossProduct(p2 - *this), 0) == 1; }
	bool insidePolygon(vector<point> &polygon) {
		int windingNumber = 0;
		loop(i, 0, sz(polygon) - 1) {
			point p1 = polygon[i], p2 = polygon[(i + 1) % sz(polygon)];
			if (fCMP(p1.Y, Y) != 1 && fCMP(Y, p2.Y) == -1 && p1.ccw(p2, *this)) ++windingNumber;
			if (fCMP(p2.Y, Y) != 1 && fCMP(Y, p1.Y) == -1 && !p1.ccw(p2, *this)) --windingNumber;
		}
		return windingNumber != 0;
	}
};

LD polygonArea(vector<point> &polygon) {
	LD a = 0;
	loop(i, 0, sz(polygon) - 1) a += polygon[i].crossProduct(polygon[(i + 1) % sz(polygon)]);
	return a * 0.5;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		int nbPolygons;
		cin >> nbPolygons;
		vector<pair<int, vector<point>>> polygons;
		loop(i, 1, nbPolygons) {
			int id;
			cin >> id;

			string s;
			getline(cin, s);
			istringstream iss(s);
			vector<point> v;
			LD X, Y;
			while (iss >> X >> Y) v.push_back(point{X, Y});
			if (fCMP(polygonArea(v), 0) == -1) reverse(all(v));

			polygons.push_back({id, v});
		}
		sort(all(polygons), [](auto &a, auto &b) { return fCMP(polygonArea(a.S), polygonArea(b.S)) == -1; });

		int nbPoints;
		cin >> nbPoints;
		vector<pair<int, int>> ans;
		loop(i, 1, nbPoints) {
			int id;
			LD x, y;
			cin >> id >> x >> y;

			int targetPolygon = 0;
			for (auto element : polygons)
				if (point{x, y}.insidePolygon(element.S)) {
					targetPolygon = element.F;
					break;
				}

			ans.push_back({id, targetPolygon});
		}
		sort(all(ans));
		for (auto element : ans) cout << element.F << ' ' << element.S << '\n';

		if (tc) cout << '\n';
	}
}
