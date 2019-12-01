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
# include<limits.h>
# include<ctime>

# define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

typedef long long ll;

using namespace std;

const int maxn=1e5+10;

int dp[maxn][20];
int n;

int main(void){
	int a,b;
	int Max;
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		Max=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			scanf("%d %d",&a,&b);//xºÍt 
			dp[b][a+1]++;
			Max=max(Max,b);
		}
		for(int i=Max;i>=0;i--){
			for(int j=1;j<=11;j++){
				dp[i][j]+=max(max(dp[i+1][j],dp[i+1][j-1]),dp[i+1][j+1]); 
			}
		}
		printf("%d\n",dp[0][6]);
	}
	return 0;
}
