#include<bits/stdc++.h>
#define MOD 1000000007
#define EPS 1e-15
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define endl '\n'
#define foreach(it,x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
const ld PI=3.141592653589793238L;
const ll N=100002;
using namespace std;

/**
* For every string S, we can loop over all the strings that are dominated by this S(beside S itself), and mark them.
* Then go over the input strings in lexicographical order and print the ones that are not marked.
*/

map<string,ll>m;
string s;
ll t[26];

void f(ll i,vector<ll> v2){
   if(i==26){
      string s2="";
      for(int j=0;j<26;++j) for(int nb=1;nb<=v2[j];++nb) s2+=(char)('a'+j);
      if(s2.size()!=s.size()) m[s2]=1;
      
      return;
   }
   
   for(int j=0;j<=t[i];++j){
      vector<ll>v3(v2.begin(),v2.end());
      v3[i]=j;
      f(i+1,v3);
   }
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   vector<string>v;
   while(cin >> s){
      v.pb(s);
      for(int i=0;i<26;++i) t[i]=0;
      for(int i=0;i<s.size();++i) ++t[s[i]-'a'];
      vector<ll>v2(26);
      f(0,v2);
   }
    
    sort(v.begin(),v.end());
    
   for(int i=0;i<v.size();++i){
      string tmp(v[i]);
      sort(tmp.begin(),tmp.end());
      if(!m[tmp]) cout << v[i] << endl;
   }
    
	return 0;
}
