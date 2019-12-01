# include<iostream>
# include<algorithm>
# include<cstring>
# include<string>
# include<cmath>
# include<queue>
# include<stack>
# include<set>
# include<vector>
# include<cstdio>
# include<cstdlib>
# include<map>
# include<deque>
# include<limits.h>
# include<ctime>

# define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=2e3+10;
const int maxw=1e9+10;

int a[maxn];
int b[maxn];
int n; 
int dp[2][maxn];

void solve(){
	int ans=maxw;
	int Min;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		Min=maxw;
		for(int j=1;j<=n;j++){
			Min=min(dp[(i-1)%2][j],Min);
			dp[i%2][j]=Min+abs(a[i]-b[j]);
		}
	}
	for(int i=1;i<=n;i++){
		ans=min(ans,dp[n%2][i]);
	}
	printf("%d\n",ans);
}

int main(void){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		sort(b+1,b+1+n);
		solve();
	}
	return 0;
}
