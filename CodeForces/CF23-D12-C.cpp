/**
* Editorial: https://codeforces.com/blog/entry/530
* Author further explaining the editorial: https://codeforces.com/blog/entry/530?#comment-124490
*/

#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
using namespace std;
//<<>>
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	while(tc--){
		int n; cin >> n;
		vector<tuple<int,int,int>> v(2*n-1 + 1);
		LL suma=0 , sumb=0;
		for(int i=1; i<=2*n-1; ++i){
			int a,b; cin >> a >> b;
			suma += a , sumb+= b;
			v[i] = make_tuple(a,b,i);
		}
		sort(all(v));

		LL a=0 , b=0;
		set<int> s;
		for(int i=1; i<=2*n-1; i+=2) a+=get<0>(v[i]) , b+=get<1>(v[i]) , s.insert(get<2>(v[i]));

		cout<<"YES\n";
		if(a >= (suma + 1)/2 && b >= (sumb + 1)/2){
			for(auto i: s) cout << i << " ";
			cout << "\n";
			continue;
		}
		
		s.clear();
		for(int i=2; i<=2*n-2; i+=2) s.insert(get<2>(v[i]));
		s.insert(get<2>(v[2*n-1]));
		for(auto i: s) cout << i << " ";
		cout << "\n";
	}
    return 0;
}
