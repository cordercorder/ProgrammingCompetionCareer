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
const int maxw=-1e7-10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e5+10;

int n;
int a[maxn];
int dp[maxn][15];
int res[maxn][15];

void solve(){
	for(int i=0;i<=10;i++){
		dp[0][i]=maxw;
	}
	dp[0][5]=0;
	for(int i=1;i<=100000;i++){
		for(int j=0;j<=10;j++){
			if(j==0){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j+1])+res[i][j];
			}
			else if(j==n){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+res[i][j];
			}
			else{
				dp[i][j]=max(dp[i-1][j],max(dp[i-1][j-1],dp[i-1][j+1]))+res[i][j];
			}
		}
	}
	int ans=0;
	for(int i=0;i<=10;i++){
		ans=max(ans,dp[100000][i]);
	}
	printf("%d\n",ans);
}

int main(void){
	int x,T;
	while(scanf("%d",&n)!=EOF){
		if(n==0){
			break;
		}
		memset(res,0,sizeof(res));
		for(int i=1;i<=n;i++){
			scanf("%d %d",&x,&T);
			res[T][x]++;
		}
		solve();
	}
	return 0;
}
