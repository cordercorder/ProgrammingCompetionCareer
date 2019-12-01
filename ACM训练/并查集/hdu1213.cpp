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

const int maxn=1e3+10;

int t,n,m;
int pre[maxn];

int Find(int x){
	return pre[x]==-1?x:pre[x]=Find(pre[x]);
}

void Union(int x,int y){
	int nx=Find(x),ny=Find(y);
	if(nx!=ny){
		pre[nx]=ny;
	}
}

void solve(){
	int ans=0;
	for(int i=1;i<=n;i++){
		pre[i]==-1?++ans:ans;
	}
	printf("%d\n",ans);
}

int main(void){
	int a,b;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		memset(pre,-1,sizeof(pre));
		for(int i=0;i<m;i++){
			scanf("%d %d",&a,&b);
			Union(a,b);
		}
		solve();
	}
	return 0;
}
