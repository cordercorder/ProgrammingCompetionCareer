#include<algorithm>
#include<iostream>
#include<limits.h>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<string>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<ctime>
#include<set>
#include<map>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("data.txt","r",stdin)
#define FOUT freopen("data.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const int maxw=1e7+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e2+10;

int n,T;
int dp[maxn][maxn];
int c[maxn][maxn],g[maxn][maxn];
int s[maxn],m[maxn];

void solve(){
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		if(s[i]==0){//每组至少取一个 dp[i][k]=max(dp[i][k],dp[i-1][k-c[i][j]]+g[i][j],dp[i][k-c[i][j]]+g[i][j])
			for(int j=0;j<=T;j++){
				dp[i][j]=-maxw;
			}
			for(int j=1;j<=m[i];j++){
				for(int k=T;k>=c[i][j];k--){
					dp[i][k]=max(dp[i][k],dp[i][k-c[i][j]]+g[i][j]);//顺序不能调换	 
					dp[i][k]=max(dp[i][k],dp[i-1][k-c[i][j]]+g[i][j]);
				}
			}
		}
		else if(s[i]==1){//最多选一个 dp[i][k]=max(dp[i][k],dp[i-1][k-c[i][j]]+g[i][j])
			for(int j=0;j<=T;j++){
				dp[i][j]=dp[i-1][j]; 
			}
			for(int j=1;j<=m[i];j++){
				for(int k=T;k>=c[i][j];k--){
					dp[i][k]=max(dp[i][k],dp[i-1][k-c[i][j]]+g[i][j]);
				}
			}
		}
		else{//任意选 
			for(int j=0;j<=T;j++){
				dp[i][j]=dp[i-1][j];
			}
			for(int j=1;j<=m[i];j++){
				for(int k=T;k>=c[i][j];k--){
					dp[i][k]=max(dp[i][k],dp[i][k-c[i][j]]+g[i][j]);//顺序不能调换 
					dp[i][k]=max(dp[i][k],dp[i-1][k-c[i][j]]+g[i][j]);
				}
			}
		}
	}
	if(dp[n][T]<0){
		dp[n][T]=-1;
	}
	printf("%d\n",dp[n][T]);
}

int main(void){
	while(scanf("%d %d",&n,&T)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d %d",&m[i],&s[i]);
			for(int j=1;j<=m[i];j++){
				scanf("%d %d",&c[i][j],&g[i][j]);
			}
		}
		solve();
	}
	return 0;
}
