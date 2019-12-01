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
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

using namespace std;

const long double PI=acos(-1.0); 
const long double eps=1e-6;
const long long maxw=1e10+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const ll maxn=3e4+10;

struct node{
	ll to;
	ll w;
	bool operator<(const node &a)const{
		return w>a.w;
	}
};

struct E{
	ll next;
	ll to;
	ll w;
}edge[150000+100];

ll n,m;
ll D[maxn];
bool isv[maxn];
priority_queue<node> q;

ll cnt;
ll head[maxn];

void add(ll u,ll v,ll w){
    edge[cnt].w=w;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

void Init_e(){
	cnt=0;
	for(ll i=1;i<=(n+1);i++){
		head[i]=-1;
	}
}

void solve(ll st){
	for(ll i=1;i<=n;i++){
		D[i]=maxw;
		isv[i]=0;
	}
	D[st]=0;
	q.push({st,D[st]});
	node now;
	ll u,v,w;
	while(!q.empty()){
		now=q.top();
		q.pop();
		u=now.to;
		if(isv[u])
			continue;
		isv[u]=1;
		for(ll i=head[u];i!=-1;i=edge[i].next){
			v=edge[i].to;
			w=edge[i].w;
			if(D[v]>D[u]+w){
				D[v]=D[u]+w;
				q.push({v,D[v]});
			}
		}
	}
	cout<<D[n];
	//printf("%lld\n",D[n]);
}

int main(void){
	//FC;
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	//scanf("%lld %lld",&n,&m);
	Init_e();
	ll u,v,w;
	for(ll i=1;i<=m;i++){
		//scanf("%lld %lld %lld",&u,&v,&w);
		cin>>u>>v>>w;
		add(u,v,w);
	}
	solve((ll)1);
	return 0;
}
