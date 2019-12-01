# include<iostream>
# include<algorithm>
# include<cstring>
# include<string>
# include<cmath>
# include<queue>
# include<stack>
# include<set>
# include<vector>
# include<cstdio>
# include<cstdlib>
# include<map>
# include<deque>
# include<limits.h>
# include<ctime>

# define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e3+10;
const int maxw=1e7+10;


int m,n; 
vector<pii> p[maxn];
int D[maxn];
priority_queue<pii,vector<pii>,greater<pii> > q;
bool isv[maxn];

void solve(int ss){
	for(int i=0;i<=n;i++){
		D[i]=maxw;
		isv[i]=0;
	}
	D[ss]=0;
	q.push({0,ss});
	pii now;
	int u,v,w;
	while(!q.empty()){
		now=q.top();
		q.pop();
		u=now.second;
		if(isv[u])
			continue;
		isv[u]=1;
		//deb(u);
		//deb(w);
		for(int i=0;i<p[u].size();i++){
			v=p[u][i].second;
			w=p[u][i].first;
			if(!isv[v]&&D[v]>D[u]+w){
				D[v]=D[u]+w;
				q.push({D[v],v});
			}
		}
	}
}

int main(void){
	int u,v,w;
	while(scanf("%d %d",&m,&n)!=EOF){
		for(int i=0;i<m;i++){
			scanf("%d %d %d",&u,&v,&w);
			p[u].push_back({w,v});
			p[v].push_back({w,u});
		}
		solve(1);
		printf("%d\n",D[n]);
	}
	return 0;
}
