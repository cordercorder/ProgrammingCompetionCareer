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

const int maxsize=1e3+10;

struct point{
	double x;
	double y;
}a[maxsize];

struct node{
	double l;
	double r;
}p[maxsize];

int n,d;
int cnt;

bool cmp(const node &a,const node &b){
	return a.l<b.l;
}

template<typename T>
T Min(T a,T b){
	if(a<b)
		return a;
	return b;
}

void solve(){
	double tmp;
	for(int i=0;i<n;i++){
		tmp=sqrt(d*d-a[i].y*a[i].y);
		p[i].l=a[i].x-tmp;
		p[i].r=a[i].x+tmp;
	}
	cnt=1;
	sort(p,p+n,cmp);
	double r=p[0].r;
	for(int i=1;i<n;i++){
		r=Min(r,p[i].r);
		if(r<p[i].l){
			cnt++;
			r=p[i].r;
		}
	}
}

int main(void){
	bool flag;
	int sum=0;
	while(scanf("%d %d",&n,&d)){
		if(n==0&&d==0)
			break;
		flag=0;
		sum++;
		for(int i=0;i<n;i++){
			scanf("%lf %lf",&a[i].x,&a[i].y);
			if(a[i].y>d)
				flag=1;
		}
		printf("Case %d: ",sum);
		if(flag){
			printf("-1\n");
			continue;
		}
		solve();
		printf("%d\n",cnt);
	}
	return 0;
}
