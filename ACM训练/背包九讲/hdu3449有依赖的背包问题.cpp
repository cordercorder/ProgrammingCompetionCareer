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
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const int maxw=-1e7-10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=55;

int n,w;

int p[maxn],m[maxn];
struct node{
	int c;
	int v;
};
vector<node> res[maxn];
int dp[maxn][100000+100];

void solve(){
	memset(dp,-1,sizeof(dp));
	memset(dp[0],0,sizeof(dp[0]));
	for(int i=1;i<=n;i++){
		for(int j=p[i];j<=w;j++){
			dp[i][j]=dp[i-1][j-p[i]];
		}
		for(int j=0;j<(int)res[i].size();j++){
			for(int k=w;k>=res[i][j].c;k--){
				if(dp[i][k-res[i][j].c]!=-1){
					dp[i][k]=max(dp[i][k],dp[i][k-res[i][j].c]+res[i][j].v);
				}						
			}
		}
		for(int j=0;j<=w;j++){
			dp[i][j]=max(dp[i][j],dp[i-1][j]);
		}		
	}
	printf("%d\n",dp[n][w]);
}

int main(void){
	while(scanf("%d %d",&n,&w)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d %d",&p[i],&m[i]);
			res[i].resize(m[i]); 
			for(int j=0;j<m[i];j++){
				scanf("%d %d",&res[i][j].c,&res[i][j].v);
			}
		}
		solve();
	}	
	return 0;
}
