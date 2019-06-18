/**
* Store a DSU data structure for each prefix and suffix.
* For a query (l,r) we want to merge the two DSUs prefix[l-1] and suffix[r+1] and then we get the answer from the result.
*/
#include <bits/stdc++.h>
#define ULL unsigned long long
#define LL long long
#define LD long double
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define loop(i,a,b) for(int i=a;i<=b;++i)
#define pool(i,a,b) for(int i=a;i>=b;--i)
using namespace std; const int N = 10000 + 5, N2 = 500 + 5, LOG = 9 + 1; 

struct DSU{
	int rep[N2],sz[N2];
	DSU(){ for(int i=1; i<=N2; ++i) rep[i]=i ,sz[i]=1; }
	int find(int x) { return (rep[x]==x) ? x : rep[x] = find(rep[x]); }
	void unite(int x , int y){
		x=find(x),y=find(y); if(x==y) return;
    		sz[x] += sz[y]; rep[y] = x;
	}
} L[N],R[N];

pair<int,int> e[N];

signed main(){ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m; cin>>n>>m;
	loop(i,1,m){ cin>>e[i].F>>e[i].S; }
  
	loop(i,1,m) L[i]=L[i-1], L[i].unite(e[i].F,e[i].S);
	pool(i,m,1) R[i]=R[i+1], R[i].unite(e[i].F,e[i].S);
	
  	int k; cin>>k;
	while(k--){
		int l,r; cin>>l>>r;
		DSU res = L[l-1];
		loop(i,1,n) if(R[r+1].find(i)!=i) res.unite(i, R[r+1].find(i));
		int nb=0; loop(i,1,n) nb+=(res.find(i)==i);
		cout<<nb<<'\n';
	}
}
