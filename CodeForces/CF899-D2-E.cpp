/**
* Editorial: https://codeforces.com/blog/entry/56392
* I used DSU but it's not needed.
*/
#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
using namespace std;
class DSU{
	public:
	int n;
	vector<int> rep;
	DSU(int nn){
		n = nn;
		rep.resize(n+2);
		for(int i=0; i<=n+1; ++i) rep[i]=i;
	}
	int find(int x) {
    	if(x == rep[x]) return x;
    	return rep[x] = find(rep[x]);
	}
	void unite(int x , int y){
    	rep[find(y)] = find(x);
	}
};
set<pair<int,pair<int,int>>> s;
set<int> fst;
int nb[200123],t[200123];
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for(int i=1; i<=n; ++i) cin >> t[i];
	DSU dsu(n);

	int cur=t[1] , ind=1;
	for(int i=2; i<=n; ++i) if(t[i]!=cur){
		nb[ind] = i-ind;
		s.insert(mp(-nb[ind],mp(ind,ind+nb[ind]-1)));
		fst.insert(ind);
		for(int j=ind+1; j<=i-1; ++j) dsu.unite(ind,j);

		cur=t[i] , ind=i;
	}
	nb[ind] = n+1-ind;
	s.insert(mp(-nb[ind],mp(ind,ind+nb[ind]-1)));
	fst.insert(ind);
	for(int j=ind+1; j<=n; ++j) dsu.unite(ind,j);

	fst.insert(n+1);

	int ans=0;
	while(!s.empty()){
		++ans;
		
		int i=(*s.begin()).S.F , j=(*s.begin()).S.S;
		s.erase(*s.begin());
		fst.erase(i);

		int a=dsu.find(i-1) , b=*fst.upper_bound(i);
		dsu.unite(a,i);
		if(1<=a && b<=n && t[a]==t[b]){
			auto p1 = *s.upper_bound(mp(-nb[a],mp(a,0)));
			auto p2 = *s.upper_bound(mp(-nb[b],mp(b,0)));
			dsu.unite(a,b);
			nb[a] += nb[b];
			s.insert(mp(-nb[a],mp(a,p2.S.S)));
			s.erase(p1);
			s.erase(p2) , fst.erase(b);
		}
	}
	cout << ans << '\n';
    return 0;
}
