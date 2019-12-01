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

const int maxn=3e4+10;

int pre[maxn],res[maxn];
int n,m;

int Find(int x){
	return pre[x]==-1?x:pre[x]=Find(pre[x]);
}

void Union(int x,int y){
	int nx=Find(x),ny=Find(y);
	if(nx==ny)
		return ;
	pre[nx]=ny;
	res[ny]+=res[nx];
}

void solve(){
	int ans=0;
	int rt=Find(0);
	printf("%d\n",res[rt]);
}

int main(void){
	int k;
	int u,v;
	while(scanf("%d %d",&n,&m)!=EOF){
		if(n==0&&m==0)
			break;
		for(int i=0;i<n;i++)
			res[i]=1;
		memset(pre,-1,sizeof(pre));
		for(int i=0;i<m;i++){
			scanf("%d %d",&k,&u);
			for(int j=1;j<k;j++){
				scanf("%d",&v);
				Union(v,u);
			}
		}
		solve();
	}
	return 0;
}
