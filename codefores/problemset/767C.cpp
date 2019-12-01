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

const int maxn=1e6+10;

int n;
vector<int> e[maxn];
int w[maxn]; 
int rt;
int sum; 
int res[maxn];
vector<int> ans;

void dfs(int u,int f){
	int v;
	res[u]=w[u];
	for(int i=0;i<(int)e[u].size();i++){
		v=e[u][i];
		if(v==f)
			continue;
		dfs(v,u);
		res[u]+=res[v];
	}
	if(res[u]==sum/3){
		ans.push_back(u);
		res[u]=0;
	}
}

int main(void){
	int u,x;
	scanf("%d",&n);
	sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d %d",&u,&x);
		if(u==0){
			rt=i;
		}
		else{
			e[u].push_back(i);
		}
		w[i]=x;
		sum+=x;
	}
	if(sum%3!=0){
		puts("-1");
		return 0;
	}
	dfs(rt,0);
	if(ans.size()>=3){
		printf("%d %d\n",ans[0],ans[1]);
	}
	else{
		puts("-1");
	}
	return 0;
}
