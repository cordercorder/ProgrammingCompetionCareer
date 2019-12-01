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

const int maxn=1e2+10;
const int maxw=1e7+10;

int n;
int a[maxn];
int dp[maxn][maxn];
int sum[maxn];

void solve(){
	int Min;
	for(int len=1;len<n;len++){
		for(int i=1;(i+len)<=n;i++){
			Min=maxw;
			for(int k=i;k<i+len;k++){
				Min=min(Min,dp[i][k]+dp[k+1][i+len]);
			}
			//deb(i);
			//deb(i+len);
			dp[i][i+len]=Min+sum[i+len]-sum[i-1];
			//deb(Min);
			//deb(dp[i][i+len]);
		}
	}
	printf("%d\n",dp[1][n]);
}

int main(void){
	while(scanf("%d",&n)!=EOF){
		sum[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}
		solve();
	}
	return 0;
}
