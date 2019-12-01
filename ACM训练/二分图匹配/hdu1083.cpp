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

const int maxn=3e2+10;

vector<int> e[maxn];
int p,n;
int t;
bool isv[maxn];
int linker[maxn];

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

void solve(){
	memset(linker,-1,sizeof(linker));
	int cnt=0;
	for(int i=1;i<=p;i++){
		memset(isv,0,sizeof(isv));
		if(dfs(i)){
			cnt++;
		}
	}
	if(cnt==p){
		puts("YES");
	}
	else{
		puts("NO");
	}
	for(int i=1;i<=p;i++){
		e[i].clear();
	}
}

int main(void){
	int u,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&p,&n);
		for(int i=1;i<=p;i++){
			scanf("%d",&k);
			for(int j=0;j<k;j++){
				scanf("%d",&u);
				e[i].push_back(u);
			}
		}
		solve();
	}
	return 0;
}
