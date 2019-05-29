/**
* Must be implemented smartly or it will be tedious.
* Good approach from the editorial: https://www.topcoder.com/tc?module=Static&d1=match_editorials&d2=srm392
* 
* I fix 'd' and 'msk', where d is the number of digits in the number we're searching for(divisor of size(n)) and msk
* will determine the digits we'll be using.
* f(n,v,i) is the smallest number possible if we keep all digits from 0 to i the same, and we still have the digits in
* the vector v to use. So now we either keep the ith digit the same as in N, or put the smallest digit we have that is bigger than it
* at this position then put all the rest in increasing order
*/
#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define loop(i,a,b) for(int i=a;i<=b;++i)
#define pool(i,a,b) for(int i=a;i>=b;--i)
using namespace std; const LL inf=2e18L;
LL p[19];

LL f(string& n, vector<int> v, int i){
	if(i==sz(n)) return 0;

	LL ans=inf;
	auto it = find(all(v),n[i]-'0');
	if(it!=end(v)){
		v.erase(it);
		ans = p[sz(n)-1-i]*(n[i]-'0') + f(n,v,i+1);
		v.push_back(n[i]-'0');
	}

	sort(all(v));
	it = upper_bound(all(v),n[i]-'0');
	if(it!=end(v)){
		LL tmp = (*it)*p[sz(n)-1-i];
		v.erase(it);
		loop(j,i+1,sz(n)-1) tmp += p[sz(n)-1-j]*v[j-(i+1)];
		ans = min(ans, tmp);
	}
	return ans;
}

class EquiDigitNumbers{
public:
	long long findNext(string n){
		if(n == "1"+string(18,'0')) return 1111111111111111111L;
		
    *p=1; loop(i,1,18) p[i]=p[i-1]*10;
    
		LL ans=inf;
		loop(d,1,10) if(sz(n)%d==0) loop(msk,0,(1<<10)-1) if(__builtin_popcount(msk)==d){
			int nb=sz(n)/d;
			vector<int> v;
			loop(i,0,9) if(msk&(1<<i)) loop(j,1,nb) v.push_back(i);
			ans = min(ans, f(n, v, 0));
		}
		return ans;
	}
};
