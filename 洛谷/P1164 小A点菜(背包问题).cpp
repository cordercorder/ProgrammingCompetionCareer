# include<iostream>
# include<algorithm>
# include<cstring>

using namespace std;

const int maxsize2=10005;
const int maxsize1=105;

int dp[maxsize1][maxsize2];
int n,m;
int val[maxsize1];


void solve(){
	int i,j;
	memset(dp,0,sizeof(int)*maxsize1*maxsize2);
	for(i=0;i<=n;i++)
		dp[i][0]=1;
	for(i=1;i<=n;i++){//dp[i,j]表示前i件物品，恰好花完j元的方案数
		for(j=1;j<=m;j++){
			if(j>=val[i])
				dp[i][j]=dp[i-1][j-val[i]]+dp[i-1][j];
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	printf("%d\n",dp[n][m]);
}

int main(void){
	int i;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&val[i]);
	}
	solve();
	return 0;
}
