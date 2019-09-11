/*
  * Official editorial: https://codeforces.com/blog/entry/62797
  * Other solution: https://github.com/nya-nya-meow/CompetitiveProgramming/blob/master/CodeForces/CF1043-D12-D.cpp
  * 
  * Mine is different than both(maybe close to the editorial's one).
  * Since all those subarrays are disjoint and must appear in every permutation, let's make an array nxt of sets.
  * For every permutation P, for every 1<=i<=n-1, we will add P[i+1] in nxt[P[i]]. Meaning in the end, nxt[x] will hold all
  * the y that came after x in atleast one permutation. For the last element in every permutation, we just add two random numbers(explained below).
  * It's clear now that all the elements of a  "correct subarray" will have a nxt[] having size 1.
  * So we just take the last permutation, and begin at every index trying to find the longest we can go, by taking the next number
  * only if the current number's nxt[] set's size is equal to 1.
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

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m; cin >> n >> m;
	set<int> nxt[n + 1];
	vector<int> order(n);
	loop(mm, 1, m) {
		loop(i, 0, n - 1) cin >> order[i];

		loop(i, 0, n - 2) {
			nxt[order[i]].insert(order[i + 1]);
			if (sz(nxt[order[i]]) > 1) nxt[order[i]] = {1, 2};
		}
		nxt[order[n - 1]] = {1, 2};
	}

	LL ans = 0;
	loop(i, 0, n - 1) {
		int nb = 1;
		while (sz(nxt[order[i]]) == 1) ++nb, ++i;
		ans += 1LL * nb * (nb + 1) / 2;
	}
	cout << ans << '\n';
}
