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

# define ll long long

using namespace std;

const int maxsize=5e2+10;

ll dp[maxsize][maxsize];

ll n; 

void solve(){
	int i,j;
	dp[0][0]=1;
	for(i=0;i<501;i++){
		for(j=1;j<=i;j++){
			dp[i][j]=dp[i-j][j-1]+dp[i][j-1];
		}
		for(j=i+1;j<501;j++){
			dp[i][j]=dp[i][i];
		}
	}
	printf("%lld\n",dp[n][n]-1);
}

int main(void){
	int i;
	while(scanf("%lld",&n)){
		if(n==0)
			break;
		solve();
	}
	return 0;
}
