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

const ll maxn=100000+10;
ll prime[maxn];//保存素数 
bool vis[maxn];//初始化 
ll cnt;

ll a,p;

void Prime(ll x){
	cnt=0;
	memset(vis,0,sizeof(vis));
	for(ll i=2;i<x;i++){
		if(!vis[i])
			prime[cnt++]=i;
		for(ll j=0;j<cnt&&i*prime[j]<x;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)//关键 
				break;
		}
	}//返回小于n的素数的个数 
}

ll q_mod(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1){
			ans=ans*a%p;
		}
		a=a*a%p;
		b>>=1;
	}
	return ans;
}

bool check(ll x){
	ll ans=1,tmp=0;
	for(ll i=0;i<cnt&&prime[i]<=x;i++){
		tmp=0;
		while(x%prime[i]==0){
			x/=prime[i];
			tmp++;
		}
		ans=ans*(tmp+1);
		if(x==1)
			break;
	}
	if(x!=1){
		ans=ans*2;
	}
	if(ans!=2)
		return 1;
	return 0;
}

int main(void){
	Prime((ll)100000);	
	while(scanf("%lld %lld",&p,&a)!=EOF){
		if(p==0&&a==0)
			break;
		if(check(p)&&q_mod(a,p)==a){
			puts("yes");
		}
		else{
			puts("no");
		}
	}
	return 0;
}
