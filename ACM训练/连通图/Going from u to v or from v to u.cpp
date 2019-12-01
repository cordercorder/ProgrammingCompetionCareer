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

const int maxn=1e3+10;

vector<int> e[maxn],e2[maxn];
bool isv[maxn];
int dfn[maxn],low[maxn];
int sta[maxn],top;
int tot,cnt;
int t;
int n,m;
int belong[maxn];
int in[maxn];
int steps;

void tarjan(int u){
	dfn[u]=low[u]=++tot;
	isv[u]=1;
	sta[++top]=u;
	int v;
	for(int i=0;i<(int)e[u].size();i++){
		v=e[u][i];
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(isv[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		cnt++;
		int now;
		while(1){
			now=sta[top--];
			belong[now]=cnt;
			isv[now]=0;
			if(now==u)
				break;
		}
	}
}

void dfs(int u,int sum){
	steps=max(steps,sum);
	isv[u]=1;
	int v;
	for(int i=0;i<(int)e2[u].size();i++){
		v=e2[u][i];
		if(!isv[v]){
			dfs(v,sum+1);
		}
	}
}

void solve(){
	tot=cnt=0;
	top=-1;
	memset(isv,0,sizeof(isv));
	memset(dfn,0,sizeof(dfn));
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tarjan(i);
		}
	}
	if(cnt==1){
		puts("Yes");
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
		return ;
	}
	memset(in,0,sizeof(in));
	memset(isv,0,sizeof(isv));
	int v;
	for(int i=1;i<=n;i++){
		for(int j=0;j<(int)e[i].size();j++){
			v=e[i][j];
			if(belong[i]!=belong[v]){
				e2[belong[i]].push_back(belong[v]);
				in[belong[v]]++;
			}
		}
	}
	steps=0;
	for(int i=1;i<=cnt;i++){
		if(in[i]==0){
			//deb(i);
			dfs(i,1);
			break;
		}
	}
	//deb(steps);
	if(steps==cnt){
		puts("Yes");
	}
	else{
		puts("No");
	}
	for(int i=1;i<=n;i++){
		e[i].clear();
		if(i<=cnt){
			e2[i].clear();
		}
	}
}

int main(void){
	scanf("%d",&t);
	int u,v;
	while(t--){
		scanf("%d %d",&n,&m);
		for(int i=0;i<m;i++){
			scanf("%d %d",&u,&v);
			e[u].push_back(v);
		}
		solve(); 
	}
	return 0;
}
