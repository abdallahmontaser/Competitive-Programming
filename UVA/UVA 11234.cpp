/**
* Draw the binary tree of the expression, the root will be the last Operator, it's left and right children
* will be it's left and right operands respectively in the expression. The leaves of the tree will be the lowercase letters(operands).
* Now with each node in the tree(character in the string) having a "level" (the root's level is 0),
* loop on the levels from the biggest to 0, and print each time all the characters in that level from right to left!
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
int a[10123],b[10123];
vector<string> lvl;
void dfs(string& s, int id, int l){
	lvl[l] += string(1,s[id]);
	if(a[id]!=b[id]){
		dfs(s,b[id],l+1);
		dfs(s,a[id],l+1);
	}
}
signed main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	while(tc--){
		string s; cin >> s;
		int n=sz(s);
		lvl.assign(n,"");
    
		stack<int> st;
		for(int i=0; i<n; ++i){
			if(islower(s[i])) a[i]=b[i]=i;
			else{
				b[i]=st.top(); st.pop();
				a[i]=st.top(); st.pop();
			}
			st.push(i);
		}
		dfs(s, n-1, 0);
		for(int i=n-1; i>=0; --i) cout << lvl[i];
		cout << '\n';
	}
return 0;
}
