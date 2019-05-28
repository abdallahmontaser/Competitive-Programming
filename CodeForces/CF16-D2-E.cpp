/**
* Old problem, from 2010. There's no editorial, here's the announcement: https://codeforces.com/blog/entry/422
* Used priority_queue to process the possible masks of fish, in decreasing order of their number in the mask so
* that if from a mask A, we can go to mask B(by killing a certain fish in A), A will come before B.
* 
* All the accepted codes I saw though just looped for the masks, I dont know how that would not create problems.
* 
* ans[mask] is the probability that we will reach that mask, that's the reason for lines 39 and 51.
* Being at a current mask A, we loop over all valid pairs of fish in that mask(let this pair be {x,y}, where x eats y),
* and we add a certain probability to the mask  B = (A without the fish y).
* That probability will be = [ prob(A) * prob(x eats y) / nb_possible_pairs ]
*/
#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define loop(i,a,b) for(int i=a;i<=b;++i)
#define pool(i,a,b) for(int i=a;i>=b;--i)
using namespace std; const int N=18;
int n;
LD beat[N+1][N+1], ans[1<<N];
vector<int> has[1<<N];

signed main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	loop(i,1,n) loop(j,1,n) cin>>beat[i][j];
	
  priority_queue<pair<int,int>> pq;
	loop(msk,0,(1<<n)-1){
		loop(i,1,n) if(msk&(1<<(i-1))) has[msk].push_back(i);
		pq.push({sz(has[msk]), msk});
	}
  
	ans[(1<<n)-1] = 1.;
	while(!pq.empty()){
		int msk = pq.top().S; pq.pop();
		LD possible_pairs=(sz(has[msk])*(sz(has[msk])-1))/2;
    
		for(int lose: has[msk]){
			LD sum=0;
			for(int any: has[msk]) sum += beat[any][lose]; 
			ans[msk - (1<<(lose-1))] += (ans[msk]*sum) / possible_pairs;
		}
	}
  
	loop(i,1,n) cout<<fixed<<setprecision(10)<<ans[1<<(i-1)]<<" \n"[i==n];
}
