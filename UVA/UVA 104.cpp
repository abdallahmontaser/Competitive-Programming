/**
* cost[L][A][B] is the maximum profit you can get in a path of length L starting at A and ending at B.(Till now by 'path' we mean the normal path, doesnt have to end at A)
* We fill it using FloydWarshall then, having a convenient start country and length of path(if non exist return that it's impossible)
* find at each step a convenient next country.
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
using namespace std; const int N = 20 + 5, LOG = 9 + 1;

LD cost[N][N][N];

signed main(){ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	while(cin>>n){
		loop(a,1,n) loop(b,1,n) loop(c,1,n) cost[a][b][c]=0;

/** Read input and compute the dp using FloydWarshall  */
		loop(i,1,n) loop(j,1,n){ if(i==j) cost[1][i][j]=0.; else cin>>cost[1][i][j]; }
		loop(len,2,n-1) loop(i,1,n) loop(j,1,n){
			loop(k,1,n) cost[len][i][j] = max(cost[len][i][j], cost[len-1][i][k]*cost[1][k][j]);
		}

/** Find any starting node or return that none exist  */
		int l=0, st;
		loop(len,1,n-1) loop(i,1,n) loop(j,1,n)
			if(cost[len][i][j]*cost[1][j][i] > 1.01 && l==0)
				l=len, st=i;
		if(l==0){ cout<<"no arbitrage sequence exists\n"; continue; }

/** Find a correct path  */
		vector<int> v={st};
		LD cur=1.01;
		while(l){
			int nxt;
			loop(i,1,n) if(cost[l][st][i] * cost[1][i][v.back()] > cur) nxt=i;
			cur /= cost[1][nxt][v.back()];
			v.push_back(nxt);
			--l;
		}
/** Print it  */
		v.push_back(st); reverse(all(v));
		loop(i,0,sz(v)-1) cout<<v[i]<<" \n"[i==sz(v)-1];
	}
}
