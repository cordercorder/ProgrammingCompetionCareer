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

const int mod=1e9+7;
const int maxn=1e5+10;

ll w[15]={0,1,2,5,10,20,50,100,200,500,1000,2000,5000,10000};
ll n;
ll dp[maxn];

void solve(){
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(ll i=1;i<=13;i++){
		for(ll j=w[i];j<=n;j++){
			dp[j]=(dp[j-w[i]]+dp[j])%mod;
		}
	}
	printf("%lld\n",dp[n]);
}

int main(void){
	while(scanf("%lld",&n)!=EOF){
		solve();
	}
	return 0;
}
