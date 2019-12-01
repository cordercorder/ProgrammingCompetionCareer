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
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e2+10;

int n,m,K;
int w[maxn][maxn];
int dp[maxn][maxn][maxn];

void solve(){
	int res,res2;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=K;k>=w[i][j];k--){
				res=max(dp[i-1][j][k-w[i][j]],dp[i][j-1][k-w[i][j]])+w[i][j];
				res2=max(dp[i-1][j][k],dp[i][j-1][k]);
				dp[i][j][k]=max(res2,res);
			}
		}
	}
	printf("%d\n",dp[n][m][K]);
}

int main(void){
	while(scanf("%d %d %d",&n,&m,&K)!=EOF){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&w[i][j]);
			}
		}
		solve();
	}
	return 0;
}
