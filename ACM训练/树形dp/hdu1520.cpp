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

const int maxn=6e3+10;

vector<int> e[maxn];
int n;
int r[maxn];
int in[maxn];
bool isv[maxn];
int dp[maxn][2];

void dfs(int u){
	isv[u]=1;
	int v;
	dp[u][1]=r[u]; 
	for(int i=0;i<(int)e[u].size();i++){
		v=e[u][i];
		if(!isv[v]){
			dfs(v);
			dp[u][0]+=max(dp[v][0],dp[v][1]);
			dp[u][1]+=dp[v][0];
		}
	}
}

void solve(){
	memset(isv,0,sizeof(isv));
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		if(in[i]==0){
			dfs(i);
			/*puts("");
			for(int i=1;i<=n;i++){
				printf("%d %d\n",dp[i][0],dp[i][1]);
			}*/
			printf("%d\n",max(dp[i][1],dp[i][0]));
			return ;
		}
	}
}

int main(void){
	int u,v;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&r[i]);
		}
		memset(in,0,sizeof(in));
		while(scanf("%d %d",&u,&v)){
			if(u==0&&v==0)
				break;
			e[v].push_back(u);
			in[u]++;
		}
		solve();
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
	}
	return 0;
}
