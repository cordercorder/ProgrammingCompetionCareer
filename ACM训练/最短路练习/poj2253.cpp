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
typedef pair<double,int> pii;

const int maxn=2e2+10;
const double maxw=1e7+10;

struct node{
	double x;
	double y;
}p[maxn];

int n;

vector<pii> e[maxn*maxn+10];
bool isv[maxn];
priority_queue<pii,vector<pii>,greater<pii> > q;
double D[maxn];

double dis(node &a,node &b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void handle(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)
				continue;
			e[i].push_back(pii(dis(p[i],p[j]),j));
			//deb(dis(p[i],p[j]));
		}
	}
}

void solve(){
	handle();
	for(int i=1;i<=n;i++){
		isv[i]=0;
		D[i]=maxw;
	}
	D[1]=0;
	q.push(pii(D[1],1));
	pii now,tmp;
	int u,v;
	double w;
	while(!q.empty()){
		now=q.top();
		q.pop();
		u=now.second;
		if(isv[u])
			continue;
		isv[u]=1;
	//	deb(u);
		for(int i=0;i<e[u].size();i++){
			v=e[u][i].second;
			if(isv[v])
				continue;
			w=max(e[u][i].first,D[u]);
		//	deb(w);
		//	deb(v);
			if(w<D[v]){
				D[v]=w;
				q.push(pii(D[v],v));
			}
		}
	}
	printf("Frog Distance = %.3lf\n\n",D[2]);
	for(int i=1;i<=n;i++)
		e[i].clear();
}

int main(void){
	int sum=0;
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		for(int i=1;i<=n;i++){
			scanf("%lf %lf",&p[i].x,&p[i].y);
		}
		printf("Scenario #%d\n",++sum);
		solve();
	}
	return 0;
}
