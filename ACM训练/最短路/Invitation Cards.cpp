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
const long long maxw=1e9+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const ll maxn=1e6+10;

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
}edge[2][maxn];

ll t;
ll n,m;
priority_queue<node> q;
ll D[maxn];
bool isv[maxn];
ll ans;
ll cnt[2];
ll head[2][maxn];

void add(ll id,ll u,ll v,ll w){
    edge[id][cnt[id]].w=w;
    edge[id][cnt[id]].to=v;
    edge[id][cnt[id]].next=head[id][u];
    head[id][u]=cnt[id]++;
}

void Init_e(){
	cnt[0]=0;
	cnt[1]=0;
	for(ll i=1;i<=(n+1);i++){
		head[0][i]=-1;
		head[1][i]=-1;
	}
}

void handle(ll id,ll st){
	for(ll i=1;i<=n;i++){
		isv[i]=0;
		D[i]=maxw;
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
		for(int i=head[id][u];~i;i=edge[id][i].next){
			v=edge[id][i].to;
			w=edge[id][i].w;
			if(D[v]>D[u]+w){
				D[v]=D[u]+w;
				q.push({v,D[v]});
			}
		}
	}
	for(ll i=1;i<=n;i++){
		ans+=(ll)D[i];
	}
}

void solve(){
	ans=0;
	handle((ll)0,(ll)1);
	handle((ll)1,(ll)1);
	//cout<<ans<<endl;
	printf("%lld\n",ans);
}

int main(void){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	//cin>>t;
	scanf("%lld",&t);
	ll u,v,w;
	while(t--){
		//cin>>n>>m;
		scanf("%lld %lld",&n,&m);
		Init_e();
		for(ll i=1;i<=m;i++){
			//cin>>u>>v>>w;
			scanf("%lld %lld %lld",&u,&v,&w);
			add((ll)0,u,v,w);
			add((ll)1,v,u,w);
		}
		solve();
	}
	return 0;
}
