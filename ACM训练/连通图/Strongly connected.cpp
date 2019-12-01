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

const int maxn=1e5+10;

int t;
int n,m;
vector<int> e[maxn]; 
int low[maxn],dfn[maxn];
bool isv[maxn];
int tot,cnt;
stack<int> sta;
int belong[maxn],in[maxn],out[maxn];
int res[maxn];

void tarjan(int u){
	low[u]=dfn[u]=++tot;
	sta.push(u);
	isv[u]=1;
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
	if(low[u]==dfn[u]){
		cnt++;
		int now;
		while(1){
			now=sta.top();
			sta.pop();
			isv[now]=0;
			belong[now]=cnt;
			res[cnt]++;
			if(now==u){
				break;
			}
		}
	}
}

void solve(){
	memset(dfn,0,sizeof(dfn));
	memset(isv,0,sizeof(isv));
	memset(res,0,sizeof(res));
	cnt=0;
	tot=0;
	for(int i=1;i<=n;i++){
		in[i]=0;
		out[i]=0;
		if(!dfn[i]){
			tarjan(i);
		}
	}
	int u;
	if(cnt==1){
		puts("-1");
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
		while(!sta.empty()){
			sta.pop();
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<(int)e[i].size();j++){
			u=e[i][j];
			if(belong[i]!=belong[u]){
				in[belong[u]]++;
				out[belong[i]]++;
			}
		}
	}
	ll ans=n*(n-1);
	ll Min=maxw;
	for(int i=1;i<=cnt;i++){
		if(in[i]==0||out[i]==0){
			Min=min(Min,(ll)res[i]);
		}
	}
	ans=ans-(Min*(n-Min))-(ll)m;
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++){
		e[i].clear();
	}
	while(!sta.empty()){
		sta.pop();
	}
}

int main(void){
	int x,y;
	scanf("%d",&t);
	for(int ca=1;ca<=t;ca++){
		scanf("%d %d",&n,&m);
		for(int i=0;i<m;i++){
			scanf("%d %d",&x,&y);
			e[x].push_back(y);
		}
		printf("Case %d: ",ca);
		solve();
	}
	return 0;
}
