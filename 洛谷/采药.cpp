# include<iostream>
# include<algorithm>
# include<cstring>

using namespace std;

const int maxsize1=105;
const int maxsize2=1005;

int t,m;
int ti[maxsize1],val[maxsize1];
int dp[maxsize1][maxsize2];

void solve(){
	int i,j;
	memset(dp,0,sizeof(dp));
	for(i=1;i<=m;i++){
		for(j=1;j<=t;j++){
			if(j>=ti[i]){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-ti[i]]+val[i]);
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	printf("%d\n",dp[m][t]);
}

int main(void){
	int i;
	scanf("%d %d",&t,&m);
	for(i=1;i<=m;i++){
		scanf("%d %d",&ti[i],&val[i]);
	}
	solve();
	return 0;
}
