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

vector<node> e[maxn];
int n,m,x;
bool isv[maxn];
int D[maxn];
priority_queue<node> q;
int ans[maxn];

void cal(int st){
	for(int i=1;i<=n;i++){
		isv[i]=0;
		D[i]=maxw;
	}
	D[st]=0;
	q.push({st,D[st]});
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
			if(D[v]>D[u]+w){
				D[v]=D[u]+w;
				q.push({v,D[v]});
			}
		}
	}
}

void solve(){
	cal(x);
	for(int i=1;i<=n;i++){
		ans[i]=D[i];
	}
	for(int i=1;i<=n;i++){
		cal(i);
		ans[i]+=D[x];
	}
	printf("%d\n",*max_element(ans+1,ans+1+n));
}

int main(void){
	int u,v,w;
	scanf("%d %d %d",&n,&m,&x);
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&w);
		e[u].push_back({v,w});
	}
	solve();
	return 0;
}
