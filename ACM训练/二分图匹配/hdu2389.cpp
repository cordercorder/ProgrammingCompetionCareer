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
bool isv[maxn];
int linker[maxn];

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

int match(){
	int ans=0;
	memset(linker,-1,sizeof(linker));
	for(int i=1;i<=m;i++){
		memset(isv,0,sizeof(isv));
		if(dfs(i)){
			ans++;
		}
	}
	return ans;
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
