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

const int maxn=1e5+10;

struct node{
	ll to;
	ll w;
};

vector<node> e[maxn];
ll n,m;
ll ans,id;

void dfs(ll u,ll f,ll sum){
	if(ans<sum){
		ans=sum;
		id=u;
	}
	ll v;
	for(ll i=0;i<(ll)e[u].size();i++){
		v=e[u][i].to;
		if(v==f)
			continue;
		dfs(v,u,sum+e[u][i].w);
	}
}

void solve(){
	ans=-1;
	dfs((ll)1,(ll)0,(ll)0);
	ans=-1;
	dfs(id,(ll)0,(ll)0);
	printf("%lld\n",ans);
}

int main(void){
	ll u,v,w;
	char tmp[10];
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=m;i++){
		scanf("%lld %lld %lld %s",&u,&v,&w,tmp);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	solve();
	return 0;
}
