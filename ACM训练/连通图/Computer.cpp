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

vector<node> e[maxn];
ll n;
ll Max1,Max2;
ll dp[maxn][3];

void dfs_back(ll u,ll f){
	ll v,w;
	ll Max1=0,Max2=0;
	for(ll i=0;i<(ll)e[u].size();i++){
		v=e[u][i].to;
		if(v==f)
			continue;
		dfs_back(v,u);
		w=e[u][i].w;
		if(dp[v][0]+w>Max1){
			Max2=Max1;
			Max1=dp[v][0]+w;
		}
		else if(dp[v][0]+w>Max2){
			Max2=dp[v][0]+w;
		}
	}
	//deb(u);
	//deb(Max1);
	//deb(Max2);
	//puts("");
	dp[u][0]=Max1;
	dp[u][1]=Max2;
}

void dfs_front(ll u,ll f){
	ll v,w,tmp;
	for(ll i=0;i<(ll)e[u].size();i++){
		v=e[u][i].to;
		if(v==f)
			continue;
		w=e[u][i].w;
		if(dp[u][0]==dp[v][0]+w){
			tmp=dp[u][1];
		}
		else{
			tmp=dp[u][0];
		}
		dp[v][2]=max(dp[u][2],tmp)+w;
		dfs_front(v,u);
	}
}

void solve(){
	dfs_back((ll)1,(ll)0);
	dfs_front((ll)1,(ll)0);
	for(ll i=1;i<=n;i++){
		printf("%lld\n",max(dp[i][0],dp[i][2]));
		e[i].clear();
	}
}

int main(void){
	ll u,w;
	while(scanf("%lld",&n)!=EOF){
		for(int i=2;i<=n;i++){
			scanf("%lld %lld",&u,&w);
			e[i].push_back({u,w});
			e[u].push_back({i,w});
		}
		solve();
	}
	return 0;
}
