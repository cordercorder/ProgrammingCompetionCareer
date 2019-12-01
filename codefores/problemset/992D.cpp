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
const long long maxw=2*1e18;

typedef long long ll;
typedef pair<ll,ll> pii;
/*head------[@cordercorder]*/

const int maxn=2e5+10;

ll n,k;
ll a[maxn];
ll res[maxn],len2; 
ll sum[maxn];
ll cnt;
map<pii,bool> mp;
ll num[maxn];

void handle(){
	res[n+1]=n+1;
	res[n]=n;
	for(ll i=n-1;i>=1;i--){
		if(a[i]==1){
			res[i]=res[i+1];
		}
		else{
			res[i]=i;
		}
	}
}

void solve(){
	handle();
	ll ans=0;
	ll mul;
	ll l,r;
	ll pos;
	for(ll i=1;i<=n;i++){
		mul=1;
		ll j=i;
		while(j<=n&&mul<=maxw/a[j]){
			mul*=a[j];
			if(mul%k==0){
				pos=lower_bound(sum+1,sum+1+n,mul/k+sum[i-1])-sum;
				if(pos<=n&&pos>=j&&!mp[pii(i,pos)]&&(sum[pos]==(mul/k+sum[i-1]))&&num[pos]-num[j]==(pos-j)){
					//deb(i);
					//deb(pos);
					//deb(mul);
					//cout<<endl;
					mp[pii(i,pos)]=1;
					ans++;
				}
			}
			j=res[j+1];
		}
	}
	printf("%lld\n",ans);
}

int main(void){
	ll tmp;
	scanf("%lld %lld",&n,&k);
	sum[0]=0;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
		num[i]=num[i-1]+(a[i]==1);
	}
	solve();
	return 0;
}
