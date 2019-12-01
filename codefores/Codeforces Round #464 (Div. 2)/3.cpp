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

ll n,s,f;
ll a[2*maxsize];
ll b[2*maxsize];

int main(void){
	ll i,ans,Max;
	while(scanf("%lld",&n)!=EOF){
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			a[i+n]=a[i];
		}
		scanf("%lld %lld",&s,&f);
		b[0]=0;
		for(i=1;i<=2*n;i++){
			b[i]=b[i-1]+a[i];
		}
		ll tmp=f-s;
		ll xx;
		Max=0;
		for(i=tmp;i<=n+tmp;i++){
			xx=b[i]-b[i-tmp];
			if(xx>Max){
				Max=xx;
				ans=i-tmp+1;
			}
		}
		ll ti=s;
		for(i=ans;i>1;i--){
			if(ti==1)
				ti=n;
			else
				ti--;
		}
		printf("%lld\n",ti);
	}
	return 0;
}

