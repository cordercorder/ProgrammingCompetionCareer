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

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

const int maxsize=2e4;

struct node{
	int x;
	int y;
	int len;
};

bool cmp(const node &a,const node &b){
	return a.len<b.len;
}

node a[maxsize];
int n,m;
vector<node> p;
int pre[maxsize];

int Find(int x){
	return pre[x]==-1?x:pre[x]=Find(pre[x]);
}

bool Union(int x,int y){
	int nx=Find(x),ny=Find(y);
	if(nx==ny)
		return 0;
	pre[nx]=ny;
	return 1; 
}

void solve(){
	memset(pre,-1,sizeof(pre));
	int Max=INT_MIN;
	for(int i=1;i<=m;i++){
		if(Union(a[i].x,a[i].y)){
			Max=max(a[i].len,Max);
			p.push_back(a[i]);
		}
	}
	printf("%d\n%d\n",Max,p.size());
	for(int i=0;i<p.size();i++){
		printf("%d %d\n",p[i].x,p[i].y);
	}
}

int main(void){
	
	while(scanf("%d %d",&n,&m)!=EOF){
		for(int i=1;i<=m;i++){
			scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].len);
		}
		sort(a+1,a+1+m,cmp);
		solve();
		p.clear();
	}
	return 0;
}
