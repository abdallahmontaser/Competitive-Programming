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
const ll N=100005;
using namespace std;

/**
* Observe the answer string, it's either a string formed of 10 characters for which we know the occurences of all letters in it(just add the number
* of applications of every type from 'A' to 'Z') or a character "!" if none of the configurations work.
* So we can try all the possible combinations; there are 10!=3*10^6 ones, and verify if any one of them is possible.Else return "!".
* Construct the string by adding every letter from 'A' to 'Z' a number of times equal to the number next to that letter in every job description.
* If the string's size is more than 10 then it's impossible, else keep adding the character "_" until the string's size becomes equal to 10.
*/

vector<ll>v[26];

bool possible(string&s){
   for(int i=0;i<s.size();++i) if(s[i]!='_'){
      bool found=0;
      for(int j=0;j<v[s[i]-'A'].size();++j) if(v[s[i]-'A'][j] == i) found=1;
      if(!found) return 0;
   }
   return 1;
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   string line;
   while(getline(cin,line)){
      for(int i=0;i<26;++i) v[i].clear();
      
      string s;
      do{
         for(int i=1;i<=line[1]-'0';++i) s+=line[0];
         ll i=3;
         while(line[i]!=';') v[line[0]-'A'].pb(line[i]-'0') , ++i;
      }while(getline(cin,line) && line.size());

      string ans="!";
      if(s.size()<=10){
         while(s.size()<10) s+="_";
         sort(s.begin(),s.end());
         do{
            if(possible(s)) ans = s;
         }while(next_permutation(s.begin(),s.end()));
      }

      cout<<ans<<endl;
   }

	return 0;
}
