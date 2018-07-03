#include<bits/stdc++.h>
#define MOD 1000000007
#define EPS 1e-9
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define endl '\n'
#define foreach(it,x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
const ld PI=3.141592653589793238L;
const ll N=300002;
using namespace std;

/**
* I explained my approach here: http://codeforces.com/blog/entry/60391
* when I was having trouble with some precision issues.
*/

ld solve(vector<ld>&v){
   ld elly=v[0];
   sort(v.rbegin(),v.rend());

   ld r = (v.size()+19)/20;

   ld sum=0; // this will contain the answer.
   ld curr=0;
   ld n=0;
   bool last=0;
   while(curr < v.size()){
      vector<ld>tmp;
      ++n;
      bool found=0;
      for(int i=curr;i<min((ld)v.size(),curr+r);++i){ if(v[i]==elly) found=1;  tmp.pb(v[i]);}
	
	curr += r;
	
      if(found) sum+=elly; // this group contains elly's rating
      else if(curr < v.size()) foreach(it,tmp) sum+=(ld)*it/r; // this isn't the last group
      else{
         last=1;
         ld sum1=sum; foreach(it,tmp) sum1+=(ld)*it/tmp.size();
         ld sum2=sum;
         
         ld p = tmp.size()/r , q = 1-p;
        
        sum1*=p , sum2*=q;
        
         sum = sum1/n  +  sum2/(n-1);
      }
}

   if(!last) sum /= n; // the last group contained elly's rating so we never entered the "else" section.

   return sum;
}

class EllysRoomAssignmentsDiv1{
   public: double getAverage(vector <string> ratings){
      string s="";
      foreach(it,ratings) s+=*it;

      vector<ld>v;
      istringstream iss(s);
      ld x;
      while(iss >> x) v.pb(x);

      return solve(v);
   };
};
