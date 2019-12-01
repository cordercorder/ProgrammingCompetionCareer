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

const int maxn=1e5+10;
const int mod=998244353;

int t;
int n,m;
int add[2][maxn];
ll ans1,ans2,res1,res2;
ll x;

ll q_mod(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1){
			ans=ans*a%mod;
		}
		b=b>>1;
		a=a*a%mod;
	}
	return ans;
}

int main(void){
	int l,r,x;
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d %d",&n,&m);
			memset(add,0,sizeof(add)); 
			while(m--){
				scanf("%d %d %d",&l,&r,&x);
				add[x-2][l]++;
				add[x-2][r+1]--;
			}
			res1=add[0][1];
			res2=add[1][1];
			ans1=res1;
			ans2=res2;
			for(int i=2;i<=n;i++){
				res1+=add[0][i];
				res2+=add[1][i];
				ans1=min(res1,ans1);
				ans2=min(res2,ans2);
			}
			x=q_mod((ll)2,ans1)*q_mod((ll)3,ans2)%mod;
			printf("%lld\n",x);
		}
	}
	return 0;
}
