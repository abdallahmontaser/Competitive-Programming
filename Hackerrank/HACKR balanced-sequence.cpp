#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
#define ll long long
using namespace std;

/**
* Editorial: https://www.hackerrank.com/contests/world-codesprint-13/challenges/balanced-sequence/editorial
*/

int32_t main(){
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int n; cin >> n;
        string s; cin >> s;

        int x = 0 , y = 0;
        for(int i = 0; i < n; ++i){
              if(s[i] == '(') ++x;
              else if(x == 0) ++y;
              else --x;
        }

        cout << (x != 0) + (y != 0) << '\n';

        return 0;
}
