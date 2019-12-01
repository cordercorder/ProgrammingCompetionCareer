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

const int maxn=2e5+10;

struct node{
	int next;
	int to;
}edge[maxn];

struct Node{
	int u;
	int steps;
	vector<int> path;
	Node():steps(0){}
};

queue<Node> Que;
int cnt;
int head[maxn];
int n,m;
int si;
int out[maxn],in[maxn];
int res[maxn];
bool isv[maxn][2];
int path[maxn],len;

void Init_e(){
	cnt=0;
	memset(head,-1,sizeof(head));
	memset(isv,0,sizeof(isv));
}

void add(int u,int v){
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}

bool dfs(int x,int sum){
	isv[x][sum&1]=1;
	path[sum]=x;
	if(out[x]==0&&(sum&1)){
		len=sum;
		return 1;
	}
	int u;
	for(int i=head[x];i!=-1;i=edge[i].next){
		u=edge[i].to;
		if(!isv[u][(sum+1)&1]&&dfs(u,sum+1))
			return 1;
	}
	return 0;
}

bool check(int x){
	res[x]=1;
	int u;
	for(int i=head[x];i!=-1;i=edge[i].next){
		u=edge[i].to;
		if(res[u]==0&&check(u)){
			return 1;
		}
		if(res[u]==1)
			return 1;
	}
	res[x]=2;
	return 0;
}

void solve(){
	if(dfs(si,0)){
		puts("Win");
		for(int i=0;i<=len;i++){
			printf("%d ",path[i]);
		}
		puts("");
		return;
	}
	
	if(check(si)){
		puts("Draw");
		return ;
	}
	puts("Lose");
}

int main(void){
	int k,v;
	scanf("%d %d",&n,&m);
	cnt=0;
	Init_e();
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d",&v);
			add(i,v);
			out[i]++;
			in[v]++;
		}
	}
	scanf("%d",&si);
	solve();
	return 0;
}
