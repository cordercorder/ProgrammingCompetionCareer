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

const int maxn=1e6;
const int maxsize=1e6+10;

vector<ll> pre;
bool flag[maxsize];
ll l,r,ans;

int main(void){
	memset(flag,0,sizeof(flag));
	for(ll i=2;i<=maxn;i++){
		if(!flag[i]){
			pre.push_back(i);
			for(ll j=i*i;j<=maxn;j+=i)
				flag[j]=1;
		}
	}
	while(scanf("%lld %lld",&l,&r)!=EOF){
		ans=0;
		for(ll i=0;i<pre.size()&&l*pre[i]<=r;i++){
			ans+=r/pre[i]-l+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
