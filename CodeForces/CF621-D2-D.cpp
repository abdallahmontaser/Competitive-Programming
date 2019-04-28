/**
* Editorial: https://codeforces.com/blog/entry/23196
* 
* My code might be messy, but here's the explanation.
* First of all; 4 is the same as 3, 8 is the same as 7 and 12 is the same as 11. So we'll ignore them(since we want the smallest index)
* The numbers are too big to be stored, so we will use logs to compare them since they are too big, but there's a catch(we can't immediatly use log on all of them, read below).
* 
* I will divide the numbers into three parts, ones that are equal to 1, ones that are bigger than 1 and the rest that are smaller.
* Basic maths, A^B is
*** equal to 1 if A is equal to 1
*** bigger than 1 if A is bigger than 1
*** smaller than 1 if A is smaller than 1
* 
* For the first part, we'll need the smallest index of them.
* For the second part, we'll compare their log(log()) values, which will at most be 200*log(200) + log(log(200)) for the case 200^200^200, which isn't big.
* For the third part, we will use "nlog" which I defined below. Why? because if we take the log(X) will be negative when X < 1 so we can't do log(log(X)). But with the log to the base of something in ]0;1[ like 0.5, we can. Since it's sign will be the opposite to the regular based logs. nlog(X) > 0 when X < 1 and nlog(X) <= 0 when X >= 1.
* 
* I separated the numbers equal to 1, because any log will give 0 when X = 1, and we can't log it again since log(0) is undefined.
*/

#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
using namespace std;
bool cmp(pair<LD,int> a , pair<LD,int> b){
	if(fabs(a.F - b.F) < (LD)1e-9) return a.S > b.S;
	return a.F < b.F;
}
LD nlog(LD x){
	return log(x)/log((LD)0.5);
}
signed main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	map<int,string> ans;
	ans[1] = "x^y^z";
	ans[2] = "x^z^y";
	ans[3] = "(x^y)^z";
	ans[5] = "y^x^z";
	ans[6] = "y^z^x";
	ans[7] = "(y^x)^z";
	ans[9] = "z^x^y";
	ans[10] = "z^y^x";
	ans[11] = "(z^x)^y";

	LD x,y,z; cin >> x >> y >> z;
	vector<pair<LD,int>> vx={mp(log(y)+log(z),3) , mp(y*log(z),2) , mp(z*log(y),1)};
  sort(all(vx),cmp);
  if(x < (LD)1) reverse(all(vx));
	
  vector<pair<LD,int>> vy={mp(log(x)+log(z),7) , mp(x*log(z),6) , mp(z*log(x),5)};
  sort(all(vy),cmp);
  if(y < (LD)1) reverse(all(vy));
	
  vector<pair<LD,int>> vz={mp(log(x)+log(y),11) , mp(x*log(y),10) , mp(y*log(x),9)};
  sort(all(vz),cmp);
  if(z < (LD)1) reverse(all(vz));

	vector<pair<LD,int>> sup_1 , inf_1 , one;
	if(x > (LD)1) sup_1.push_back(vx.back()) , sup_1.back().F += log(log(x));
	if(x < (LD)1) inf_1.push_back(vx.back()) , inf_1.back().F = (inf_1.back().F)/log((LD)0.5) + nlog(nlog(x));
	if(x == (LD)1) one.push_back(vx.back()) , one.back().F = 1;

	if(y > (LD)1) sup_1.push_back(vy.back()) , sup_1.back().F += log(log(y));
	if(y < (LD)1) inf_1.push_back(vy.back()) , inf_1.back().F = (inf_1.back().F)/log((LD)0.5) + nlog(nlog(y));
	if(y == (LD)1) one.push_back(vy.back()) , one.back().F = 1;

	if(z > (LD)1) sup_1.push_back(vz.back()) , sup_1.back().F += log(log(z));
	if(z < (LD)1) inf_1.push_back(vz.back()) , inf_1.back().F = (inf_1.back().F)/log((LD)0.5) + nlog(nlog(z));
	if(z == (LD)1) one.push_back(vz.back()) , one.back().F = 1;

	sort(all(sup_1),cmp);
	sort(all(inf_1),cmp);
	sort(all(one),cmp);

	if(!sup_1.empty()) cout << ans[sup_1.back().S] << '\n';
	else if(!one.empty()) cout << ans[one.back().S] << '\n';
	else cout << ans[inf_1.back().S] << '\n';

  return 0;
}
