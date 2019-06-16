/**
* First take all the shortest path and suppose they are actual direct edges in the graph we're seeking(worst case - n*(n-1)/2 edges)
* Go through all edges starting from the ones having the greatest weight.
* If there's another route from i to j other than (i,j) that gives a shorter distance than dist(i,j) then it's impossible.
* If there's another route from i to j other than (i,j) that gives an equal distance to dist(i,j) then remove this edge(useless edge).
* Print the rest of the edges.
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
using namespace std; const int N = 100 + 5, LOG = 9 + 1;

int dist[N][N]; vector<pair<int,pair<int,int>>> e;

signed main(){ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin>>tc;
	loop(t,1,tc){
		cout<<"Case #"<<t<<":\n";
		e.clear();
		int n; cin>>n;
		loop(i,1,n) loop(j,1,i-1){ cin>>dist[i][j]; dist[j][i]=dist[i][j]; e.push_back({dist[i][j],{i,j}}); }
    
/**  checking the impossible case  */
		bool impossible=0;
		loop(i,1,n) loop(j,1,i-1){
			loop(k,1,n) if(k!=i && k!=j && dist[i][k]+dist[k][j] < dist[i][j]) impossible = 1;
		}
		if(impossible){ cout<<"Need better measurements.\n\n"; continue; }

/**  removing useless edges       */
		sort(e.rbegin(),e.rend());
		vector<pair<int,int>> e2;
		for(auto edge: e){
			bool rmv=0;
			int i=edge.S.F, j=edge.S.S;
			loop(k,1,n) if(k!=i && k!=j && dist[i][k]+dist[k][j] == dist[i][j])
				rmv=1;
			if(!rmv) e2.push_back({min(i,j),max(i,j)});
		}
		
/**  printing the result         */
		sort(all(e2));
		cout<<sz(e2)<<'\n';
		for(auto edge: e2) cout<<edge.F<<' '<<edge.S<<' '<<dist[edge.F][edge.S]<<'\n';
		cout<<'\n';
	}
}
