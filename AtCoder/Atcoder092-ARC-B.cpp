/**
* Editorial: https://img.atcoder.jp/arc092/editorial.pdf
* 
* My solution:
* For each bit, I compute the number of times it appears in the N² numbers and add 2^bit to the final answerif that number is odd(that's XOR)
* If we're at the k_th bit, let's go through all A_i.
* A_i + B_j gives 1 at the k_th bit iff one of these two statements is true:
*** Values of A_i and B_j at the k_th bit are different, and the sum of A_i[0..k-1] and B_j[0..k-1] in binary representation is < 2^k
*** Values of A_i and B_j at the k_th bit are the same,  and the sum of A_i[0..k-1] and B_j[0..k-1] in binary representation is >= 2^k
* 
* The first part is preprocessing.
*/

#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
using namespace std;
//<<>>
vector<pair<int,int>> v[29][2];
int nb[29][2];
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int a[n+1]; for(int i=1; i<=n; ++i) cin>>a[i];
	int b[n+1]; for(int i=1; i<=n; ++i) cin>>b[i];
	
	for(int bit=0; bit<=28; ++bit){
		map<int,int> map[2];
		for(int i=1; i<=n; ++i){
			int x = b[i]&((1<<bit)-1);
			bool bb = b[i]&(1<<bit);
			++map[bb][x];
			++nb[bit][bb];
		}

		for(int bb=0; bb<2; ++bb){
			for(const auto &p: map[bb]) v[bit][bb].push_back(p);
			for(int i=1; i<sz(v[bit][bb]); ++i) v[bit][bb][i].S += v[bit][bb][i-1].S;
		}
	}

	int ans=0;
	for(int bit=0; bit<=28; ++bit){
		LL t = 0;
		for(int i=1; i<=n; ++i){
			bool bb = a[i]&(1<<bit);
			int y = a[i]&((1<<bit)-1);
            
            auto it = lower_bound(all(v[bit][bb]), make_pair((1<<bit)-y , 0));
			if(it != v[bit][bb].begin()) t += nb[bit][bb] - (--it)->S;
			else t += nb[bit][bb];
            
			it = lower_bound(all(v[bit][1-bb]), make_pair((1<<bit)-y , 0));
			if(it != v[bit][1-bb].begin()) t += (--it)->S;
		}

		if(t%2 == 1) ans += (1<<bit);
	}
	
	cout<<ans<<'\n';
    return 0;
}
