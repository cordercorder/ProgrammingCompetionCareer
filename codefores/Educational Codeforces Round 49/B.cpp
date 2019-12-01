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

ll n,q;
ll x,y;
ll ret;

void solve(){
	ll ans;
	if((x+y)&(ll)1){
		if(n&(ll)1){
			if(x&(ll)1){
				ans=(x-(ll)1)/(ll)2*n+(y+(ll)1)/(ll)2+ret-(ll)1;
			}
			else{
				ans=x/(ll)2*n-n/(ll)2+(y+(ll)1)/(ll)2+ret-(ll)1-(ll)1;
			}
		}
		else{
			ans=(x-(ll)1)/(ll)2*n+(x-(ll)1)%(ll)2*n/(ll)2+(y+(ll)1)/(ll)2+ret-(ll)1;
		}
	}
	else{
		if(n&(ll)1){
			if(x&(ll)1){
				ans=(x-(ll)1)/(ll)2*n+(y+(ll)1)/(ll)2;
			}
			else{
				ans=x/(ll)2*n-n/(ll)2+(y+(ll)1)/(ll)2;
			}
		}
		else{
			ans=(x-(ll)1)/(ll)2*n+(x-(ll)1)%(ll)2*n/(ll)2+(y+(ll)1)/(ll)2;
		}
	}
	printf("%lld\n",ans);
}

int main(void){
	scanf("%lld %lld",&n,&q);
	ret=(n*n)/(ll)2+(ll)1;
	if(n&(ll)1){
		++ret;
	}
	while(q--){
		scanf("%lld %lld",&x,&y);
		solve();
	}
	return 0;
}
