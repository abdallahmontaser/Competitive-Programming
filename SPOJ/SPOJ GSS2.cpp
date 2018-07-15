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
* Fully explained solution: https://www.quora.com/How-can-the-SPOJ-problem-GSS2-be-solved
*/

struct node{
   ll curr;
   ll lazy;
   ll best;
   ll best_lazy;
};

ll n,nn;
ll a[N];
vector<node>seg;
ll ans[N];
map<ll,ll>last;
vector<pair<pair<ll,ll>,ll> >v;

ll val;
ll l,r;

ll query(ll i=1,ll st=1,ll en=nn){
   if(l > en || r < st) return 0ll;
	if(l <= st && en <= r) return seg[i].best;

   if(st != en)
      for(ll j=2*i;j<=2*i+1;++j){
         seg[j].best_lazy = max(seg[j].best_lazy , seg[j].lazy + seg[i].best_lazy);
         seg[j].best = max(seg[j].best , seg[j].curr + seg[i].best_lazy);
         seg[j].lazy += seg[i].lazy;
         seg[j].curr += seg[i].lazy;
      }

   seg[i].lazy = seg[i].best_lazy = 0ll;

	ll mid = (st+en)/2;

	return max(query(2*i,st,mid),query(2*i+1,mid+1,en));
}

void modify(ll i=1,ll st=1,ll en=nn){
	if(st > r || en < l) return;

	if(l <= st && en <= r){
		seg[i].curr += val;
		seg[i].lazy += val;
		seg[i].best_lazy = max(seg[i].best_lazy,seg[i].lazy);
		seg[i].best = max(seg[i].best,seg[i].curr);
		return;
	}

   if(st != en)
      for(ll j=2*i;j<=2*i+1;++j){
         seg[j].best_lazy = max(seg[j].best_lazy , seg[j].lazy + seg[i].best_lazy);
         seg[j].best = max(seg[j].best , seg[j].curr + seg[i].best_lazy);
         seg[j].lazy += seg[i].lazy;
         seg[j].curr += seg[i].lazy;
      }

   seg[i].lazy = seg[i].best_lazy = 0ll;

	ll mid = (st + en)/2;

	modify(2*i,st,mid);
	modify(2*i+1,mid+1,en);

	seg[i].curr = max(seg[2*i].curr , seg[2*i+1].curr);
}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // <<>>

   cin >> n;

   nn = pow(2,ceil(log2(n)));

   node x;
   x.curr = x.best = x.lazy = x.best_lazy = 0ll;
   seg.resize(2*nn,x);

   for(int i=1;i<=n;++i){
      cin >> a[i];
      last[a[i]] = 0;
   }

   ll q; cin >> q;
   for(int i=1;i<=q;++i){
      ll x,y; cin >> x >> y;
      v.pb(mp(mp(y,x),i)); // because we want to sort queries by their upper bound(in non-decreasing order)
   }

   sort(v.begin(),v.end());

   ll curr=0;
   for(int i=1;i<=n;++i){
      val = a[i];
      l = last[a[i]]+1 , r = i;
      modify();

      while(curr < q && i==v[curr].first.first){
         l = v[curr].first.second , r = i;
         ans[v[curr].second] = query();
         ++curr;
      }

      last[a[i]]=i;
   }

   for(int i=1;i<=q;++i) cout << ans[i] << endl;

	return 0;
}
