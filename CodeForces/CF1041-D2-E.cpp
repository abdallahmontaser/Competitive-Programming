#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
const long double EPS = 1e-12L;
const int N = 200005 , MOD = 1000000007;
using namespace std;

/**
* Editorial: http://codeforces.com/blog/entry/61876
*/

int nb[1005];

void no(){
	cout << "NO\n";
	exit(0);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;

	set<int> missing;
	for(int i = 1; i <= n; ++i) missing.insert(i);

	vector<int> v;
	for(int i = 1; i <= n - 1; ++i){
		int a , b; cin >> a >> b;
		++nb[a];
		v.pb(a);
		
		if(b != n) no();

		if(missing.find(a) != missing.end()) missing.erase(a);
		if(missing.find(b) != missing.end()) missing.erase(b);
	}
	v.pb(n);
	sort(v.begin() , v.end());

	for(int i = 1; i <= n; ++i){
		nb[i] += nb[i - 1];
		if(nb[i] > i) no();
	}
	cout << "YES\n";
	
	int last = v[0];
	for(int i = 1; i < sz(v); ++i){
		if(v[i] > v[i - 1]){
			cout << last << " " << v[i] << '\n';
			last = v[i];
		}
		else{
			int x = *missing.begin();
			cout << last << " " << x << '\n';
			last = x;
			missing.erase(missing.begin());
		}
	}

    return 0;
}
