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

const int maxsize=1e2+10;

int t;
int n,c[3];
int w[maxsize];
int sum;
int dp[maxsize][maxsize];

void solve(int nw){
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++){
		for(int j=0;j<=nw;j++){
			if(j>=w[i]){
				dp[i+1][j]=max(dp[i][j],dp[i][j-w[i]]+w[i]);
			}
			else
				dp[i+1][j]=dp[i][j];
		}
	}
	if(dp[n][nw]==0)
		return ;
	sum-=dp[n][nw];
	int k=nw;
	for(int i=n;i>=1;i--){
		if(dp[i][k]>dp[i-1][k]){
			k-=w[i-1];
			w[i-1]=0;
			cout<<"i-1=="<<i-1<<endl;	
		}
	}
	cout<<endl;
}

int main(void){
	int ans;
	while(scanf("%d",&t)!=EOF){
		for(int i=1;i<=t;i++){
			scanf("%d %d %d",&n,&c[1],&c[2]);
			sum=0;
			ans=0;
			for(int j=0;j<n;j++){
				scanf("%d",&w[j]);
				sum+=w[j];
			}
			while(sum>0){
				solve(c[1]);	
				//cout<<"sum=="<<sum<<endl;
				//cout<<"tmp=="<<tmp<<endl; 
				if(sum==0){
					ans++;
					break;
				}
				solve(c[2]);
				ans++;
			}
			printf("Scenario #%d:\n",i);
			printf("%d\n\n",ans);
		}		
	}
	return 0;
}
