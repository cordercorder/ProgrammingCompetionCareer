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
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const ll maxn=1e5+10;

struct node{
	ll to;
	ll w;
};

ll t[maxn];
ll n;
vector<node> e[maxn];
ll sum[maxn],sum_w[maxn];
ll dp[maxn];
ll SS;

void dfs(ll u,ll f){
	sum[u]=t[u];
	sum_w[u]=0;
	ll v,w;
	for(ll i=0;i<(ll)e[u].size();i++){
		v=e[u][i].to;
		if(v==f)
			continue;
		dfs(v,u);
		w=e[u][i].w;
		sum_w[u]+=(sum[v]*w+sum_w[v]);
		sum[u]+=sum[v];
	}
}

void dfs2(ll u,ll f){
	ll v,w;
	for(ll i=0;i<(ll)e[u].size();i++){
		v=e[u][i].to;
		if(v==f)
			continue;
		w=e[u][i].w;
		dp[v]=sum_w[u]+(SS-sum[v])*w-sum[v]*w;
		sum_w[v]=dp[v];
		dfs2(v,u);
	}
}

void solve(){
	dfs(1,0);
	SS=sum[1];
	dp[1]=sum_w[1];
	dfs2(1,0);
	ll ans=dp[1];
	for(ll i=2;i<=n;i++){
		ans=min(ans,dp[i]); 
	}
	printf("%lld\n",ans);
	for(ll i=1;i<=n;i++){
		e[i].clear();
	}
}

int main(void){
	ll u,v,w;
	while(scanf("%lld",&n)!=EOF){
		for(ll i=1;i<=n;i++){
			scanf("%lld",&t[i]);
		}
		for(ll i=1;i<n;i++){
			scanf("%lld %lld %lld",&u,&v,&w);
			e[u].push_back({v,w});
			e[v].push_back({u,w});
		}
		solve();
	}
	return 0;
}
