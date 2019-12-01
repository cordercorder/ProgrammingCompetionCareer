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

const int maxn=1e6+10;

ll n,m;
ll a[maxn];
ll dp[2][maxn];

void solve(){
	ll Max;
	memset(dp,0,sizeof(dp));
	for(ll i=1;i<=m;i++){
		Max=-maxw;
		for(ll j=i;j<=n;j++){
			Max=max(Max,dp[(i-1)%2][j-1]);
			if(i==j){
				dp[i%2][j]=Max+a[j];
			}
			else{
				dp[i%2][j]=max(dp[i%2][j-1],Max)+a[j];
			}
		}
	}
	ll ans=-maxw;
	for(ll i=m;i<=n;i++){
		ans=max(ans,dp[m%2][i]);
	}
	printf("%lld\n",ans);
}

int main(void){
	while(scanf("%lld %lld",&m,&n)!=EOF){
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		solve();
	}
	return 0;
}
