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

const ll maxn=5e4+10;

ll n;
ll a[maxn]; 

void solve(){
	ll ans=0,Min=maxw;
	for(ll i=1;i<=n;i++){
		ans+=a[i];
		Min=min(Min,ans);
	}
	printf("%lld\n",-Min);
}

int main(void){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	solve();
	return 0;
}
