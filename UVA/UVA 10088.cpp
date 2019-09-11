/**
  * Search for "Pick's theorem" if you don't know it.
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
const int N = 100 + 5, inf = 1e9;

const LD EPS = 1e-9, PI = acos(-1.0);
#define INF(A, B) (fabs((A) - (B)) > EPS && A < B)
#define SUP(A, B) (fabs((A) - (B)) > EPS && A > B)
#define EQU(A, B) (fabs((A) - (B)) < EPS)
struct point {
	LD X, Y;
	bool operator==(point &other) { return EQU(X, other.X) && EQU(Y, other.Y); }
	point operator+(point &other) { return point{X + other.X, Y + other.Y}; }
	point operator-(point &other) { return point{X - other.X, Y - other.Y}; }
};
LD crossProduct(const point &p1, const point &p2) { return p1.X * p2.Y - p1.Y * p2.X; }

LD polygonArea(vector<point> &polygon) {
	LD a = 0;
	loop(i, 0, sz(polygon) - 1) a += crossProduct(polygon[i], polygon[(i + 1) % sz(polygon)]);
	return a * 0.5;
}
LD nbBorderPoints(vector<point> &polygon) {
	LL nb = 0;
	loop(i, 0, sz(polygon) - 1) {
		point p1 = polygon[i], p2 = polygon[(i + 1) % sz(polygon)];
		nb += 1 + __gcd((int)abs(p1.X - p2.X), (int)abs(p1.Y - p2.Y));
	}
	return nb - sz(polygon);
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	while (cin >> n && n) {
		vector<point> polygon(n);
		loop(i, 0, n - 1) cin >> polygon[i].X >> polygon[i].Y;
		cout << (LL)(fabs(polygonArea(polygon)) - nbBorderPoints(polygon) * 0.5 + 1) << '\n';
	}
}
