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

int n,m,k;
int w[maxn],v[maxn];
int belong[maxn];
int dp[15][maxn*100];

void solve(){
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=k;i++){
		for(int u=0;u<=m;u++){
			dp[i][u]=-maxw;
		}
		for(int j=1;j<=n;j++){
			if(belong[j]==i){
				for(int u=m;u>=w[j];u--){
					dp[i][u]=max(dp[i][u],dp[i][u-w[j]]+v[j]);
					dp[i][u]=max(dp[i][u],dp[i-1][u-w[j]]+v[j]);
				}
			}
		}
	}
	if(dp[k][m]<0){
		puts("Impossible");
	}
	else{
		printf("%d\n",dp[k][m]);
	}
}

int main(void){
	while(scanf("%d %d %d",&n,&m,&k)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&belong[i],&w[i],&v[i]);
		}
		solve();
	}
	return 0;
}
