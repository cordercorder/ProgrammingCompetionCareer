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

int n,m,k;
int a[maxn][maxn];
bool isv[maxn];
int linker[maxn];
int x[maxn],y[maxn];

bool dfs(int u){
	for(int i=1;i<=m;i++){
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
	memset(linker,-1,sizeof(linker));
	int ans=0;
	for(int i=1;i<=n;i++){ 
		memset(isv,0,sizeof(isv));
		if(dfs(i)){
			ans++;
		}
	}
	return ans;
}

void solve(){
	int cnt=match(),sum=0;
	for(int i=1;i<=k;i++){
		a[x[i]][y[i]]=0;
		if(match()<cnt){
			sum++;
		}
		a[x[i]][y[i]]=1;
	}
	printf("%d important blanks for %d chessmen.\n",sum,cnt);
}

int main(void){
	int ca=0;
	while(scanf("%d %d %d",&n,&m,&k)!=EOF){
		memset(a,0,sizeof(a));
		for(int i=1;i<=k;i++){
			scanf("%d %d",&x[i],&y[i]);
			a[x[i]][y[i]]=1;
		}
		printf("Board %d have ",++ca);
		solve();
	}
	return 0;
}
