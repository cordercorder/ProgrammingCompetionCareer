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

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)

typedef long long ll;

using namespace std;

const int maxsize=1e2+10;

int a[maxsize],sum;
int n;
int dp[maxsize][22505];

int solve(int num,int v,int tol){//vÎª±³°üÈÝÁ¿ 
	if(num>=n){
		return 0;
	}
	if(dp[num][v]>=0)
		return dp[num][v];
	int res;
	if(v>=a[num]&&tol>0){
		res=max(solve(num+1,v-a[num],tol-1)+a[num],solve(num+1,v,tol));
	}
	else{
		res=solve(num+1,v,tol);
	}
	return dp[num][v]=res;
} 

int main(void){
	int i,tmp1=0,tmp2=0; 
	while(scanf("%d",&n)!=EOF){
		sum=0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		memset(dp,-1,sizeof(dp));
		tmp1=solve(0,sum/2,(n+1)/2);
		tmp2=sum-tmp1;
		printf("%d %d\n",min(tmp1,tmp2),max(tmp1,tmp2));
	}
	return 0;
}
