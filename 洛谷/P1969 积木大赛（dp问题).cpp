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

using namespace std;

const int maxsize=1e5+10;

int dp[maxsize];
int a[maxsize];
int n;

void solve(){
	int i;
	dp[1]=a[1];
	for(i=2;i<=n;i++){
		if(a[i]>a[i-1]){
			dp[i]=dp[i-1]+a[i]-a[i-1];
		}
		else{
			dp[i]=dp[i-1];
		}
		//printf("dp[%d]=%d\n",i,dp[i]);
	}
	printf("%d\n",dp[n]);
}

int main(void){
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	solve();
	return 0;
}
