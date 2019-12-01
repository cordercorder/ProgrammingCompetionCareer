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

const int maxn=40+10;

int t;
int h,w;
char s[maxn][maxn];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int res[maxn*maxn],cnt;
vector<int> e[maxn*maxn];
bool isv[maxn*maxn];
int linker[maxn*maxn];
int num;


void pre_handle(){
	cnt=0;
	num=0;
	int u,v;
	int x,y;
	bool f;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			f=0;
			u=(i-1)*w+j;
			if(s[i][j]=='*'){
				++num;
				for(int k=0;k<4;k++){
					x=dx[k]+i;
					y=dy[k]+j;
					if(x>=1&&x<=h&&y>=1&&y<=w&&s[x][y]=='*'){
						if(!f){
							res[++cnt]=u;
							f=1;
						}
						v=(x-1)*w+y;
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
	int ans=match();
	//deb(ans);
	//deb(num);
	printf("%d\n",num-ans/2);
	for(int i=1;i<=cnt;i++){
		e[res[i]].clear();
	}
}

int main(void){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&h,&w);
		for(int i=1;i<=h;i++){
			scanf("%s",s[i]+1);
		}
		solve();
	}
	return 0;
}
