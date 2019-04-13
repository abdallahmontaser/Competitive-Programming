#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
#define ll long long
#define ld long double
#define all(x) x.begin(),x.end()
using namespace std;
map<set<int>,int> m1;
map<int,set<int>> m2;
int id;
void check(set<int>& s){
      if(m1[s]) return;
      ++id;
      m1[s] = id;
      m2[id] = s;
}
int32_t main(){
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      int tc; cin >> tc;
      while(tc--){
            int n; cin >> n;
            m1.clear() , m2.clear() , id = 0;
            stack<int> st;
            while(n--){
                  string s; cin >> s;
                  if(s == "PUSH"){
                        set<int> tmp;
                        check(tmp);
                        st.push(m1[tmp]);
                  }
                  if(s == "DUP") st.push(st.top());
                  if(s == "UNION"){
                        set<int>& a = m2[st.top()]; st.pop();
                        set<int>& b = m2[st.top()]; st.pop();
                        set<int> c;
                        set_union(all(a) , all(b) , inserter(c,c.begin()));
                        check(c);
                        st.push(m1[c]);
                  }
                  if(s == "INTERSECT"){
                        set<int>& a = m2[st.top()]; st.pop();
                        set<int>& b = m2[st.top()]; st.pop();
                        set<int> c;
                        set_intersection(all(a) , all(b) , inserter(c,c.begin()));
                        check(c);
                        st.push(m1[c]);
                  }
                  if(s == "ADD"){
                        set<int>& a = m2[st.top()]; st.pop();
                        set<int>& b = m2[st.top()]; st.pop();
                        set<int> c(all(b));
                        c.insert(m1[a]);
                        check(c);
                        st.push(m1[c]);
                  }

                  cout << sz(m2[st.top()]) << '\n';
            }
            cout << "***\n";
      }
      return 0;
}
