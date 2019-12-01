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

const int maxn=1e5+10;

ll a,b,h,w,n;
ll res[maxn];
ll ans;

bool check(ll hh,ll ww){
	if(min(hh,ww)>=a&&max(hh,ww)>=b)
		return 1;
	return 0;
}

void handle(ll pos,ll hh,ll ww,ll sum){
	if(check(hh,ww)){
		ans=min(ans,sum);
		return ;
	}
	if(pos>n)
		return ;
	if(res[pos]==2){
		ll tmp;
		if(hh<a){
			tmp=hh*res[pos];
			handle(pos+1,min(ww,tmp),max(ww,tmp),sum+1);
			return ;
		}
		tmp=ww*res[pos];
		handle(pos+1,min(tmp,hh),max(tmp,hh),sum+1);
		return ;
	}
	if(hh<a){
		ll tmp=hh*res[pos];
		handle(pos+1,min(tmp,ww),max(tmp,ww),sum+1);
	}
	if(ww<b){
		ll tmp=ww*res[pos];
		handle(pos+1,min(tmp,hh),max(tmp,hh),sum+1);
	}
}

void solve(){
	sort(res+1,res+1+n,greater<ll>());
	ans=maxw;
	handle(1,min(h,w),max(h,w),0);
	if(ans==maxw){
		puts("-1");
		return ;
	}
	printf("%lld\n",ans);	
}

int main(void){
	scanf("%lld %lld %lld %lld %lld",&a,&b,&h,&w,&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&res[i]);
	}
	if(a>b){
		swap(a,b);
	}
	if(check(h,w)){
		puts("0");
		return 0;
	}
	solve();
	return 0;
}
