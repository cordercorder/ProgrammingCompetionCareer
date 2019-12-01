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

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=2e5+10;

ll a[maxn];
ll n;
ll sum[maxn],sum2[maxn];
ll res;
map<ll,ll> mp;
map<ll,ll>::iterator it;

void solve(){
	sum[n+1]=0;
	for(ll i=n;i>=1;i--){
		sum2[i]=sum2[i+1]+a[i];
		mp[sum2[i]]++;
	}
	ll ans=0;
	ll pos1,pos2;
	for(it=mp.begin();it!=mp.end();it++){
		if(it->second==2){
			pos1=lower_bound(sum+1,sum+1+n,it->first)-sum;
			pos2=lower_bound(sum2+1,sum2+1+n,it->first,greater<ll>())-sum2;
		//	deb(pos1);
		//	deb(pos2);
			if(pos1<pos2)
				ans=max(ans,it->first);	
		}
	}
	printf("%lld\n",ans);
	mp.clear();
}

int main(void){
	while(scanf("%lld",&n)!=EOF){
		sum[0]=0;
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			sum[i]=sum[i-1]+a[i];
			mp[sum[i]]++;
		}
		solve();
	}
	return 0;
}
