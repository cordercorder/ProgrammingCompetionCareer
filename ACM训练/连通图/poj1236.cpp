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
int n;
stack<int> sta;
bool isv[maxn];
int tot;
int low[maxn],dfn[maxn]; 
int cnt;
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
	if(low[u]==dfn[u]){
		cnt++;
		int now;
		while(1){
			now=sta.top();
			sta.pop();
			belong[now]=cnt;
			isv[now]=0;
			if(now==u)
				break;
		}
	}
}

void solve(){
	tot=0;
	cnt=0;
	memset(dfn,0,sizeof(dfn));
	memset(isv,0,sizeof(isv));
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tarjan(i);
		}
	}
	if(cnt==1){
		puts("1");
		puts("0");
		return ;
	}
	int u;
	for(int i=1;i<=n;i++){
		for(int j=0;j<(int)e[i].size();j++){
			u=e[i][j];
			if(belong[i]!=belong[u]){
				in[belong[u]]++;
				out[belong[i]]++;
			}
		}
	}
	int sum=0,ans=0,tmp1=0,tmp2=0;
	for(int i=1;i<=cnt;i++){
		if(in[i]==0){
			sum++;
		}
		if(in[i]==0){
			tmp1++;
		}
		if(out[i]==0){
			tmp2++;
		}
	}
	ans=max(tmp1,tmp2);
	printf("%d\n",sum);
	printf("%d\n",ans);
}

int main(void){
	scanf("%d",&n);
	int u;
	for(int i=1;i<=n;i++){
		while(scanf("%d",&u)){
			if(u==0)
				break;
			e[i].push_back(u);
		}
	}
	solve();
	return 0;
}
