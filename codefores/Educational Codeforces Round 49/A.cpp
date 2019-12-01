#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<deque>
#include<limits.h>
#include<bitset>
#include<ctime>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

const long double PI=acos(-1.0); 
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const ll mod=998244353;
const ll maxn=1e5+10; 

ll t,n,m;
ll a[maxn];
ll L,R;
ll ret;
ll sum[maxn];

ll q_mod(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1){
			ans=ans*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}

ll lowbit(ll x){
	return x&(-x);
}

void handle(bool f){
	ll ans=sum[R]-sum[L-1]+mod;
	ans=ans%mod;
	ans=ans*ret%mod;
	printf("%lld\n",ans);
}

int main(void){
	ll tmp;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld",&n,&m);
		ret=q_mod((ll)2,(m*n));
		sum[0]=0;
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			sum[i]=(sum[i-1]+a[i])%mod;
		}
		while(m--){
			scanf("%lld %lld %lld",&tmp,&L,&R);
			if(tmp==1){
				//handle(1); 
			}
			else{
				handle(0);
			}
		}
	}
	return 0;
}
