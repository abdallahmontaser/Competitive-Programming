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

ld n,dist,s,g;

ld f2(ld x1,ld v1,ld x2,ld v2){
   if(fabs(x1-x2)<1e-9) return 0;
   return (ld)(x1*v2+x2*v1)/(v1+v2);
}

bool f(ld d){
   ld prev=0 , target_t=d/g+(dist-1-d)/s , t=0;
   for(int nn=0;nn<n;++nn){
      ld meet = f2(t*s,s,prev,g);
      ld target_d = (ld)(target_t - t + meet/g -(dist-1)/s) / ((ld)1/g - (ld)1/s);

      t+=(ld)(prev-meet+target_d-meet)/g;
      prev=target_d;
      if(t > target_t && fabs(t-target_t)>1e-9) return 0;
   }

   return 1;
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

    cin >> n >> dist >> s >> g;

   ld ans=0;
   ld i=0,j=dist-1;
   if(s<g) for(int cnt=1;cnt<=70;++cnt){
      ld d=(i+j)/2;
      if(f(d)) ans=d,i=d;
      else j=d;
   }

   cout << fixed << setprecision(9) << ans/g+(dist-1-ans)/s << endl;

   return 0;

}
