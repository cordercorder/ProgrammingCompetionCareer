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

const ll mod=1000;

ll t,n,k;

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

void solve(){
	ll res1,res2=q_mod(n,k);
	double tmp=log10((double)n)*k;
	double tmp1=tmp-static_cast<ll>(tmp);
	//printf("%.6lf\n",tmp1);
	//printf("====%.6lf\n",pow(10,tmp1));
	res1=pow(10,tmp1)*100;
	printf("%03lld %03lld\n",res1,res2);
}

int main(void){
	scanf("%lld",&t);
	for(ll ca=1;ca<=t;ca++){
		scanf("%lld %lld",&n,&k);
		printf("Case %lld: ",ca);
		solve();
	}
	return 0;
}
