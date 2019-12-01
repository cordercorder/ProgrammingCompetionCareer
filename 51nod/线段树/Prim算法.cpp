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


vector<pii> p[maxn];
priority_queue<pii,vector<pii>,greater<pii> > q;
int n,m;
bool isv[maxn];
int D[maxn];

void sovle(){
	for(int i=1;i<=n;i++){
		isv[i]=0;
		D[i]=maxw;
	}
	q.push({0,1});
	pii now;
	int u,v,w;
	int ans=0;
	while(!q.empty()){
		now=q.top();
		q.pop();
		u=now.second;
		if(isv[u])
			continue;
		isv[u]=1;
		ans+=now.first;
		for(int i=0;i<(int)p[u].size();i++){
			v=p[u][i].second;
			w=p[u][i].first;
			if(!isv[v]&&D[v]>w){
				D[v]=w;
				q.push({D[v],v});
			}
		}
	}
	printf("%d\n",ans);
}

int main(void){
	int u,v,w;
	while(scanf("%d %d",&n,&m)!=EOF){
		for(int i=0;i<m;i++){
			scanf("%d %d %d",&u,&v,&w);
			p[u].push_back({w,v});
			p[v].push_back({w,u});
		}
		sovle();
	}
	return 0;
}
