# include<iostream>
# include<algorithm>
# include<cstring>
# include<string>
# include<cmath>
# include<queue>
# include<stack>
# include<set>
# include<vector>
# include<cstdio>
# include<cstdlib>
# include<map>
# include<deque>
# include<limits.h>
# include<ctime>

# define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e5+10;
const int mod=1e9+7;

ll a[maxn];
ll pos[maxn],dp[maxn];
ll n;

int main(void){
	while(scanf("%lld",&n)!=EOF){
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(ll i=1;i<=n;i++){
			if(pos[a[i]]==0){
				dp[i]=(dp[i-1]*2)%mod;
			}
			else{
				dp[i]=(dp[i-1]*2-dp[pos[a[i]]-1]+mod)%mod;
			}
			pos[a[i]]=i;
		}
		printf("%lld\n",(dp[n]-1+mod)%mod);
	}
	return 0;
}
