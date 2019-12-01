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

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e3+10;
const int maxw=1e6+10;

int t,n;
vector<pii> e[maxn];
priority_queue<pii,vector<pii>,greater<pii> > q;
int D[maxn];
bool isv[maxn];

void solve(int st){
	for(int i=1;i<=n;i++){
		isv[i]=0;
		D[i]=maxw;
	}
	D[st]=0;
	q.push(pii(D[st],st));
	pii now;
	int u,v,w;
	while(!q.empty()){
		now=q.top();
		q.pop();
		u=now.second;
		if(isv[u])
			continue;
		isv[u]=1;
		for(int i=0;i<(int)e[u].size();i++){
			v=e[u][i].second;
			w=e[u][i].first;
			if(D[u]+w<D[v]){
				D[v]=D[u]+w;
				q.push(pii(D[v],v));
			}
		}
	}
	printf("%d\n",D[n]);
}

int main(void){
	int u,v,w;
	while(scanf("%d %d",&t,&n)!=EOF){
		for(int i=0;i<t;i++){
			scanf("%d %d %d",&u,&v,&w);
			e[v].push_back(pii(w,u));
			e[u].push_back(pii{w,v});
		}		
		solve(1);
	}
	return 0;
}
