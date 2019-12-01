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

const int maxsize=30;

int adj[maxsize][maxsize];
int num[maxsize];
int n;
int ans;

void solve(int x,int sum){
	ans=max(ans,sum);
	if(x>n)
		return ;
	int res=sum;
	num[x]=1;
	for(int i=1;i<=n;i++){
		if(num[i]==0)
			res+=adj[x][i];
		else
			res-=adj[x][i];
	}
	//cout<<"res=="<<res<<endl;	
	solve(x+1,res);
	num[x]=0;
	solve(x+1,sum);
}

int main(void){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				scanf("%d",&adj[i][j]);
		}
		memset(num,0,sizeof(num));
		ans=0;
		solve(1,0);
		printf("%d\n",ans);
	}
	return 0;
}
