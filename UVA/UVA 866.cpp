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
* Every time I find two intersecting segments, I erase them and push the 4 resulting segments, and repeat.
*
* Simpler and better solution: https://github.com/MeGaCrazy/CompetitiveProgramming/blob/master/UVA/UVA_866.cpp
*/

struct point{ld x,y;};

bool found;
point p;

bool f2(point p1,point p2){
    if(p1.x != p2.x) return 0;
    if(p1.y != p2.y) return 0;
    return 1;
}

void f(point p1,point p2,point p3,point p4){
    if(f2(p1,p3) || f2(p1,p4) || f2(p2,p3) || f2(p2,p4)) return;
   ld denom = (p4.x-p3.x)*(p1.y-p2.y) - (p1.x-p2.x)*(p4.y-p3.y);
   if(denom == (ld)0) return;
   
   ld t1 = ((p3.y-p4.y)*(p1.x-p3.x) + (p4.x-p3.x)*(p1.y-p3.y)) / denom;
   ld t2 = ((p1.y-p2.y)*(p1.x-p3.x) + (p2.x-p1.x)*(p1.y-p3.y)) / denom;
   
   if(t1 > (ld)1 || t1 < (ld)0) return;
   if(t2 > (ld)1 || t2 < (ld)0) return;
   
   found=1;
   p.x = p1.x + t1*(p2.x-p1.x);
   p.y = p1.y + t1*(p2.y-p1.y);
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   //freopen("t.txt","r",stdin); freopen("d.txt","w",stdout);
   // <<>>

   ll tc; cin >> tc;
   for(int t=1;t<=tc;++t){
      ll n; cin >> n;
      vector<pair<point,point> >v(n);
      for(int i=0;i<n;++i) cin >> v[i].first.x >> v[i].first.y >> v[i].second.x >> v[i].second.y;
      
      found=1;
      while(found){
         found=0;
         
         for(int i=0;!found&&i<v.size();++i) for(int j=i+1;!found&&j<v.size();++j){
            f(v[i].first,v[i].second,v[j].first,v[j].second);
            
            if(found){
               v.pb(mp(v[i].first,p));
               v.pb(mp(v[i].second,p));
               v.pb(mp(v[j].first,p));
               v.pb(mp(v[j].second,p));
               
               v.erase(v.begin()+j);
               v.erase(v.begin()+i);
            }
         }
      }
      
      if(t!=1) cout << endl;
      cout << v.size() << endl;
   }

   return 0;

}
