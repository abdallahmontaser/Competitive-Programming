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
* I gathered all the pairs of "quality,price" (I inversed the input) of every type in a vector(see the vector of vectors "type")
* and sorted them in ascending order based on the quality.Then I binary search for the quality.
* Now, inside our binary search, either "mid" can't be reached(for atleast one type, all the qualities of it's components < mid)
* or it can be reached, and in that case we calculate the minimum budget we'll need to achieve a quality >= mid.For that I loop over every type
* and find the interval of it's components in which all qualities are >= mid, and I find the minimum price in them(that's what "type_min" is for). 
*/

ll n,budget;
ll ans;
vector<vector<pair<ll,ll> > >type;
vector<vector<ll> >type_min;

ll bsearch(vector<pair<ll,ll> >&v,ll x){
   ll tmp_ans=-1;
   ll i=0,j=v.size()-1;
   while(i<=j){
      ll mid=(i+j)/2;
      if(v[mid].first < x) tmp_ans=mid , i=mid+1;
      else j=mid-1;
   }
   return tmp_ans;
}

bool f(ll q){
   ll tmp_budget=0;

   for(int i=0;i!=type.size();++i){
      ll sz=type[i].size();
      vector<pair<ll,ll> >&v = type[i];
      vector<ll>&vmin = type_min[i];

      ll j=bsearch(v,q);

      if(j==sz-1) return 0;
      tmp_budget += vmin[j+1];
   }

   if(tmp_budget > budget) return 0;

   ans=q;
   return 1;
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   ll tc; cin >> tc;
   while(tc--){
      cin >> n >> budget;
      type.clear();
      type_min.clear();

      map<string,vector<pair<ll,ll> > >m;
      for(int i=0;i!=n;++i){
         string s1,s2;
         ll p,q;
         cin >> s1 >> s2 >> p >> q;
         m[s1].pb(mp(q,p));
      }

      foreach(it,m){
         type.pb(it->second);
         vector<pair<ll,ll> >& v=type[type.size()-1];
         sort(v.begin(),v.end());

         type_min.pb(vector<ll>(v.size()));
         vector<ll>& vmin=type_min[type_min.size()-1];

         vmin[vmin.size()-1]=v[v.size()-1].second;
         for(int i=vmin.size()-2;i>=0;--i) vmin[i]=min(vmin[i+1],v[i].second);
      }

      ll i=0,j=1e9;
      while(i<=j){
         ll mid=(i+j)/2;
         if(f(mid)) i=mid+1;
         else j=mid-1;
      }

      cout << ans << endl;
   }

   return 0;

}
