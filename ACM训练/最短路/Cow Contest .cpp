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
const int maxw=1e7+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e2+10;

struct node{
	int to;
	int w;
	bool operator<(const node &a)const{
		return w>a.w;
	}
};

vector<node> e[maxn];
int n,m;
int D[maxn][maxn];
bool isv[maxn];
priority_queue<node> q;

void handle(int st){
	for(int i=1;i<=n;i++){
		isv[i]=0;
		D[st][i]=maxw;
	}
	D[st][st]=0;
	q.push({st,D[st][st]});
	node now;
	int u,v,w;
	while(!q.empty()){
		now=q.top();
		q.pop();
		u=now.to;
		if(isv[u])
			continue;
		isv[u]=1;
		for(int i=0;i<(int)e[u].size();i++){
			v=e[u][i].to;
			w=e[u][i].w;
			if(D[st][v]>D[st][u]+w){
				D[st][v]=D[st][u]+w;
				q.push({v,D[st][v]});			
			}
		}
	}
}

void solve(){
	for(int i=1;i<=n;i++){
		handle(i);
	}
	int sum,ans=0;
	for(int i=1;i<=n;i++){
		sum=0;
		for(int j=1;j<=n;j++){
			//deb(D[i][j]);
			if(i==j)
				continue;
			if(D[i][j]!=maxw||D[j][i]!=maxw){
				sum++;
			}
		}
		if(sum==n-1){
			ans++;
		}
	}
	printf("%d\n",ans);
}

int main(void){
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&u,&v);
		e[u].push_back({v,1});
	}
	solve();
	return 0;
}
