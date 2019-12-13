#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define all(x) x.begin(), x.end()
const int inf = 2e9, mod = 1e9 + 7;
const int N = 1 * 1e5 + 1, N2 = 5000 + 3, LOGN = 16 + 1;
//--
struct BITlazy {
	int n; vector<LL> BIT1,BIT2;
	BITlazy(int _n){ n = _n; BIT1.assign(n + 1,0); BIT2.assign(n + 1,0);}
	void add(vector<LL>&b,int ind,int x){
		while(ind <= n) {
			b[ind] += x;
			ind += ind & (-ind);
		}
	}
	void rangeAdd(int l,int r, LL val){
		add(BIT1, l, val); add(BIT1, r + 1, -val);
		add(BIT2, l, val * (l - 1)); add(BIT2, r + 1, -val * r);
	}
	LL sum(vector<LL>&b,int ind){
		LL sum = 0;
		while(ind > 0) {
			sum += b[ind];
			ind -= ind & (-ind);
		}
		return sum;
	}
	LL prefixSum(int ind){return sum(BIT1,ind) * ind - sum(BIT2,ind);}
	LL rangeSum(int l, int r){ return prefixSum(r) - prefixSum(l - 1); }
};
int a[N]; set<int> zero[LOGN];
int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m; cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];

	vector<BITlazy> occ(LOGN,BITlazy(n));
	for(int j = 0; j < LOGN; ++j) {
		int bitOcc = 0;
		for(int i = n; i >= 1; --i) {
			if(a[i] & (1 << j)) ++bitOcc, occ[j].rangeAdd(i,i,bitOcc);
			else bitOcc = 0, zero[j].insert(i);
		}
		zero[j].insert({0,n + 1});
	}

	while(m--) {
		int i, x; cin >> i >> x;

		for(int j = 0; j < LOGN; ++j) if((x & (1 << j)) != (a[i] & (1 << j))) {
				auto it1 = prev(zero[j].lower_bound(i));
				int nbL = i - 1 - *it1;
				auto it2 = zero[j].upper_bound(i);
				int nbR = *it2 - 1 - i;

				bool has = (a[i] & (1 << j));
				int curBitOcc = (has ? 1 + nbR : 0);
				int newBitOcc = (has ? 0 : 1 + nbR);

				int diff = newBitOcc - curBitOcc;
				occ[j].rangeAdd(i - nbL, i,diff);
				if(diff) {
					if(!newBitOcc) zero[j].insert(i);
					if(!curBitOcc) zero[j].erase(i);
				}
			}

		a[i] = x;
		LL sum = 0;
		for(int j = 0; j < LOGN; ++j) sum += (LL)(1 << j) * occ[j].rangeSum(1,n);
		cout << sum << '\n';
	}
	return 0;
}
