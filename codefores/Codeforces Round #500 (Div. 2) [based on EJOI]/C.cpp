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

ll a[maxn+maxn];
ll n;

void solve(){
	sort(a+1,a+1+n+n);
	ll ans=(a[n]-a[1])*(a[2*n]-a[n+1]);//  (x_max-x_min)*(y_max-y_min)
	for(ll i=2;i<=n;i++){
		ans=min(ans,(a[2*n]-a[1])*(a[i+n-1]-a[i]));
	}
	printf("%lld\n",ans);
}

int main(void){
	scanf("%lld",&n);
	for(ll i=1;i<=2*n;i++){
		scanf("%lld",&a[i]);
	}
	solve();
	return 0;
}
