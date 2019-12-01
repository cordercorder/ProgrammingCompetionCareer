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
const int maxw=1e3+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e2+10;

int n,m,K,s; 
int v[maxn],w[maxn];
int dp[maxn][maxn];

void solve(){
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=K;i++){
		for(int j=w[i];j<=m;j++){
			for(int k=1;k<=s;k++){
				dp[j][k]=max(dp[j][k],dp[j-w[i]][k-1]+v[i]);
			}
		}
	}
	int ans=maxw;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=s;j++){
			//deb(dp[i][j]);
			if(dp[i][j]>=n){
				ans=min(ans,i);
			}
		}
	}
	if(ans==maxw){
		puts("-1");
		return ;
	}
	ans=m-ans;
	printf("%d\n",ans);
}

int main(void){
	while(scanf("%d %d %d %d",&n,&m,&K,&s)!=EOF){
		for(int i=1;i<=K;i++){
			scanf("%d %d",&v[i],&w[i]);
		}
		solve();
	}
	return 0;
}
