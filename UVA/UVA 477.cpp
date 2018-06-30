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
* My implementation was long and bad.I'm just not familiar yet with good geometry templates.
* For each point I just check it with every circle and verify whether the distance between the point and the center of the circle
* is < the radius of the circle.And for each rectangle, I sum the areas of the four triangles formed each time by the point and two other
* points of the rectangle, and compare it to the area of the rectangle.They need to be equal, and none of the four areas of the triangles
* should be 0.
*/

struct point{ld x,y;};

vector<pair<pair<point,point>,pair<point,point> > > r;
vector<ll>r2;

vector<pair<point,ld> > c;
vector<ll>c2;

ld dist(point a,point b){
   ld d = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
   return sqrt(d);
}

ld area(point a,point b,point c){
   ld d1=dist(a,b) , d2=dist(a,c) , d3=dist(b,c);
   ld p = (ld)(d1+d2+d3)/2;
   p = p*(p-d1)*(p-d2)*(p-d3);
   return sqrt(p);
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll n=0;
   string st; getline(cin,st);
   while(st[0]!='*'){
       ++n;
      istringstream iss(st);
      char ch; iss >> ch;
      
      if(ch=='r'){
         ld x1,y1,x2,y2; iss >> x1 >> y1 >> x2 >> y2;
         point p1,p2,p3,p4;
         p1.x=x1 , p1.y=y1;
         p2.x=x1 , p2.y=y2;
         p3.x=x2 , p3.y=y2;
         p4.x=x2 , p4.y=y1;
         r.pb(mp(mp(p1,p2),mp(p3,p4))); r2.pb(n);
      }else{
         point p;
         ld rad; iss >> p.x >> p.y >> rad;
         c.pb(mp(p,rad)) , c2.pb(n);
      }
      
      getline(cin,st);
   }
   
   getline(cin,st);
   n=0;
   while(st != "9999.9 9999.9"){
      point p;
      istringstream iss(st); iss >> p.x >> p.y;
      ++n;
      vector<ll>ans;

      ll i=-1;
      foreach(it,r){
         ++i;
         point a = (*it).first.first , b = (*it).first.second;
         point c = (*it).second.first , d = (*it).second.second;

         ld area1=area(p,a,b) , area2=area(p,b,c) , area3=area(p,c,d) , area4=area(p,d,a);
         if(area1!=(ld)0 && area2!=(ld)0 && area3!=(ld)0 && area4!=(ld)0){
            ld s = area1+area2+area3+area4;
            ld l = fabs(a.y-b.y)*fabs(b.x-c.x);
            if(fabs(s-l) < EPS) ans.pb(r2[i]);
         }
      }

      i=-1;
      foreach(it,c){
         ++i;
         if(dist((*it).first,p) < (*it).second) ans.pb(c2[i]);
      }
      
      if(!ans.empty()) sort(ans.begin(),ans.end());
      
      if(ans.empty()) cout << "Point " << n << " is not contained in any figure\n";
      else foreach(it,ans) cout << "Point " << n << " is contained in figure " << *it << endl;
      
      getline(cin,st);
   }

   return 0;

}
