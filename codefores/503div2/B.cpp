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

const int maxn=1e3+10;

int n;
int p[maxn];
vector<int> e[maxn];
bool isv[maxn];

void dfs(int x){
	isv[x]=1;
	int u;
	for(int i=0;i<(int)e[x].size();i++){
		u=e[x][i];
		if(!isv[u]){
			dfs(u);
		}
		else{
			printf("%d ",u);
			return ;
		}
	}
}

void solve(){
	for(int i=1;i<=n;i++){
		memset(isv,0,sizeof(isv));
		dfs(i);
	}
}

int main(void){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		e[i].push_back(p[i]);
	}
	solve();
	return 0;
}
