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

const int maxsize=15e4+10;

ll n;
ll a[maxsize];
map<ll,ll> mp;
ll ans;

int main(void){
	while(scanf("%lld",&n)!=EOF){
		ans=0;
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			while(mp[a[i]]){
				a[mp[a[i]]]=0;
				mp[a[i]]=0;
				a[i]+=a[i];
				ans++;
			}
			mp[a[i]]=i;
		}
		printf("%lld\n",n-ans);
		for(ll i=1;i<=n;i++){
			if(a[i]){
				printf("%lld ",a[i]);
			}
		}
		printf("\n");
		mp.clear();
	}
	return 0;
}
