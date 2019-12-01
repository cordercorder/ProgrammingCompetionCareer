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

const int maxn=1e4+10;

vector<int> e[maxn];
int n,m;
int low[maxn],dfn[maxn];
stack<int> sta;
int tot;
bool isv[maxn];
int cnt;

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
	if(low[u]==dfn[u]){
		cnt++;
		int now;
		while(1){
			now=sta.top();
			isv[now]=0;
			sta.pop();
			if(now==u)
				break;
		}
	}
}

void solve(){
	cnt=0;
	tot=0;
	memset(isv,0,sizeof(isv));
	memset(dfn,0,sizeof(dfn));
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tarjan(i);
		}
	}
	if(cnt==1){
		puts("Yes");
	}
	else{
		puts("No");
	}
	for(int i=1;i<=n;i++){
		e[i].clear();
	}
	while(!sta.empty()){
		sta.pop();
	}
}

int main(void){
	int u,v;
	while(scanf("%d %d",&n,&m)){
		if(n==0&&m==0)
			break;
		for(int i=0;i<m;i++){
			scanf("%d %d",&u,&v);
			e[u].push_back(v);
		}
		solve();
	}
	return 0;
}
