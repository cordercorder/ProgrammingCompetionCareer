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

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;


const int maxn=1e6+10;

int n,m;
int a[maxn],dp[2][maxn];


void solve(){
	int Max;
	for(int i=1;i<=m;i++){
		Max=INT_MIN;
		for(int j=i;j<=n;j++){
			Max=max(dp[(i-1)%2][j-1],Max);
			if(i==j){
				dp[i%2][j]=dp[(i-1)%2][j-1]+a[j];
			}
			else{
				dp[i%2][j]=max(dp[i%2][j-1],Max)+a[j];
			}
			
		}
	}
	int ans=INT_MIN;
	for(int i=m;i<=n;i++){
		ans=max(ans,dp[m%2][i]);
	}
	printf("%d\n",ans);
}

int main(void){	
	while(scanf("%d %d",&m,&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		memset(dp,0,sizeof(dp));
		solve();
	}
	return 0;
}
