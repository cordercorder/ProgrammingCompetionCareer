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


const int maxn=2e3+10;

int a[maxn];
int n;
int dp[maxn][maxn];

int main(void){
	int cnt;
	int ans;
	while(scanf("%d",&n)!=EOF){
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		memset(dp,0,sizeof(dp));
		cnt=1;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=n;j>=i-1;j--){
				dp[i][j]=max(dp[i-1][j]+a[i-1]*(n+i-j-1),dp[i][j+1]+a[j+1]*(n+i-j-1));
				ans=max(ans,dp[i][j]);
				cnt++;
			}
		}
		/*for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				printf("%d ",dp[i][j]);
			}
			printf("\n");
		}*/
		printf("%d\n",ans);
	}
	return 0;
}
