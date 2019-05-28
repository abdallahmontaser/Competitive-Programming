/**
 * Think of DP. The regular dp[cur_pos][mask_so_far], where you loop over the possible masks
 * and choose whether to take the current mask or not, and move to the next position.
 * That would take O(m*2^n) time and memory.
 * What if you used the memory reduction technique? And looped over masks while updating just
 * dp[masks] ?
 * That would make it O(2^n) memory. And the time will depend on what you're looping on each 
 * time you process a possible mask for a sauce.
 * You will only need to update the sup_masks of any current mask(like below).
 * Looping over sup_mask/sub_masks of every mask from 0 to 2^n-1 will take O(3^n) which is sufficient.
 *
 * Alternative but similar approach: https://github.com/magdy-hasan/competitive-programming/blob/master/Other/ZOJ%20Get%20Sauce.cpp
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
using namespace std; const int N=16;
int dp[1<<N];

signed main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m;
	while(cin>>n>>m){
		memset(dp,0,sizeof(dp));
		int ans=0;
		while(m--){
			int msk=0;
			int nb; cin>>nb; while(nb--){ int x; cin>>x; msk+=1<<(x-1); }
			for(int sup=msk; sup<=(1<<n)-1; sup=(sup+1)|msk)
				dp[sup]=max(dp[sup],1+dp[sup-msk]), ans=max(ans,dp[sup]);
		}
		cout<<ans<<'\n';
	}
}
