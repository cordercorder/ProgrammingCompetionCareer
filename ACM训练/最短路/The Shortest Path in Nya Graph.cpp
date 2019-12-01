#include<algorithm>
#include<iostream>
#include<limits.h>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<string>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<ctime>
#include<set>
#include<map>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("data.txt","r",stdin)
#define FOUT freopen("data.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const int maxw=1e9+1e8+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const ll maxn=1e5+10;

struct node{
	int to;
	int w;
	bool operator<(const node &a)const{
		return w>a.w;
	}
	node(){}
	node(int a,int b):to(a),w(b){}
};

int t,n,m,c;
vector<node> e[maxn*3];
int D[maxn*3];
bool isv[maxn*3];
priority_queue<node> q;
int ans;

void handle(int st){
	for(int i=1;i<=3*n;i++){
		D[i]=maxw;
		isv[i]=0;
	}
	D[st]=0;
	q.push(node(st,D[st]));
	node now;
	int u,v,w;
	while(!q.empty()){
		now=q.top();
		q.pop();
		u=now.to;
		if(isv[u])
			continue;
		isv[u]=1;
		for(ll i=0;i<(int)e[u].size();i++){
			v=e[u][i].to;
			w=e[u][i].w;
			if((ll)D[v]>(ll)D[u]+w){
				D[v]=D[u]+w;
				q.push(node(v,D[v])); 
			}
		}
	}
	ans=D[n];
}

void solve(){
	handle(1);
	if(ans==maxw){
		puts("-1");
	}
	else{
		printf("%d\n",ans);
	}
	for(ll i=1;i<=3*n;i++){
		e[i].clear();
	}
}

int main(void){
	int u,v,w,l;
	scanf("%d",&t);
	for(int ca=1;ca<=t;ca++){
		scanf("%d %d %d",&n,&m,&c);
		for(int i=1;i<=n;i++){
			scanf("%d",&l);
			e[i].push_back(node(n+2*l,0));
			e[n+2*l-1].push_back(node(i,0));
		}
		for(int i=1;i<n;i++){
			e[n+2*i].push_back(node(n+2*(i+1)-1,c));
			e[n+2*(i+1)].push_back(node(n+2*i-1,c));
		}
		for(int i=0;i<m;i++){
			scanf("%d %d %d",&u,&v,&w);
			e[u].push_back(node(v,w));
			e[v].push_back(node(u,w));
		}
		printf("Case #%d: ",ca);
		solve();
	}
	return 0;
}
