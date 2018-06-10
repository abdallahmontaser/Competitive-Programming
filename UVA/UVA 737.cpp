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

/**
*The struct "form" represents a parallelepiped(because that's generally the result of the intersection of two cubes).
*I just begin with our first cube and keep storing the intersection with all the others.
*/

struct form{
   ll x; ll xd;
   ll y; ll yd;
   ll z; ll zd;
};

form intersection(form a,form b){
   form ans;

   ans.x=max(a.x,b.x);
   if((a.x+a.xd<=b.x+b.xd && b.x<=a.x) || (a.x+a.xd>=b.x+b.xd && b.x>=a.x)) ans.xd=min(a.xd,b.xd);
   else ans.xd=max(0ll,min(a.x+a.xd-b.x,b.x+b.xd-a.x));

   ans.y=max(a.y,b.y);
   if((a.y+a.yd<=b.y+b.yd && b.y<=a.y) || (a.y+a.yd>=b.y+b.yd && b.y>=a.y)) ans.yd=min(a.yd,b.yd);
   else ans.yd=max(0ll,min(a.y+a.yd-b.y,b.y+b.yd-a.y));

   ans.z=max(a.z,b.z);
   if((a.z+a.zd<=b.z+b.zd && b.z<=a.z) || (a.z+a.zd>=b.z+b.zd && b.z>=a.z)) ans.zd=min(a.zd,b.zd);
   else ans.zd=max(0ll,min(a.z+a.zd-b.z,b.z+b.zd-a.z));

   return ans;
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll n; cin >> n;
   while(n){
      form t[n];
      for(int i=0;i!=n;++i){
         ll xx,yy,zz,dd; cin >> xx >> yy >> zz >> dd;
         form a;
         a.x=xx , a.y=yy , a.z=zz , a.xd=dd , a.yd=dd , a.zd=dd;
         t[i]=a;
      }

      form ans=t[0];
      for(int i=1;i!=n;++i) ans=intersection(ans,t[i]);

      cout << (ll)ans.xd*ans.yd*ans.zd << endl;

      cin >> n;
   }

   return 0;

}
