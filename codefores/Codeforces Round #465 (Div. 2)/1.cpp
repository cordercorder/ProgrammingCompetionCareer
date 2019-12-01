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

ll n,ans;

int main(void){
	ll i,j;
	while(scanf("%lld",&n)!=EOF){
		ans=0;
		for(i=1;i<=n;i++){
			for(j=1;i+i*j<=n;j++){
				if(i+i*j==n)
					ans++;
			}
		}
		printf("%lld\n",ans);	
	}
	return 0;
}
