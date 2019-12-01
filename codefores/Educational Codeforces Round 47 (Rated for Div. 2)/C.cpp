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
typedef pair<ll,ll> pii;

const int maxn=1e5+10;

ll a[maxn];
ll n,m;
vector<pii> res[2];

void solve(){
	ll sum=0,x_sum=0;
	for(ll i=0;i<(ll)res[0].size();i++){
		sum+=res[0][i].second;
		x_sum+=res[0][i].first;
	}
	for(ll i=1;i<=n;i++){
		a[i]+=((i-1)*sum+x_sum);
	//	deb(a[i]); 
	}
	sum=0;
	x_sum=0;
	for(ll i=0;i<(ll)res[1].size();i++){
		sum+=res[1][i].second;
		x_sum+=res[1][i].first;
	}
	long double ans=0;
	ll tmp=(n+1)/2;
	for(ll i=1;i<=n;i++){
		a[i]+=(abs(i-tmp)*sum+x_sum);
	//	deb(a[i]);
		ans+=(long double)a[i];
	}
	printf("%.20Lf\n",(long double)ans/n);
}

int main(void){
	ll x,d;
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=m;i++){
		scanf("%lld %lld",&x,&d);
		if(d>=0){
			res[0].push_back(pii(x,d));
		}
		else{
			res[1].push_back(pii(x,d));
		}
	}
	solve();
	return 0;
}
