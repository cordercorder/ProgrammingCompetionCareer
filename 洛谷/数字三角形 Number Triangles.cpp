# include<iostream>
# include<cstdio>
# include<cstring>
# include<algorithm>

using namespace std;

const int maxsize=1005;

int dp[maxsize][maxsize];
int m;

void solve(){
	int i,j,ans=0;
	for(i=1;i<=m;i++){
		for(j=1;j<=i;j++){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+dp[i][j];
			ans=max(ans,dp[i][j]);
		}
	}
	printf("%d\n",ans);
}

int main(void){
	int i,j;
	scanf("%d",&m);
	memset(dp,0,sizeof(int)*maxsize);
	for(i=1;i<=m;i++){
		for(j=1;j<=i;j++){
			scanf("%d",&dp[i][j]);
		}
	}
	solve();
	return 0;
}
