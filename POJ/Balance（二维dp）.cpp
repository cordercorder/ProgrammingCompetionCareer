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
# include<map>
# include<deque>

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

const int maxsize=15000+10;

int c,g;
int pos[25],w[25];
int dp[25][maxsize];

void solve(){
	memset(dp,0,sizeof(dp));
	dp[0][7500]=1;
	for(int i=1;i<=g;i++){
		for(int j=0;j<=15000;j++){
			if(dp[i-1][j]){
				for(int k=1;k<=c;k++){
					dp[i][j+w[i]*pos[k]]+=dp[i-1][j];
				}
			}
		}
	}
	printf("%d\n",dp[g][7500]);
}

int main(void){
	while(scanf("%d %d",&c,&g)!=EOF){
		for(int i=1;i<=c;i++){
			scanf("%d",&pos[i]);
		}
		for(int i=1;i<=g;i++){
			scanf("%d",&w[i]);
		}
		solve();
	}
	return 0;
}
