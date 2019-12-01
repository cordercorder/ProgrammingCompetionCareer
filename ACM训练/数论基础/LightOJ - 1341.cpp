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

const ll maxn=1e6+10;

ll t;
ll a,b;

ll prime[maxn];
bool isv[maxn];
ll cnt;

void pre_handle(ll x){
	cnt=0;
	memset(isv,0,sizeof(isv));
	for(ll i=2;i<x;i++){
		if(!isv[i]){
			prime[cnt++]=i;
		}
		for(ll j=0;j<cnt&&i*prime[j]<x;j++){
			isv[i*prime[j]]=1;
			if(i%prime[j]==0)
				break;
		}
	}
}

void solve(){
	ll x=a,sum,ans=1;
	for(ll i=0;i<cnt&&prime[i]*prime[i]<=x;i++){
		sum=0;
		while(x%prime[i]==0){
			x/=prime[i];
			sum++;
		}
		ans*=(sum+1); 
		if(x==1)
			break;
	}
	if(x!=1){
		ans*=(ll)2;
	}
	ans/=2;
	for(ll i=1;i<b;i++){
		if(a%i==0){
			ans--;
		}
	}
	printf("%lld\n",ans);
}

int main(void){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	//clock_t st=clock();
	pre_handle((ll)(1000000+1));
	scanf("%lld",&t);
	for(ll ca=1;ca<=t;ca++){
		scanf("%lld %lld",&a,&b);
		if(a<=b*b){
			printf("Case %lld: 0\n",ca);
			continue;
		}
		printf("Case %lld: ",ca);
		solve();
	}
	//clock_t ed=clock();
	//cout<<"running time is "<<(double)(ed-st)<<"ms"<<endl;
	return 0;
}
