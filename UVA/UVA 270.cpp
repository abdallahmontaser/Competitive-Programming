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
* Loop over the points, and for every point, check all other points and
* store the occurence of every possible slope of the two points.(Use a map)
* The answer should be 1 + maxOccurence.
* Don't forget the points which have the same x-coordinate.
*/

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll tc; cin >> tc;
   string s;
   getline(cin,s);

   bool first=1;
   while(tc--){
      if(!first) cout << endl;
      else getline(cin,s) , first=0;

      vector<pair<ld,ld> >v;

      while(getline(cin,s)){
         if(!s.size()) break;
         istringstream iss(s);
         ld x,y; iss >> x >> y;
         v.pb(mp(x,y));
      }


      ll ans=0;
      for(int i=0;i<v.size();++i){
         map<ld,ll>m1,m2;
         ll tmp=0;
         for(int j=0;j<v.size();++j) if(i!=j){
            ld x1=v[i].first,y1=v[i].second;
            ld x2=v[j].first,y2=v[j].second;

            if(x1!=x2) ++m1[(ld)(y2-y1)/(x2-x1)];
            if(x1==x2) ++m2[x1];
         }

         foreach(it,m1) tmp=max(tmp,1+it->second);
         foreach(it,m2) tmp=max(tmp,1+it->second);

         ans = max(ans,tmp);
      }

      cout << ans << endl;
   }

   return 0;

}
