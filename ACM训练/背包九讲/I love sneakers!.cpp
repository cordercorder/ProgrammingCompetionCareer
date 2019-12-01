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
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e2+10;

int n,m,k;
int f[maxn],w[maxn],v[maxn];
int dp[15][10010+100];

void solve(){
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<=m;i++){
		dp[0][i]=0;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(f[j]==i){
				for(int u=m;u>=w[j];u--){
					if(dp[i][u-w[j]]!=-1){
						dp[i][u]=max(dp[i][u],dp[i][u-w[j]]+v[j]);
					}
					if(dp[i-1][u-w[j]]!=-1){
						dp[i][u]=max(dp[i-1][u-w[j]]+v[j],dp[i][u]);
					}
				}
			}
		}
	}
	if(dp[k][m]==-1){
		puts("Impossible");
	}
	else{
		printf("%d\n",dp[k][m]);
	}
}

int main(void){
	while(scanf("%d %d %d",&n,&m,&k)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&f[i],&w[i],&v[i]);
		}
		solve();
	}
	return 0;
}
