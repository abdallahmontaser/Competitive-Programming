/**
 * Explained solutions similar to this: https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/SPOJ/SPOJ_IOPC1207.txt
 * I also use 3 segment trees to find for each query the number of greens in each dimension
 * Then I first handle the case as if it was 2D (only x and y - line: 96)
 * Finally it shouldn't be hard to find the answer when adding the z dimension after that
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
class SEGTREE{
public:
	int n;
	int qL, qR;
	vector<int> st,en;
	vector<int> sum,lz;
	SEGTREE(int nn){
		n = 1 << (int)ceil(log2(nn));
		int nb=n<<1;
		st.resize(nb), en.resize(nb);
		sum.resize(nb), lz.resize(nb);

		init(1, 1, n);
	}
	void q(int a,int b){ qL=a , qR=b; }
	int value(int i){ return ((!lz[i])?sum[i]:en[i]-st[i]+1-sum[i]); }
	void update_up(int i){ sum[i] = value(i<<1) + value(i<<1|1); }
	void propagate_down(int i){
		if(lz[i]){
			lz[i<<1]   =  1-lz[i<<1];
			lz[i<<1|1] =  1-lz[i<<1|1];
			lz[i]=0;
		}
	}
	void init(int i, int start, int end){
		st[i]=start , en[i]=end;
		sum[i]=lz[i]=0;
		if(start==end) return;

		int mid=(start+end)>>1;
		init(i<<1, start, mid);
		init(i<<1|1, mid+1, end);
	}
	int query(int i=1){
		if(en[i]<qL || qR<st[i]) return 0;
		if(qL<=st[i] && en[i]<=qR) return value(i);
		propagate_down(i);
		int ans = query(i<<1) + query(i<<1|1);
		update_up(i);
		return ans;
	}
	void add(int i=1){
		if(en[i]<qL || qR<st[i]) return;
		if(qL<=st[i] && en[i]<=qR){
			lz[i]=1-lz[i];
			return;
		}
		propagate_down(i);
		add(i<<1); add(i<<1|1);
		update_up(i);
	}
};

signed main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	while(tc--){
		vector<SEGTREE> seg;
		for(int i=0; i<3; ++i){ int n; cin>>n; seg.push_back(SEGTREE(n)); }
		
		int q; cin >> q;
		while(q--){
			int tmp; cin >> tmp;
			if(tmp!=3){
				int a,b; cin >> a >> b , ++a , ++b;
				seg[tmp].q(a , b);
				seg[tmp].add();
			}else{
				pair<int,int> t[3];
				for(int i=0; i<3; ++i) cin>>t[i].F , ++t[i].F;
				for(int i=0; i<3; ++i) cin>>t[i].S , ++t[i].S;
				
				LL N[3],len[3];
				for(int i=0; i<3; ++i){
					N[i] = t[i].S-t[i].F+1;
					
					seg[i].q(t[i].F , t[i].S);
					len[i] = seg[i].query();
				}
				LL x = (LL)len[0]*N[1];
				LL y = (LL)len[1]*N[0];
				LL xy = x + y - 2*len[0]*len[1];

				LL ans = len[2]*(N[0]*N[1]-xy) + (N[2]-len[2])*xy;
				cout << ans << '\n';
			}
		}
	}
return 0;
}
