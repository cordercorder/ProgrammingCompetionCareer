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

const int maxsize=1e3+10;
const int maxn=1e5+10;

struct node{
	int x;
	int y;
	int t;
};

node a[maxn];
int pre[maxsize];
int n,m;

int Find(int x){
	return pre[x]==-1?x:pre[x]=Find(pre[x]);
}

bool cmp(const node &a,const node &b){
	return a.t<b.t;
}

void Union(int x,int y){
	int nx=Find(x),ny=Find(y);
	if(nx!=ny){
		pre[nx]=ny;
	}
}

bool check(){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(pre[i]==-1)
			sum++;
		if(sum>1)
			return 0;
	}
	return 1;
}

void solve(){
	sort(a,a+m,cmp);
	for(int i=0;i<m;i++){
		Union(a[i].x,a[i].y);
		if(check()){
			printf("%d\n",a[i].t);
			return ;
		}
	}
	printf("-1\n");
}

int main(void){
	while(scanf("%d %d",&n,&m)!=EOF){
		memset(pre,-1,sizeof(pre));
		for(int i=0;i<m;i++){
			scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].t);
		}
		solve();
	}
	return 0;
}
