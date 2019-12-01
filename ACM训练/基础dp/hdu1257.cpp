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

const int maxn=1e4+10;
int dp[maxn];

int n;
int a[maxn];

void solve(){
	int ans=0;
	for(int i=1;i<=n;i++){
		dp[i]=1;
		for(int j=1;j<i;j++){
			if(a[i]>a[j]){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
}

int main(void){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		solve();
	}
	return 0;
}
