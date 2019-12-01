# include<iostream>
# include<algorithm>
# include<cstring>

using namespace std;

const int maxsize1=35;
const int maxsize2=20005;

int dp[maxsize1][maxsize2];

int v[maxsize1];

int m,n;

void solve(){
	int i,j;
	memset(dp,0,sizeof(dp));
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(j>=v[i]){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+v[i]);
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	printf("%d\n",m-dp[n][m]); 
}

int main(void){
	int i;
	scanf("%d %d",&m,&n);
	for(i=1;i<=n;i++){
		scanf("%d",&v[i]);
	}
	solve();
	return 0;
}
