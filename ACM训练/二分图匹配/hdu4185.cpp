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

const int maxn=6e2+10; 

int t;
int n;
char s[maxn][maxn];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
vector<int> e[maxn*maxn]; 
int linker[maxn];
bool isv[maxn];
int res[maxn*maxn],cnt;

void pre_handle(){
	int x,y;
	int u,v;
	cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			u=(i-1)*n+j;
			if(s[i][j]=='#'){
				res[++cnt]=u;
				for(int k=0;k<4;k++){
					x=i+dx[k];
					y=j+dy[k];
					if(x>=1&&x<=n&&y>=1&&y<=n&&s[x][y]=='#'){
						v=(x-1)*n+y;
						e[u].push_back(v);
					}
				}
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
	for(int i=1;i<=cnt;i++){
		memset(isv,0,sizeof(isv));
		if(dfs(res[i])){
			ans++;
		}
	}
	return ans;
}

void solve(){
	pre_handle(); 
	printf("%d\n",match()/2);
	for(int i=1;i<=cnt;i++){
		e[res[i]].clear();
	}
}

int main(void){
	scanf("%d",&t);
	for(int ca=1;ca<=t;ca++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]+1);
		}
		printf("Case %d: ",ca);
		solve();
	}
	return 0;
}
