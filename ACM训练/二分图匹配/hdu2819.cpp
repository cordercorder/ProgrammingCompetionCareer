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

int a[maxn][maxn];
int n;
int linker[maxn];
bool isv[maxn]; 

struct node{
	int a;
	int b;
};

node res[maxn*maxn];
int tot;


bool dfs(int u){
	for(int i=1;i<=n;i++){
		if(a[u][i]&&!isv[i]){
			isv[i]=1;
			if(linker[i]==-1||dfs(linker[i])){
				linker[i]=u;
				return 1;
			}
		}
	}
	return 0;
}

int match(){
	int ans=0;
	memset(linker,-1,sizeof(linker));
	for(int i=1;i<=n;i++){
		memset(isv,0,sizeof(isv));
		if(dfs(i)){
			ans++;
		}
	}
	return ans;
}

void solve(){
	int cnt=match();
	if(cnt<n){
		puts("-1");
		return ;
	}
	//for(int i=1;i<=n;i++){
	//	printf("%d ",linker[i]);
	//}
	//puts("");
	int Min;
	tot=0;
	for(int i=1;i<=n;i++){
		Min=i;
		for(int j=i+1;j<=n;j++){
			if(linker[Min]>linker[j]){
				Min=j;
			}
		}
		if(Min!=i){
			swap(linker[Min],linker[i]);
			res[++tot].a=i;
			res[tot].b=Min;
		}
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++){
		printf("C %d %d\n",res[i].a,res[i].b);
	}
}

int main(void){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&a[i][j]);
			}
		}
		solve();
	}
	return 0;
}
