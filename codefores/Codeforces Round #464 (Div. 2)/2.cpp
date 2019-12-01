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

ll n,k;
ll a[maxsize];

int main(void){
	ll i,Min,x;
	while(scanf("%lld %lld",&n,&k)!=EOF){
		Min=1e18+10;
		x=1;
		for(i=1;i<=k;i++){
			scanf("%lld",&a[i]);
			if(n>=a[i]&&(n%a[i])<Min){
				Min=n%a[i];
				x=i;
			}
		}
		printf("%lld %lld\n",x,n/a[x]);
	}
	return 0;
}
