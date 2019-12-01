# include<iostream>
# include<algorithm>
# include<cstring>

using namespace std;

const int maxsize1=26;
const int maxsize2=30005;

int dp[maxsize1][maxsize2];

int val[maxsize1],im[maxsize1];

int n,m;

void solve(){
	int i,j;
	memset(dp,0,sizeof(int)*maxsize1*maxsize2);
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(j>=val[i]){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-val[i]]+val[i]*im[i]);
			}
			else{
				dp[i][j]=dp[i-1][j];
			}		
		}	
	}
	printf("%d\n",dp[m][n]);
}

int main(void){
	int i;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d %d",&val[i],&im[i]);
	}
	solve();
	return 0;
}
