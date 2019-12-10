#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define all(x) x.begin(), x.end()
const int inf = 2e9, mod = 998244353;
const int N = 1000 + 3, N2 = 5000 + 3, LOGN = 20;
//--
int n,m, t[N][N], correct[N][N], shouldPass[N]; set<int> chosenTests;
vector<pair<int,int> > passTimes; set<int> failIncorrectTests[N]; set<pair<int,int> > failTimes[N];
void removeTest(int ind){
	chosenTests.erase(ind);
	while(!passTimes.empty() && !chosenTests.count(passTimes.back().second)) passTimes.pop_back();
	for(int i = 1; i <= n; ++i) if(!shouldPass[i]) {
			failIncorrectTests[i].erase(ind);
			failTimes[i].erase({t[i][ind],ind});
		}
}
int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	while(tc--) {
		cin >> n >> m;
		for(int i = 1; i <= n; ++i) cin >> shouldPass[i];
		for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) cin >> t[i][j];
		for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) cin >> correct[i][j];

		int nbPass = count(shouldPass + 1,shouldPass + 1 + n,1);
		if(nbPass == 0) {
			cout << "YES\n";
			cout << 1 << " " << m << '\n';
			for(int i = 1; i <= m; ++i) cout << i << ' ';
			cout << '\n';
			continue;
		}

		chosenTests.clear();
		for(int i = 1; i <= m; ++i) {
			bool take = true;
			for(int subm = 1; subm <= n; ++subm) if(shouldPass[subm] && !correct[subm][i])
					take = false;
			if(take) chosenTests.insert(i);
		}
		if(chosenTests.empty()) {
			if(nbPass == n) {
				cout << "YES\n";
				cout << inf / 2 << " " << 0 << '\n';
				cout << '\n';
			} else cout << "NO\n";
			continue;
		}

		passTimes.clear();
		for(int i = 1; i <= n; ++i) if(shouldPass[i]) for(int j: chosenTests) passTimes.push_back({t[i][j],j});
		sort(all(passTimes));

		for(int i = 1; i <= n; ++i) if(!shouldPass[i]) {
				failIncorrectTests[i].clear();
				for(int j: chosenTests) if(!correct[i][j]) failIncorrectTests[i].insert(j);
			}

		for(int i = 1; i <= n; ++i) if(!shouldPass[i]) {
				failTimes[i].clear();
				for(int j: chosenTests) failTimes[i].insert({t[i][j],j});
			}

		while(!chosenTests.empty()) {
			int curTimeLimit = passTimes.back().first;
			bool done = true;
			for(int i = 1; i <= n; ++i) if(!shouldPass[i]) {
					if(!failIncorrectTests[i].empty()) continue;
					if(failTimes[i].rbegin()->first > curTimeLimit) continue;
					done = false;
				}
			if(done) break;

			removeTest(passTimes.back().second);
		}

		if(chosenTests.empty()) cout << "NO\n";
		else{
			int timeLimit = 1; for(auto p: passTimes) timeLimit = max(timeLimit,p.first);
			cout << "YES\n";
			cout << timeLimit << " " << chosenTests.size() << '\n';
			for(int test: chosenTests) cout << test << ' ';
			cout << '\n';
		}
	}
	return 0;
}
