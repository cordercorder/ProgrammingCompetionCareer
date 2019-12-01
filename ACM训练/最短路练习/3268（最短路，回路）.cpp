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
const int maxw=1e8+10;

int n,m,x;
vector<pii> e[2][maxn];
int D[2][maxn];
bool isv[maxn];
priority_queue<pii,vector<pii>,greater<pii> > q;

void dijstra(int id,int st){
	for(int i=1;i<=n;i++){
		isv[i]=0;
		D[id][i]=maxw;
	}
	D[id][st]=0;
	q.push(pii(D[id][st],st));
	pii now;
	int u,v,w;
	while(!q.empty()){
		now=q.top();
		q.pop();
		u=now.second;
		if(isv[u])
			continue;
		isv[u]=1;
		for(int i=0;i<e[id][u].size();i++){
			v=e[id][u][i].second;
			w=e[id][u][i].first;
			if(w+D[id][u]<D[id][v]){
				D[id][v]=w+D[id][u];
				q.push(pii(D[id][v],v));
			}
		}
	}
}

void solve(){
	dijstra(0,x);
	dijstra(1,x);
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,D[0][i]+D[1][i]);
	//	deb(D[0][i]);
	//	deb(D[1][i]);
	}
	printf("%d\n",ans);
}

int main(void){
	int u,v,w;
	while(scanf("%d %d %d",&n,&m,&x)!=EOF){
		for(int i=0;i<m;i++){
			scanf("%d %d %d",&u,&v,&w);
			e[0][u].push_back(pii(w,v));
			e[1][v].push_back(pii(w,u));
		}
		solve();
	}
	return 0;
}
