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

const int maxn=2e2+10;

int n,m;
vector<int> e[maxn];
int v[maxn];
bool isv[maxn];
int dp[maxn][maxn];

void dfs(int u){
	isv[u]=true;
	dp[u][1]=v[u];
	int v;
	for(int i=0;i<(int)e[u].size();i++){
		v=e[u][i];
		if(isv[v]){
			continue;
		}
		dfs(v);
		for(int j=m;j>1;j--){
			for(int k=1;k<j;k++){
				dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]);
			}
		}
	}
}

int main(void){
	int u;
	while(scanf("%d %d",&n,&m)!=EOF){
		if(n==0&&m==0)
			break;
		for(int i=1;i<=n;i++){
			scanf("%d %d",&u,&v[i]);
			e[u].push_back(i);
		}
		m++;
		dfs(0);
		printf("%d\n",dp[0][m]);
		for(int i=0;i<=n;i++){
			e[i].clear();
		}
		memset(isv,false,sizeof(isv));
		memset(dp,0,sizeof(dp));
	}
	return 0;
}
