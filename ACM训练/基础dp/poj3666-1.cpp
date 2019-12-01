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

const int maxn=2e3+10;

ll n; 
int a[maxn],b[maxn];
ll dp[maxn][maxn];

void solve(){
	sort(b+1,b+1+n);
	ll Min,ans=maxw;
	for(ll i=1;i<=n;i++){
		Min=maxw;
		for(ll j=1;j<=n;j++){
			Min=min(Min,dp[i-1][j]);
			dp[i][j]=abs(a[i]-b[j])+Min;
		}
	}
	for(ll i=1;i<=n;i++){
		ans=min(ans,dp[n][i]);
	}
	printf("%lld\n",ans);
}

int main(void){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	solve();
	return 0;
}
