/**
* Editorial: https://codeforces.com/blog/entry/46662
* First solution is the same as this one. I didn't understand what he meant with the second one.
* 
* So, since we need to answer the queries(number of books after every operations) offline, let's draw a graph and connect the operations from 1 to Q.
* The nodes will be connected in such a way that each edge will be an operation(put a book, remove a book or flip row of books)
* The operation on the edge {i -> j} will be the j_th query operation, so we'll have to execute it before going to j, then print the number
* of books when we get there.
* The 4th type of query will simply denote an edge with no operation.
* 
* Now how will we construct the edges? First imagine there is no query of type 4. The edges will be {i -> i+1} for every i.
* Now if the i_the query is "4 x", it's independant from the query before it, but completely dependant from the state of our shelves
* after the x_th query. So when Q[i] = 4 x, we connect x to i with an edge(instead of connecting i-1 to i).
* That way we will have a directed tree and starting from 0, we can visit all nodes and apply every operation on an edge when we cross it
* but reverse the operation when we go back(since the 3 operations are reversible). This will let us keep only one copy of the shelves.
* 
* Used bitset to apply and reverse operations. See below.
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
using namespace std; const int N = 100000 + 5, LOG = 17 + 1;

vector<int> g[N]; int n,m,ans[N],sum;
bitset<1005> bs[1005],tmp_bs;

struct op{
	int type,a,b; bool useful=1;
	void apply(){
		if(type==1){
			if(bs[a][b]){ useful=0; return; }
			bs[a].set(b); ++sum;
		}
		if(type==2){
			if(!bs[a][b]){ useful=0; return; }
			bs[a].set(b,0); --sum;
		}
		if(type==3){
			sum-=bs[a].count();
			bs[a]^=tmp_bs;
			sum+=bs[a].count();
		}
	}
	
	void reverse(){
		if(!useful) return;
		if(type==1){ bs[a].set(b,0); --sum; }
		if(type==2){ bs[a].set(b); ++sum; }
		if(type==3){
			sum-=bs[a].count();
			bs[a]^=tmp_bs;
			sum+=bs[a].count();
		}
	}
};
map<pair<int,int>,op> e;

void dfs(int i){
	ans[i] = sum;
	for(int j: g[i]){
		e[{i,j}].apply();
		dfs(j);
		e[{i,j}].reverse();
	}
}

signed main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//<>
	int q; cin>>n>>m>>q;
	loop(i,1,m) tmp_bs.set(i);
	loop(i,1,q){
		op o; cin>>o.type>>o.a;
		if(o.type<=2) cin>>o.b;
		
		int before = (o.type==4) ? o.a : i-1;
		
		g[before].push_back(i), e[{before , i}]=o;
	}
	dfs(0);
	loop(i,1,q) cout<<ans[i]<<'\n';

}
