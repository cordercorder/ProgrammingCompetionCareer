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

const int maxn=2e5+10;

int n,m,q;
vector<int> e[maxn+maxn];
bool isv[maxn+maxn];

void dfs(int u){
	isv[u]=1;
	for(int i=0;i<(int)e[u].size();i++){
		if(!isv[e[u][i]]){
			dfs(e[u][i]);
		}
	}
}

void solve(){
	int len=m+n;
	ll ans=0;
	for(int i=1;i<=len;i++){
		if(!isv[i]){
			//deb(i);
			dfs(i);
			ans++;
		}
	}
	ans-=1;
	printf("%lld\n",ans);
}

int main(void){
	int u,v;
	scanf("%d %d %d",&n,&m,&q);
	while(q--){
		scanf("%d %d",&u,&v);
		v+=n;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	solve();
	return 0;
}
