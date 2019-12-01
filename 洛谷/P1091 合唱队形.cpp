# include<iostream>
# include<algorithm>
# include<string>
# include<cstdio>
# include<cstring>
# include<cstdlib>
# include<vector>
# include<queue>
# include<set>
# include<cmath>

using namespace std;

const int maxsize=1e2+5;

int n;
int a[maxsize];
int dp1[maxsize];
int dp2[maxsize];

void solve(){
	int i,j,ans=0;
	for(i=0;i<n;i++){
		dp1[i]=1;
		for(j=0;j<i;j++){
			if(a[j]<a[i]&&dp1[i]<dp1[j]+1){//最长上升子序列 
				dp1[i]=dp1[j]+1;
			}
		}
	}
	for(i=n-1;i>=0;i--){
		dp2[i]=1;
		for(j=n-1;j>i;j--){
			if(a[i]>a[j]&&dp2[i]<dp2[j]+1)
				dp2[i]=dp2[j]+1;
		}
	}
	for(i=0;i<n;i++){
		ans=max(ans,dp1[i]+dp2[i]);
	}
	printf("%d\n",n-ans+1);
}

int main(void){
	int i;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		solve();
	}
	return 0;
}
