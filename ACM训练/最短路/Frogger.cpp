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
const double maxw=1e10+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=2e2+10;

struct node{
	int to;
	double w;
	bool operator<(const node &a)const{
		return w>a.w;
	}
}; 

double x[maxn],y[maxn];
int n;
vector<node> e[maxn];
bool isv[maxn];
double D[maxn];
priority_queue<node> q;

void pre_handle(){
	double tmp;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(i==j)
				continue;
			tmp=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			e[i].push_back({j,tmp});
			e[j].push_back({i,tmp});
		}
	}
}

void solve(int st,int ed){
	pre_handle();
	for(int i=1;i<=n;i++){
		isv[i]=0;
		D[i]=maxw;
	}
	D[st]=(double)0;
	q.push({st,D[st]});
	node now;
	int u,v;
	double w;
	while(!q.empty()){
		now=q.top();
		q.pop();
		u=now.to;
		if(isv[u])
			continue;
		isv[u]=1;
		for(int i=0;i<(int)e[u].size();i++){
			v=e[u][i].to;
			w=max(e[u][i].w,D[u]);
			if(D[v]>w){
				D[v]=w;
				q.push({v,D[v]});
			}
		}
	}
	cout.precision(3);
	cout<<fixed<<D[ed]<<'\n';
	for(int i=1;i<=n;i++){
		e[i].clear();
	}
}

int main(void){
	int ca=0;
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		for(int i=1;i<=n;i++){
			scanf("%lf %lf",&x[i],&y[i]);
		}
		printf("Scenario #%d\n",++ca);
		printf("Frog Distance = ");
		solve(1,2);
		puts("");
	}
	return 0;
}
