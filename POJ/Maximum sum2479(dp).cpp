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

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

const int maxsize=5e4+10;
const int minw=-1e9;

int t;
int n;
int dp[2][maxsize];
int a[maxsize];

void solve(){
	for(int i=0;i<=n+1;i++){
		dp[0][i]=minw;
		dp[1][i]=minw;
	}
	for(int i=1;i<=n;i++){
		dp[0][i]=max(a[i],dp[0][i-1]+a[i]);
	}
	for(int i=1;i<=n;i++){
		dp[0][i]=max(dp[0][i],dp[0][i-1]);
	}
	//for(int i=1;i<=n;i++){
	//	cout<<dp[0][i]<<" ";
	//}
	//cout<<endl;
	for(int i=n;i>=1;i--){
		dp[1][i]=max(a[i],dp[1][i+1]+a[i]);		
	}
	for(int i=n;i>=1;i--){
		dp[1][i]=max(dp[1][i],dp[1][i+1]);
	}
	int ans=INT_MIN;
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[0][i]+dp[1][i+1]);
		//cout<<"###"<<dp[0][i]<<endl;
		//cout<<"@@@@"<<dp[1][i+1]<<endl;
	}
	printf("%d\n",ans);
}

int main(void){
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d",&n);
			for(int i=1;i<=n;i++){
				scanf("%d",&a[i]);
			}
			solve();			
		}
	}
	return 0;
}
