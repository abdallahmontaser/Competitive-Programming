#include <bits/stdc++.h>
#define ULL unsigned long long
#define LL long long
#define LD long double
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define loop(i, a, b) for (int i = a; i <= b; ++i)
#define pool(i, a, b) for (int i = a; i >= b; --i)
using namespace std;
const int N = 100 + 5, INF = 1e9;
const LD EPS = 1e-9;

class point {
  public:
	LD X, Y;
	bool operator==(point &other) { return fabs(X - other.X) < EPS && fabs(Y - other.Y) < EPS; }
};

LD polygonArea(vector<point> &v) {
	LD a = 0;
	loop(i, 0, sz(v) - 1) a += v[i].X * v[(i + 1) % sz(v)].Y - v[(i + 1) % sz(v)].X * v[i].Y;
	return a * 0.5;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1;
	while (true) {
		int n = 4;
		vector<point> poly(n);
		loop(i, 0, n - 1) cin >> poly[i].X >> poly[i].Y;

		bool last = 1;
		loop(i, 0, n - 1) if (poly[i].X != 0 || poly[i].Y != 0) last = 0;
		if (last) break;

		cout << "Cake " << tc++ << ": ";

		vector<point> tmp;
		tmp.pb(poly[0]);
		loop(i, 1, n - 1) tmp.pb(point{0.5 * (poly[i - 1].X + poly[i].X), 0.5 * (poly[i - 1].Y + poly[i].Y)}), tmp.pb(poly[i]);
		tmp.pb(point{0.5 * (poly[n - 1].X + poly[0].X), 0.5 * (poly[n - 1].Y + poly[0].Y)});
		swap(tmp, poly);

		LD bestDiff = INF, best1, best2;
		for (auto p1 : poly) for (auto p2 : poly)
				if (!(p1 == p2)) {
					vector<point> right, left;
					for (auto p : poly) {
						if (p == p1 || p == p2)
							right.pb(p), left.pb(p), swap(right, left);
						else
							right.pb(p);
					}
					LD a1 = polygonArea(right), a2 = polygonArea(left);
					if (a1 < a2) swap(a1, a2);
					if (a1 - a2 < bestDiff) bestDiff = a1 - a2, best1 = a1, best2 = a2;
				}

		cout << fixed << setprecision(3) << best2 << " " << best1 << '\n';
	}
}
