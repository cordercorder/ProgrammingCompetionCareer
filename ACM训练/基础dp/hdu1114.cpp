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
const int maxw=1e7+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=5e2+10;

int t,E,F;
int ret;
int n;
int P[maxn],W[maxn];
int dp[10000+100];

void solve(){
	ret=F-E;
	for(int i=1;i<=10000;i++){
		dp[i]=maxw;
	}
	dp[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=W[i];j<=ret;j++){
			dp[j]=min(dp[j],dp[j-W[i]]+P[i]);
			//deb(dp[j]);
		}
	}
	if(dp[ret]==maxw){
		puts("This is impossible.");
		return ;
	}
	printf("The minimum amount of money in the piggy-bank is %d.\n",dp[ret]);
}

int main(void){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&E,&F);
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d",&P[i],&W[i]);
		}
		solve();
	}
	return 0;
}
