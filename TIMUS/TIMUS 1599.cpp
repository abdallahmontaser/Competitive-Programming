/**
  * Must use int not long double or long long(only where it's necessary) in order to squeeze it.
  * Another code: https://github.com/AbdelrahmanRamadan/competitive-programming/blob/master/Timus/1599-Winding-Number.cpp
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

struct point {
	int X, Y;
	bool operator==(point &other) { return X == other.X && Y == other.Y; }
	point operator+(point &other) { return point{X + other.X, Y + other.Y}; }
	point operator-(point &other) { return point{X - other.X, Y - other.Y}; }
};
LL dotProduct(const point &p1, const point &p2) { return 1LL * p1.X * p2.X + 1LL * p1.Y * p2.Y; }
LL crossProduct(const point &p1, const point &p2) { return 1LL * p1.X * p2.Y - 1LL * p1.Y * p2.X; }
bool ccw(point &p, point &p1, point &p2) { return crossProduct(p1 - p, p2 - p) > 0; }
bool insideSegment(point &p, point &p1, point &p2) { return !crossProduct(p1 - p, p2 - p) && dotProduct(p - p1, p2 - p1) >= 0 && dotProduct(p - p2, p1 - p2) >= 0; }
int windingNumber(point &p, vector<point> &polygon) {
	int wn = 0;
	loop(i, 0, sz(polygon) - 1) {
		point p1 = polygon[i], p2 = polygon[(i + 1) % sz(polygon)];
		if (p1.Y <= p.Y && p.Y < p2.Y && ccw(p1, p2, p)) ++wn;
		if (p2.Y <= p.Y && p.Y < p1.Y && !ccw(p1, p2, p)) --wn;
	}
	return wn;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<point> track(n);
	loop(i, 0, n - 1) cin >> track[i].X >> track[i].Y;

	int m;
	cin >> m;
	loop(j, 1, m) {
		point p;
		cin >> p.X >> p.Y;

		bool onEdge = 0;
		loop(i, 0, n - 1) {
			point p1 = track[i], p2 = track[(i + 1) % n];
			onEdge |= insideSegment(p, p1, p2);
		}
		if (onEdge)
			cout << "EDGE\n";
		else
			cout << windingNumber(p, track) << '\n';
	}
}
