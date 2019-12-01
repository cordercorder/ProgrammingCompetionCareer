# include<iostream>
# include<algorithm>
# include<cstring>

using namespace std;

const int maxsize=100005;

int dp[maxsize];

int t,m;
int ti[maxsize],val[maxsize];

void solve(){
	int i,j;
	memset(dp,0,sizeof(dp));
	for(i=1;i<=m;i++){
		for(j=ti[i];j<=t;j++){
			dp[j]=max(dp[j],dp[j-ti[i]]+val[i]);//如果是01背包问题，则循环为从t到ti[i] 
		}
	}
	printf("%d\n",dp[t]);
}

int main(void){
	int i;
	scanf("%d %d",&t,&m);
	for(i=1;i<=m;i++)
		scanf("%d %d",&ti[i],&val[i]);
	solve();
	return 0;
}
