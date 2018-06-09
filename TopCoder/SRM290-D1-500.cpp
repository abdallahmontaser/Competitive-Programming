#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define endl '\n'
const ld PI =  3.141592653589793238L;
const ll N=1000002;
using namespace std;

class SnailRace {
	public: double shortestTime(int aa, int bb, int cc, int dd) {
		ld n=aa,dist=bb,s=cc,g=dd;

	   ld i=0,j=dist-1,d=0;
	   if(s<g) for(int cnt=1;cnt<=50;++cnt){
	      d=(i+j)/2;
	      ld t=(ld)(2.0*d)/(g+s);
	      if(t*(n-1)*s + d < dist-1) i=d;
	      else j=d;
	   }

	   ld f=d/g+(dist-1-d)/s;
	   return f;
	}
};
