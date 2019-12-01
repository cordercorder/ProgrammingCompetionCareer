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

const int maxn=1e4+10;
const int maxnn=1e6+10;

int a[maxn];
int t,n;
int phi[maxnn];
int prime[maxnn];
bool isv[maxnn];
int tot;
int T[maxnn<<2]; 

void create(int rt,int l,int r){
	if(l==r){
		T[rt]=phi[l];
		return ;
	}
	int mid=(l+r)>>1;
	create(rt<<1,l,mid);
	create(rt<<1|1,mid+1,r);
	T[rt]=max(T[rt<<1],T[rt<<1|1]);
}

void pre_handle(int x){
	phi[1]=1;
	tot=0;
	for(int i=2;i<=x;i++){
		if(!isv[i]){
			prime[tot++]=i;
			phi[i]=i-1;
		}
		for(int j=0;j<tot;j++){
			if(i*prime[j]>x)
				break;
			isv[i*prime[j]]=1;
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			else{
				phi[i*prime[j]]=phi[i]*(prime[j]-1);
			}
		}
	}
	phi[1]=0;
}

int query(int rt,int l,int r,int val){
	if(l==r){
		return l;
	}
	int mid=(l+r)>>1;
	if(T[rt<<1]>=val){
		return query(rt<<1,l,mid,val);
	}
	else{
		return query(rt<<1|1,mid+1,r,val);
	}
}

void solve(){
	ll ans=0,pos;
	create(1,1,1000003);
	for(int i=1;i<=n;i++){
		ans+=(ll)query(1,1,1000003,a[i]);
	}
	printf("%lld Xukha\n",ans);
}

int main(void){
	pre_handle(1000003);
	while(scanf("%d",&t)!=EOF){
		for(int ca=1;ca<=t;ca++){
			scanf("%d",&n);
			for(int i=1;i<=n;i++){
				scanf("%d",&a[i]);
			}
			printf("Case %d: ",ca);
			solve();
		}
	}
	return 0;
}
