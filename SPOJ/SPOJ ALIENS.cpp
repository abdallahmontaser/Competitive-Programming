/**
  * Read: https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/SPOJ/SPOJ_ALIENS.txt
*/
#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
using namespace std;
const int N = 100000 + 5, inf = 1e9;

const LD EPS = 1e-9;
#define INF(A, B) (fabs((A) - (B)) > EPS && A < B)
#define SUP(A, B) (fabs((A) - (B)) > EPS && A > B)
#define EQU(A, B) (fabs((A) - (B)) < EPS)
struct point {
	LD X = 0, Y = 0;
	bool operator==(const point &other) { return EQU(X, other.X) && EQU(Y, other.Y); }
	point operator+(const point &other) { return point{X + other.X, Y + other.Y}; }
	point operator-(const point &other) { return point{X - other.X, Y - other.Y}; }
	point operator*(const LD &f) { return point{X * f, Y * f}; }
};
LD norm(const point &p) { return sqrtl(p.X * p.X + p.Y * p.Y); }
point center(point &a, point &b) { return (a + b) * 0.5; }
point perp(const point &p) { return point{p.Y, -p.X}; }
point intersectLines(const point &a, const point &b, const point &c, const point &d) {
	LD A1 = b.Y - a.Y, B1 = a.X - b.X, C1 = A1 * a.X + B1 * a.Y;
	LD A2 = d.Y - c.Y, B2 = c.X - d.X, C2 = A2 * c.X + B2 * c.Y;
	LD determinant = A1 * B2 - A2 * B1;

	if (EQU(determinant, 0)) return point{0, 0}; // parallel
	return point{(B2 * C1 - B1 * C2) / determinant, (A1 * C2 - A2 * C1) / determinant};
}
point findCircle(point &a, point &b, point &c) {
	return intersectLines(center(a, b), center(a, b) + perp(b - a), center(a, c), center(a, c) + perp(c - a));
}

int nbPoints, nbBorder; // start with n, 0
point pnts[N], border[3]; // start by shuffling the points
point C; LD R;
void minEnclosingCircle() {
	if (nbBorder == 3) { C = findCircle(border[0], border[1], border[2]), R = norm(C - border[0]); }

	else if (nbPoints == 0 && nbBorder <= 1) { C = border[0], R = 0; }

	else if (nbPoints == 0 && nbBorder == 2) { C = (border[0] + border[1]) * 0.5, R = norm(C - border[0]); }

	else {
		nbPoints--;
		minEnclosingCircle();

		if (norm(pnts[nbPoints] - C) > R) {
			border[nbBorder++] = pnts[nbPoints];
			minEnclosingCircle();
			nbBorder--;
		}
		nbPoints++;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		for (int i = 0; i < n; ++i) cin >> pnts[i].X >> pnts[i].Y;

		random_shuffle(pnts, pnts + n);
		nbPoints = n, nbBorder = 0;
		minEnclosingCircle();

		cout << fixed << setprecision(2) << R << '\n' << C.X << ' ' << C.Y << '\n';
	}
}
