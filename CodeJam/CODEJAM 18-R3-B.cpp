// CODE STILL DOESN'T WORK - My algorithm for generating a "valid" graph randomly keeps failing forever, although the probability of
// it's failure according to the official editorial is low.
/**
* Problem link: https://codingcompetitions.withgoogle.com/codejam/round/0000000000007707/000000000004ba29
*/
#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
using namespace std;
//<<>>
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
class graph{
	public:
	int n;
	vector<vector<int>> e , tmp;
	graph(){}
	graph(int nn, bool construct){
		n = nn;
		e.resize(n+1 , vector<int>(n+1));
		tmp.resize(n+1 , vector<int>(n+1));
		for(int i = 1; i<=n; ++i) for(int j = 1; j <= n; ++j) e[i][j]=0 , tmp[i][j] == ((i == j) ? 1 : 0);

		vector<int> rand;
		for(int i=1; i<=n; ++i) for(int cnt=1; cnt<=4; ++cnt) rand.pb(i);
		
		if(construct)
		while(1){
		  //constructing the graph
			while(1){
				for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) e[i][j]=0;
				shuffle(all(rand), rng);
				
				vector<int> deg(n+1,0);
				bool valid=1;
				for(int i=0; i<sz(rand); i+=2){
					int u=rand[i] , v=rand[i+1];
					if(e[u][v]==1 || u==v){
						valid=0;
						break;
					}

					e[u][v] = e[v][u] = 1;
				}

				if(valid) break;
			}

		  //constructing the k_th adjacency matrix
			for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) tmp[i][j] == ((i == j) ? 1 : 0);
			for(int cnt=1; cnt<=7; ++cnt) this->mul();
		}
	}
	void mul(){
		vector<vector<int>> res(n+1,vector<int>(n+1,0));
		for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) for(int k = 1; k <= n; ++k){
			res[i][j] += tmp[i][k] * e[k][j];
		}

		swap(tmp, res);
	}
};
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	graph g1 = graph(10 , 1);
	return 0;

	int tc; cin >> tc;
	while(tc--){
		int L; cin >> L;
		if(L == -1) return 0;
		int R; cin >> R;
		
		int n = L;
		cout << n << endl;
		graph& G1 = g1;
		for(int i = 1; i <= n; ++i) for(int j = i+1; j <= n; ++j) if(G1.e[i][j] == 1) cout << i << " " << j << endl;

		cin >> n;
		graph G2 = graph(n,0);
		for(int cnt = 1; cnt <= 2*n; ++cnt){
			int a,b; cin >> a >> b;
			G2.e[a][b] = G2.e[b][a] = 1;
		}
		for(int cnt = 1; cnt <= 7; ++cnt) G2.mul();

		for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j){
			vector<int> v1(G1.tmp[i]); sort(all(v1));
			vector<int> v2(G2.tmp[j]); sort(all(v2));
			if(v1 == v2) cout << j << " ";
		}
		cout << endl;
	}
    return 0;
}
