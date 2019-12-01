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

const int maxsize=1e5+10;
const int mod=998244353;

int T;
int n,m;
ll add[2][maxsize];

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
	ll x1,x2;
	ll a,b,ans;
	while(scanf("%d",&T)!=EOF){
		while(T--){
			memset(add,0,sizeof(add));
			scanf("%d %d",&n,&m);
			while(m--){
				scanf("%d %d %d",&l,&r,&x);
				add[x-2][l]++;
				add[x-2][r+1]--;
			}
			x1=0,x2=0;
			a=add[0][1];
			b=add[1][1];
			for(int i=1;i<=n;i++){
				x1+=add[0][i];
				x2+=add[1][i];
				a=min(a,x1);
				b=min(b,x2);
			}
			//cout<<"a=="<<a<<"  b=="<<b<<endl;
			ans=q_mod((ll)2,a);
			ans=ans*q_mod((ll)3,b)%mod;
			printf("%lld\n",ans);
		}
	}
	
	return 0;
}
