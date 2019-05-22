/**
* Solved with segmentTree + lazy propagation.
* The idea is that if you have the sum of squares numbers in [i;j] = A_i² + A_i+1² + .... + A_j², and you're adding x,
* you can compute the sum of squares of (A + x)², it will be
*         sum(a_i²)   +   (j-i+1) * x²   +   2*sum(a_i)*x
*/
#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define int long long
using namespace std;
int a[100123];

class SEGTREE{
public:
	int n;
	int qL, qR, qVal;
	vector<int> st,en;
	vector<int> set, lz;
	vector<vector<int>> sum;
	SEGTREE(int nn){
		n = 1 << (int)ceil(log2(nn));
		int nb=n<<1;
		st.resize(nb), en.resize(nb);
		set.resize(nb), lz.resize(nb);
		sum.assign(nb, vector<int>(2));

		init(1, 1, n);
	}
	int compute_value(int i, int j){
		if(j==0) return !set[i]*sum[i][0] + lz[i]*(en[i]-st[i]+1);
		if(j==1) return !set[i]*(sum[i][1] + 2*lz[i]*compute_value(i,0)) + lz[i]*lz[i]*(en[i]-st[i]+1);
	}
	void update(int i){
		for(int ii: {i<<1, i<<1|1}) for(int j: {0,1})
			sum[ii][j]=compute_value(ii, j);
		
		for(int j: {0,1})
			sum[i][j] = sum[i<<1][j]+sum[i<<1|1][j];
	}
	void propagate(int i){
		if(set[i]){
			set[i<<1] = set[i<<1|1] = 1;
			lz[i<<1]  = lz[i<<1|1]  = lz[i];
		}
		else lz[i<<1]+=lz[i], lz[i<<1|1]+=lz[i];
		
		set[i]=lz[i]=0;
	}
	void init(int i, int start, int end){
		st[i]=start , en[i]=end;
		set[i]=lz[i]=0;
		if(start==end){
			sum[i][0]=a[start];
			sum[i][1]=a[start]*a[start];
			return;
		}
		int mid=(start+end)>>1;
		init(i<<1, start, mid);
		init(i<<1|1, mid+1, end);
		update(i);
	}
	int query(int i=1){
		if(en[i]<qL || qR<st[i]) return 0;
		if(qL<=st[i] && en[i]<=qR) return compute_value(i,1);
		propagate(i);
		return query(i<<1) + query(i<<1|1);
	}
	void add(int i, bool erase){
		if(en[i]<qL || qR<st[i]) return;
		if(qL<=st[i] && en[i]<=qR){
			if(!set[i]) set[i] = erase;
			lz[i] = !erase*lz[i] + qVal;
			return;
		}
		propagate(i);
		add(i<<1, erase); add(i<<1|1, erase);
		update(i);
	}
};


signed main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);	
	int tc; cin >> tc;
	for(int t=1; t<=tc; ++t){
		cout << "Case " << t << ":\n";
		int n,q; cin >> n >> q;
		for(int i=1; i<=n; ++i) cin >> a[i];
		SEGTREE seg(n);
		
		while(q--){
			int x; cin >> x;
			cin >> seg.qL >> seg.qR;
			if(x==2) cout << seg.query() << '\n';
			else{
				cin >> seg.qVal;
				seg.add(1, 1-x);
			}
		}
	}
return 0;
}
