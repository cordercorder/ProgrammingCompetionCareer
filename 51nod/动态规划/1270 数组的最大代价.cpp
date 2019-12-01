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

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=5e4+10;

int b[maxn];
int n;
int dp[2][maxn];

int main(void){
	int ans; 
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&b[i]);
		}
		dp[0][1]=0;
		dp[1][1]=0;
		for(int i=2;i<=n;i++){
			dp[0][i]=max(dp[0][i-1],dp[1][i-1]+abs(1-b[i-1]));
			dp[1][i]=max(dp[0][i-1]+abs(b[i]-1),dp[1][i-1]+abs(b[i]-b[i-1]));
		}
		ans=max(dp[0][n],dp[1][n]);
		printf("%d\n",ans);
	}
	return 0;
}
