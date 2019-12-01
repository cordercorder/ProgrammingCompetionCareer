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
typedef pair<int,int> pii;

const int maxn=2e5+10;
vector<int> e[maxn],res;
int n,q;
int ret[maxn],cnt,ed[maxn],cnt2;
int u,k;

void dfs(int x){
	int u;
	res.push_back(x); 
	ret[x]=cnt++;
	for(int i=0;i<e[x].size();i++){
		u=e[x][i];
		dfs(u);
	}
	ed[x]=cnt-1;
}

void solve(){
	int pos=ret[u];
	if(e[u].empty()){
		if(k==1){
			printf("%d\n",u);
		}
		else{
			puts("-1");
		}
		return ;
	}
	int pos2=ed[u];
	if(pos-1+k>pos2){
		puts("-1");
		return ;
	}
	int ans=res[pos-1+k-1];
	printf("%d\n",ans);
}

int main(void){
	int p;
	while(scanf("%d %d",&n,&q)!=EOF){
		for(int i=2;i<=n;i++){
			scanf("%d",&p);
			e[p].push_back(i);
		}
		cnt=1;
		cnt2=n;
		dfs(1);
		while(q--){
			scanf("%d %d",&u,&k);
			solve();
		}
	}
	return 0;
}
