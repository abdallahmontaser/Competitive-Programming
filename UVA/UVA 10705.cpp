#include <iostream>
#include<iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <iterator>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#include <limits>
#include <math.h>
#include <stdio.h>
#include <string.h>
#define MOD 1000000007
#define EPS 1e-15
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define endl '\n'
#define FOREACH(it,x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define FOR(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);++i)
#define ROF(i,a,b) for(ll i=(ll)(a);i>=(ll)(b);--i)
const ld PI=3.141592653589793238L;
const ll N=100005;
using namespace std;
//   <<>>

/**
* It's not hard to see that in the Fun-K number system, all the numbers between the Mn and Mx can be represented.
* Where Mn is the minimum number that can be represented(i.e. the sum of all powers i such that s[k-1-i]='n') and Mx is the maximum number
* that can be represented(i.e. the sum of all powers i such that s[k-1-i]='p').
* 
* So now, how to get the representation(it's unique of course) of n in this number system?
* 
* Let's start with Mx's representation(ans[i]='1' if s[i]='p' and '0' otherwise).And let diff = Mx - n.
* Now we need to "substract" diff from our current number(represented by the string ans).Just like the way you convert a number in base 10 to binary.
* 
* You go over the powers of 2, and if the current power pi <= diff, you take this power and subtract it from diff.
* That's what we'll be doing.How do we "take" a power pi ? If ans[i]='1'(meaning that s[i]='p') we just set it to '0'.And if ans[i]='0'
* (meaning that s[i]='n') we just set ans[i]='1'.The first way means we just subtracted pi from our ans, and the second means we added -pi.
* 
* It's always true that when we're at position i, all the rest of the representation(ans[i..k]) will have ans[j]='1' when s[j]='p' and '0' when s[j]='n'
* because we began with the representation of Mx at first.
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    ll tc; cin>>tc;
    while(tc--){
        ll k; cin>>k;
        string s; cin>>s;

        vector<unsigned ll>p; p.pb(1);
        FOR(i,1,k-1) p.pb(p[p.size()-1]<<1);

        unsigned ll mx=0,mn=0;
        FOR(i,0,k-1){
            if(s[i]=='p') mx += p[k-1-i];
            else mn += p[k-1-i];
        }

        ll n; cin>>n;
        unsigned ll x;
        if((n>0 && (x=n) > mx) || (n<0 && (x=(ll)-n) > mn)){
            cout<<"Impossible\n";
            continue;
        }

        string ans;
        FOR(i,0,k-1){
            if(s[i]=='p') ans += "1";
            else ans += "0";
        }

        unsigned ll diff=mx-n;
        FOR(i,0,k-1) if(diff >= p[k-1-i]){
             diff -= p[k-1-i];
             if(s[i]=='p') ans[i]='0';
             else ans[i]='1';
        }

        cout<<ans<<endl;
    }

    return 0;
}
