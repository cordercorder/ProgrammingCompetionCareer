#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<deque>
#include<limits.h>
#include<bitset>
#include<ctime>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

const long double PI=acos(-1.0); 
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e3+10;

ll a[maxn],dp[maxn];
ll n;

void solve(){
	ll ans=INT_MIN;
	for(ll i=1;i<=n;i++){
		dp[i]=a[i];
		for(ll j=1;j<i;j++){
			if(a[i]>a[j]){
				dp[i]=max(dp[i],dp[j]+a[i]);
			}
		}
		ans=max(ans,dp[i]);
	}
	//deb(ans);
	printf("%lld\n",ans<0?(ll)0:ans);
}

int main(void){
	while(scanf("%lld",&n)!=EOF){
		if(n==0)
			break;
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		solve();
	}
	return 0;
}
