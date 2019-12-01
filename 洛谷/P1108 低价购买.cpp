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

const int maxsize=5e3+5;

int n,dp[maxsize];
int num[maxsize];

int a[maxsize];

void solve(){
	int i,j;
	int ans=0,sum=0;
	for(i=0;i<n;i++){//最长下降子序列 
		dp[i]=1;
		for(j=0;j<i;j++){
			if(a[i]<a[j]&&dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
			}
		}
		ans=max(ans,dp[i]);
	}
	for(i=0;i<n;i++){
		if(dp[i]==1){
			num[i]=1;
		}
		for(j=0;j<i;j++){
			if(dp[i]==dp[j]+1&&a[i]<a[j]){
				num[i]=num[i]+num[j];
			}
			if(dp[i]==dp[j]&&a[i]==a[j]){
				num[j]=0;
			}
		}
	}
	for(i=0;i<n;i++){
		if(dp[i]==ans){
			sum=sum+num[i];
		}
	}
	printf("%d %d\n",ans,sum);
}

int main(void){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	solve();
	return 0;
}
