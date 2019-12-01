# include<iostream>
# include<algorithm>
# include<cstring>
# include<cstdlib>
# include<string>
# include<cmath>
# include<queue>
# include<stack>
# include<set>
# include<vector>
# include<cstdio>

# define ll long long 

using namespace std;

const int maxsize=5e2+10;

int a[maxsize][maxsize]; 

int N,Q;

int main(void){
	int i,j,x,y,ans;
	while(scanf("%d %d",&N,&Q)!=EOF){
		for(i=1;i<=N;i++){
			for(j=1;j<=N;j++)
				scanf("%d",&a[i][j]);
		}
		while(Q--){
			scanf("%d %d",&x,&y);
			if(a[x][y]==-1&&a[y][x]==-1){
				printf("jujue\n");
				continue;
			}
			else if(a[x][y]!=-1&&a[y][x]==-1){
				ans=a[x][y];
			}
			else if(a[y][x]==-1&&a[x][y]==-1){
				ans=a[y][x];
			}
			else{
				ans=min(a[x][y],a[y][x]);
			}
			printf("%d\n",ans);
		}
		
	}
	return 0;
}
