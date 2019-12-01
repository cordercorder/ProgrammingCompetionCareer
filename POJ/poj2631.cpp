#include<algorithm>
#include<iostream>
#include<limits.h>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<string>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<ctime>
#include<set>
#include<map>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e4+10;

struct node{
	int to;
	int w;
	node(){}
	node(int a,int b):to(a),w(b){}
};

vector<node> e[maxn];
int D[maxn];
int Max;

void dfs(int u,int f,int sum){
	D[u]=sum;
	int v,w;
	for(int i=0;i<(int)e[u].size();i++){
		v=e[u][i].to;
		w=e[u][i].w;
		if(v!=f){
			dfs(v,u,sum+w);
		}
	}
}

void solve(){
	dfs(1,0,0);
	int res1=1,res2=1;
	for(int i=1;i<=Max;i++){
		if(D[i]>D[res1]){
			res1=i;
		}
	}
	memset(D,0,sizeof(D));
	dfs(res1,0,0);
	for(int i=1;i<=Max;i++){
		if(D[i]>D[res2]){
			res2=i;
		}
	}
	printf("%d\n",D[res2]);
}

int main(void){
	int u,v,w;
	Max=0;
	while(scanf("%d %d %d",&u,&v,&w)!=EOF){
		e[v].push_back(node(u,w));
		e[u].push_back(node(v,w));
		Max=max(Max,v);
		Max=max(Max,u);
	}
	solve();
	return 0;
}
