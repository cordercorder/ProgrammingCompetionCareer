#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<deque>
#include<limits.h>
#include<bitset>
#include<ctime>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

const long double PI=acos(-1.0); 
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e2+10;

vector<int> e[maxn];

int b[maxn],num[maxn];
int n,m;
bool isv[maxn];
int dp[maxn][maxn];

void dfs(int u){
	isv[u]=1;
	int v;
	for(int i=b[u];i<=m;i++){
		dp[u][i]=num[u];
	}
	for(int i=0;i<(int)e[u].size();i++){
		v=e[u][i];
		if(!isv[v]){
			dfs(v);
			for(int j=m;j>=b[u];j--){
				for(int k=1;k+b[u]<=j;k++){
					dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]);
				}
			}
		}
	}
}

int main(void){
	int u,v;
	while(scanf("%d %d",&n,&m)){
		if(n==-1&&m==-1)
			break;
		for(int i=1;i<=n;i++){
			scanf("%d %d",&b[i],&num[i]);
			b[i]=b[i]/20+(int)(!(b[i]%20==0));
		}
		for(int i=1;i<n;i++){
			scanf("%d %d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(m==0){
			puts("0");
			for(int i=1;i<=n;i++){
				e[i].clear();
			}
			continue;
		}
		memset(isv,0,sizeof(isv));
		memset(dp,0,sizeof(dp));
		dfs(1);
		printf("%d\n",dp[1][m]);
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
	}
	return 0;
}
