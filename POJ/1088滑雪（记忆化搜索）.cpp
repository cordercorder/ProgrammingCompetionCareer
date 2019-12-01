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

int r,c;
int a[maxsize][maxsize];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int dp[maxsize][maxsize];

int solve(int x,int y){
	if(dp[x][y]>=0)
		return dp[x][y];
	int i;
	int nx,ny,res=0;
	for(i=0;i<4;i++){
		nx=x+dx[i];
		ny=y+dy[i];
		if(nx>=0&&nx<r&&ny>=0&&ny<c&&a[x][y]>a[nx][ny]){
			res=max(res,solve(nx,ny)+1);
		}
	}
	return dp[x][y]=res;
}

int main(void){
	int i,j,ans;
	while(scanf("%d %d",&r,&c)!=EOF){
		for(i=0;i<r;i++){
			for(j=0;j<c;j++)
				scanf("%d",&a[i][j]);
		}
		ans=0;
		memset(dp,-1,sizeof(dp));
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				ans=max(ans,solve(i,j));
			}
		} 
		printf("%d\n",ans+1);
	}
	return 0;
}
