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

const int maxn=5e2+10;

int a[maxn][maxn];
int n;
int dp[maxn][maxn];

void solve(){
	memset(dp,0,sizeof(dp));
	dp[1][1]=a[1][1];
	int ans=0;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+a[i][j];
			ans=max(ans,dp[i][j]);
		}
	}
	printf("%d\n",ans);
}

int main(void){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				scanf("%d",&a[i][j]);
			}
		}
		solve();
	}	
	return 0;
}
