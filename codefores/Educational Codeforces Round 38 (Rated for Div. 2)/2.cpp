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

const int maxsize=1e5+10;
const int ss=1;
const int ee=1e6;

int n;
int a[maxsize];
int c1[maxsize],c2[maxsize];

int main(void){
	int i,ti,ans;
	while(scanf("%d",&n)!=EOF){
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			c1[i]=a[i]-ss;
			c2[i]=ee-a[i];
		}
		ti=0;
		ans=0;
		for(i=1;i<=n;i++){
			ti=min(c1[i],c2[i]);
			ans=max(ti,ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}
