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

typedef long long ll;

using namespace std;

const int maxn=1e3+10;
const ll maxw=-1e12;

ll a[maxn];
ll n;
ll dp[maxn][maxn+10];

ll solve(ll x,ll pre){
	if(x>=n)
		return 0;
	if(dp[x][pre+1]>maxw)
		return dp[x][pre+1];
	ll res;
	if(pre==-1){
		res=solve(x+1,x)+a[x];
		res=max(res,solve(x+1,pre));
		return dp[x][pre+1]=res;
	}
	if(a[x]>a[pre]){
		res=solve(x+1,x)+a[x];
		res=max(res,solve(x+1,pre));
	}
	else{
		res=solve(x+1,pre);
	}
	return dp[x][pre+1]=res;
}

int main(void){
	while(scanf("%lld",&n)!=EOF){
		if(n==0)
			break;
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		for(ll i=0;i<=n;i++){
			for(ll j=0;j<=n+2;j++){
				dp[i][j]=maxw;
			}
		}
		printf("%lld\n",solve(0,-1));
	}
	return 0;
}
