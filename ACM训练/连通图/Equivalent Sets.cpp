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

const int maxn=2e4+10;

int n,m;
vector<int> e[maxn];
int low[maxn],dfn[maxn];
bool isv[maxn];
int tot,cnt;
stack<int> sta;
int belong[maxn];
int in[maxn],out[maxn];

void tarjan(int u){
	int v;
	low[u]=dfn[u]=++tot;
	sta.push(u);
	isv[u]=1;
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
			now=sta.top();
			sta.pop();
			isv[now]=0;
			belong[now]=cnt;
			if(now==u)
				break;
		}
	}
}

void solve(){
	memset(dfn,0,sizeof(dfn));
	memset(isv,0,sizeof(isv));
	tot=0;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tarjan(i);
		}
	}
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	int u;
	for(int i=1;i<=n;i++){
		for(int j=0;j<(int)e[i].size();j++){
			u=e[i][j];
			if(belong[u]!=belong[i]){
				out[belong[i]]++;
				in[belong[u]]++;
			}
		}
	}
	//deb(cnt);
	if(cnt==1){
		puts("0");
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
		while(!sta.empty()){
			sta.pop();
		}
		return ;
	}
	int res1=0,res2=0;
	for(int i=1;i<=cnt;i++){
		if(in[i]==0){
			res1++;
		}
		if(out[i]==0){
			res2++;
		}
	}
	printf("%d\n",max(res1,res2));
	for(int i=1;i<=n;i++){
		e[i].clear();
	}
	while(!sta.empty()){
		sta.pop();
	}
}

int main(void){
	int x,y;
	while(scanf("%d %d",&n,&m)!=EOF){
		for(int i=0;i<m;i++){
			scanf("%d %d",&x,&y);
			e[x].push_back(y);
		}
		solve();
	}
	return 0;
}
