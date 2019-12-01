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

const int maxn=2e2+10;

int n,m;
vector<int> e[maxn];
int linker[maxn];
bool isv[maxn];

bool bfs(int st){//È¾É«ÅÐ¶Ï¶þ·ÖÍ¼ 
	int q[maxn];
	int color[maxn];
	int front=0,back=0;
	memset(color,-1,sizeof(color));
	color[st]=1;
	q[++back]=st;
	int now,v;
	while(front<back){
		now=q[++front];
		for(int i=0;i<(int)e[now].size();i++){
			v=e[now][i];
			if(color[v]==-1){
				color[v]=!color[now];
				q[++back]=v;
			}
			else if(color[v]==color[now]){
				return 0;
			}
		}
	}
	return 1;
}

bool dfs(int u){
	int v;
	for(int i=0;i<(int)e[u].size();i++){
		v=e[u][i];
		if(!isv[v]){
			isv[v]=1;
			if(linker[v]==-1||dfs(linker[v])){
				linker[v]=u;
				return 1;
			}
		}
	}
	return 0;
}

void solve(){
	if(!bfs(1)){
		puts("No");
		return ;
	}
	int ans=0;
	memset(linker,-1,sizeof(linker));
	for(int i=1;i<=n;i++){
		memset(isv,0,sizeof(isv));
		if(dfs(i)){
			ans++;
		}
	}
	ans>>=1;
	printf("%d\n",ans);
}

int main(void){
	int u,v;
	while(scanf("%d %d",&n,&m)!=EOF){
		for(int i=0;i<m;i++){
			scanf("%d %d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		solve();
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
	}
	return 0;
}
