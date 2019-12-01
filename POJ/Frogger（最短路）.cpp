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

const int maxsize=2e2+10;
const int maxw=1e8+10;

struct node{
	double x;
	double y;
};

node a[maxsize];
int n;
double adj[maxsize][maxsize];
bool isv[maxsize];
double D[maxsize];

double dis(const node &a,const node &b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void handle(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			adj[i][j]=maxw;
	}
	double tmp;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			tmp=dis(a[i],a[j]);
			adj[i][j]=tmp;
			adj[j][i]=tmp;
		}
	}
}

void solve(int f,int ee){
	double Min;
	double Max;
	int x;
	for(int i=1;i<=n;i++){
		D[i]=adj[f][i];
		isv[i]=0;
	}
	isv[f]=1;
	D[f]=0;
	for(int i=1;i<n;i++){
		Min=maxw;
		x=-1;
		for(int j=1;j<=n;j++){
			if(!isv[j]&&D[j]<Min){
				Min=D[j];
				x=j;
			}		
		}
		if(x!=-1){
			isv[x]=1;
			for(int j=1;j<=n;j++){
				if(!isv[j]){
					Max=max(D[x],adj[x][j]);
					if(Max<D[j])
						D[j]=Max;
				}
			}
		}
	}
}

int main(void){
	double x,y;
	int sum=0;
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		for(int i=1;i<=n;i++){
			scanf("%lf %lf",&x,&y);
			a[i].x=x;
			a[i].y=y;
		}
		handle();
		solve(1,2);
		sum++;
		printf("Scenario #%d\n",sum);
		printf("Frog Distance = %.3lf\n\n",D[2]);
	}
	return 0;
}
