# include<iostream>
# include<algorithm>
# include<cstring>
# include<cstdlib>
# include<string>
# include<cmath>
# include<queue>
# include<stack>
# include<set>
# include<vector>
# include<cstdio>

using namespace std;

const int maxsize=25;

int a[maxsize][maxsize];
int dp[maxsize][maxsize];
int n;

void solve(){
	int i,j,ans=0;
	memset(dp,0,sizeof(dp));
	for(i=0;i<n;i++)
		dp[0][i]=a[0][i];//dp数组的初始化 
	for(i=1;i<n;i++){
		for(j=0;j<n;j++){
			if(j>0&&j<n-1){
				dp[i][j]=max(dp[i-1][j-1],dp[i-1][j+1])+a[i][j];
			}
			else if(j==0){
				dp[i][j]=dp[i-1][j+1]+a[i][j];
			}
			else if(j==n-1){
				dp[i][j]=dp[i-1][j-1]+a[i][j];
			}
			ans=max(dp[i][j],ans);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
	printf("%d\n",ans);
}

int main(void){
	int i,j;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&a[i][j]);
			}
		}
		solve();
	}
	return 0;
}
