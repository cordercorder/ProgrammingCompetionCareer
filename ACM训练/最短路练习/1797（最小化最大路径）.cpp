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

vector<pii> e[maxn];
int t,n,m;
priority_queue<pii>q;
int D[maxn];
bool isv[maxn];

void solve(){
	for(int i=1;i<=n;i++){
		isv[i]=0;
		D[i]=0;
	}
	D[1]=1000000+10;
	q.push(pii(D[1],1));
	pii now;
	int u,v,w;
	while(!q.empty()){
		now=q.top();
		q.pop();
		u=now.second;
		if(isv[u])
			continue;
		isv[u]=1;
		for(int i=0;i<e[u].size();i++){
			v=e[u][i].second;
			if(isv[v])
				continue;
			w=min(e[u][i].first,D[u]);
			if(w>D[v]){
				D[v]=w;
				q.push(pii(D[v],v));
			}
		}
	}
	printf("%d\n\n",D[n]);
	for(int i=1;i<=n;i++){
		e[i].clear();
	}
}

int main(void){
	int u,v,w;
	int sum=0;
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d %d",&n,&m);
			for(int i=0;i<m;i++){
				scanf("%d %d %d",&u,&v,&w);
				e[u].push_back(pii(w,v));
				e[v].push_back(pii(w,u));
			}
			printf("Scenario #%d:\n",++sum);
			solve(); 
		}
	}
	return 0;
}
