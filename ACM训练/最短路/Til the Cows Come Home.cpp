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

const int maxn=1e3+10;

struct node{
	int to;
	int w;
	bool operator<(const node &a)const{
		return w>a.w;
	}
};

int n,m;
vector<node> e[maxn];
bool isv[maxn];
int D[maxn];
priority_queue<node> q;
 
void solve(int st,int ed){
	for(int i=1;i<=n;i++){
		D[i]=maxw;
		isv[i]=0;
	}
	D[st]=0;
	q.push({st,D[st]});
	node now;
	int v,u,w;
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
			if(D[v]>D[u]+w){
				D[v]=D[u]+w;
				q.push({v,D[v]});
			}
		}
	}
	printf("%d\n",D[ed]);
}

int main(void){
	int u,v,w;
	scanf("%d %d",&m,&n);
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	solve(1,n);
	return 0;
}
