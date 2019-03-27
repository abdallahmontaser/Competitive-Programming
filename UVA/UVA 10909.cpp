#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
#define ll long long
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

/**
* You need to simulate the process of building the sequence.
* For that you need a data structure that supports finding the "k-th element" and erasing an element in short time.
* i.e. a balanced tree.
* 
* Then for each integer N, if N is odd then there's no answer(since all the elements in the sequence are odd)
* else loop from the smallest integer X >= N/2 till the end of the sequence, and stop if N - X is in the sequence or if X >= N.
* The sequence is dense enough for an answer to be found in short time for every even number.
* 
* Solution with an implementation of a balanced tree:
*      https://github.com/pin3da/Programming-contest/blob/master/solved/UVa/10909%20-%20Lucky%20Number/solution.cc
*/

bool a[2000005];

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ordered_set s;
	for(int i = 1; i <= 2000000; i += 2) s.insert(i) , a[i] = 1;

	for(int i = 3; i <= 2000000; ++i) if(a[i] == 1){
		int nb = 1;
		while(1){
			auto it = s.find_by_order(i * nb - (nb - 1)  -  1);
			if(it == s.end()) break;

			++nb;
			a[*it] = 0;
			s.erase(it);
		}
	}

	vector<int> v;
	for(auto x: s) v.pb(x);

	int n;
	while (cin >> n) {
		if (n % 2 == 1) {
			cout << n << " is not the sum of two luckies!" << '\n';
			continue;
		}

		int i = lower_bound(v.begin(), v.end(), n / 2) - v.begin();
		while(a[n - v[i]] == 0) ++i;
		cout << n << " is the sum of " << n - v[i] << " and " << v[i] << "." << '\n';
	}

	return 0;
}
