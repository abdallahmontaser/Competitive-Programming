#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define endl '\n'
#define foreach(it,x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
const ld PI =  3.141592653589793238L;
const ll N=100002;
using namespace std;

/**
* Recurse on every node in the tree, and when coming back, add as many "-" characters as the depth of the node(which is the "n" argument).
* Then on every root of every subtree, join the strings of it's children and sort them.
* It doesn't matter how you sort them, as long as you do the same for each root and it's children and for the two trees.It's just some sort
* of convention, to unite all the different representations of the same tree.
*/

ll pref[3000];

string f(string& s,ll n,ll i,ll j){
   string curr(s.begin()+i,s.begin()+j+1);
   bool found=0;
   for(int ii=i;ii<j;++ii) if(s[ii]=='1'&&s[ii+1]=='0') found=1;
   if(!found) return "0"+curr+"1";

   vector<ll>v;
   vector<string>v2;

   for(int ii=i;ii<=j;++ii) if(pref[ii]==n+1&&s[ii]=='0') v.pb(ii);
   v.pb(j+1);

   for(int ii=0;ii<v.size()-1;++ii){
      string tmp = f(s,n+1,v[ii]+1,v[ii+1]-2);
      v2.pb(tmp);
   }

   sort(v2.begin(),v2.end());

   string sss;
   for(int nb=1;nb<=n;++nb) sss+="-";

   string s2;
   foreach(it,v2) s2+=sss+*it; s2+=sss;

   return "0"+s2+"1";
}

ll ch(char c){
   if(c=='0') return 1;
   return -1;
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll tc; cin >> tc;
   while(tc--){
      string s1,s2; cin >> s1 >> s2;
      s1="0"+s1+"1" , s2="0"+s2+"1";

      pref[0]=1; for(int i=1;i<s1.size();++i) pref[i] = pref[i-1] + ch(s1[i]);
      s1 = f(s1,1,1,s1.size()-2);

      pref[0]=1; for(int i=1;i<s2.size();++i) pref[i] = pref[i-1] + ch(s2[i]);
      s2 = f(s2,1,1,s2.size()-2);

      if(s1==s2) cout << "same";
      else cout << "different";

      cout << endl;
   }

   return 0;

}
