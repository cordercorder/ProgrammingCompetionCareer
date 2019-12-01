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

vector<int> e[maxn];
int n;
bool isv[maxn];
int res[maxn];

void dfs(int u){
	isv[u]=1;
	res[u]=1;
	vector<int> num;
	int v;
	int Max=1,sum=0;
	for(int i=0;i<(int)e[u].size();i++){
		v=e[u][i];
		if(!isv[v]){
			dfs(v);
			num.push_back(res[v]);
			Max=max(Max,res[v]);
		}
	}
	for(int i=0;i<(int)num.size();i++){
		if(num[i]==Max){
			sum++;
		}
	}
	if(sum>1){
		res[u]=Max+1;
	}
	else{
		res[u]=Max;
	}
}

int main(void){
	int u,v;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<n;i++){
			scanf("%d %d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		memset(isv,0,sizeof(isv));
		dfs(1);
		printf("%d\n",res[1]); 
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
	}
	return 0;
}
