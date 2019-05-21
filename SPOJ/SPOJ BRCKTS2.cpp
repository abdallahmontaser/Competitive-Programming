/**
* First find c[i] for every opening bracket on index i. It will be the index of it's closing character.
* Now for a segment [i ; c[i]], it's length will be (the number of characters in it - 1) = (c[i]-i) and it's width will be it's depth.
* Recursively, the depth of a segment is 1 + max_depth of all it's subsegments.
* f(i,x) is the answer for the segment [i ; c[i]] multiplied by x. x can be 1 or -1.
* It's computed recursively as the surface of the surface of [i ; c[i]] multiplied by x + sum of f(j,-x) on all subsegments [j ; c[j]] inside it.
* Finally, loop over all first segments [i ; c[i]] of the string and add f(i,1).
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
int c[400123],memo[400123];
string s;
int depth(int i){
	if(memo[i] != -1) return memo[i];
	int ans=0;
	for(int j=i+1; j<c[i]; j=c[j]+1) ans = max(ans,depth(j));
	return memo[i] = 1 + ans;
}
LL f(int i, int x){
	LL ans = (LL) x*(c[i] - i)*depth(i);
	for(int j=i+1; j<c[i]; j=c[j]+1) ans += f(j, -x);
	return ans;
}
signed main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	while(tc--){
		cin >> s;
		stack<int> st;
		for(int i=0; i<sz(s); ++i){
			if(s[i]=='(') st.push(i);
			else c[st.top()] = i , st.pop();
		}
		memset(memo,-1,sizeof(memo));
		LL ans=0;
		for(int i=0; i<sz(s); i=c[i]+1) ans += f(i, 1);
		cout << ans << '\n';
	}
return 0;
}
