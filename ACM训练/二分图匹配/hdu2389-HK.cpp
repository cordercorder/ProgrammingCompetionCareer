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
const int maxw=1e8+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=3e3+10;

struct node{
	int x;
	int y;
	int sp;
};

int t;
int ti,n,m;
node a[maxn],b[maxn];
vector<int> e[maxn];
int mx[maxn],my[maxn];
int dx[maxn],dy[maxn];
int dis;
bool isv[maxn];

bool search_p(){
	queue<int> q;
	dis=maxw;
	memset(dx,-1,sizeof(dx));
	memset(dy,-1,sizeof(dy));
	for(int i=1;i<=m;i++){
		if(mx[i]==-1){
			q.push(i);
			dx[i]=0;
		}
	}
	int u,v;
	while(!q.empty()){
		u=q.front();
		q.pop();
		if(dx[u]>dis)
			break;
		for(int i=0;i<(int)e[u].size();i++){
			v=e[u][i];
			if(dy[v]==-1){
				dy[v]=dx[u]+1;
				if(my[v]==-1){
					dis=dy[v];
				}
				else{
					dx[my[v]]=dy[v]+1;
					q.push(my[v]);
				}
			}
		}
	}
	return dis!=maxw;
}

bool dfs(int u){
	int v;
	for(int i=0;i<(int)e[u].size();i++){
		v=e[u][i];
		if(!isv[v]&&dy[v]==dx[u]+1){
			isv[v]=1;
			if(my[v]!=-1&&dy[v]==dis)
				continue;
			if(my[v]==-1||dfs(my[v])){
				my[v]=u;
				mx[u]=v;
				return 1;
			}
		}
	}
	return 0;
}


int match(){
	int ans=0;
	memset(mx,-1,sizeof(mx));
	memset(my,-1,sizeof(my));
	while(search_p()){
		memset(isv,0,sizeof(isv));
		for(int i=1;i<=m;i++){
			if(mx[i]==-1&&dfs(i)){
				ans++;
			}
		}
	}
	return ans;
}

void pre_handle(){
	int tmp;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			tmp=a[i].sp*ti;
			tmp=tmp*tmp;
			if(tmp>=(a[i].x-b[j].x)*(a[i].x-b[j].x)+(a[i].y-b[j].y)*(a[i].y-b[j].y)){
				e[i].push_back(j);
			}
		}
	}
}

void solve(){
	pre_handle();
	printf("%d\n",match());
	puts("");
	for(int i=1;i<=m;i++){
		e[i].clear();
	}
}

int main(void){
	scanf("%d",&t);
	for(int ca=1;ca<=t;ca++){
		scanf("%d %d",&ti,&m);
		for(int i=1;i<=m;i++){
			scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].sp);
		}
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d",&b[i].x,&b[i].y);
		}
		printf("Scenario #%d:\n",ca);
		solve();
	}
	return 0;
}
