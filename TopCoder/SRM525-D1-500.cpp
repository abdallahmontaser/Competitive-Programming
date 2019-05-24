/**
* Editorial: https://apps.topcoder.com/wiki/display/tc/SRM+525
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
class Rumor{
public:
	int getMinimum(string knowledge, vector <string> graph){
		int n=sz(knowledge);
		const int inf = 1e9;

		int final_ans = inf;
		for(int mask=0; mask<(1<<n); ++mask){
			int fst[n],know[n][2],shared[n][2];
			for(int i=0; i<n; ++i){
				fst[i] = (mask&(1<<i)) == 0;
				shared[i][0] = shared[i][1] = 0;
				know[i][0] = know[i][1] = (knowledge[i]=='Y');
			}
			
			int days=0;
			while(true){
				bool done=1;
				vector<pair<int,bool>> cur;
				for(int x=0 ;x<n ;++x){
					if(know[x][fst[x]] && !shared[x][fst[x]]){
						shared[x][fst[x]] = 1;
						cur.push_back(mp(x,fst[x]));
					}
					else if(know[x][!fst[x]] && !shared[x][!fst[x]]){
						shared[x][!fst[x]] = 1;
						cur.push_back(mp(x,!fst[x]));
					}
				}

				for(auto p: cur) for(int i=0; i<n; ++i){
					if(graph[p.F][i]=='Y' && !know[i][p.S])
						done=0, know[i][p.S]=1;
				}
				
				if(done) break;
				++days;
			}
			bool valid=1;
			for(int i=0; i<n; ++i) valid&=know[i][0]*know[i][1];
			if(valid) final_ans = min(final_ans , days);
		}
		return final_ans==inf ? -1 : final_ans;
	}
};
