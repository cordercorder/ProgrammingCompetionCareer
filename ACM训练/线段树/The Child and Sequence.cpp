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

const ll maxn=1e5+10;

ll a[maxn];
ll T[2][maxn<<2];
ll n,m;

void create(ll rt,ll l,ll r){
	if(l==r){
		T[0][rt]=a[l];
		T[1][rt]=a[l];
		return ;
	}
	ll mid=(l+r)>>1;
	create(rt<<1,l,mid);
	create(rt<<1|1,mid+1,r);
	T[0][rt]=T[0][rt<<1]+T[0][rt<<1|1];
	T[1][rt]=max(T[1][rt<<1],T[1][rt<<1|1]);
}

void update(ll rt,ll l,ll r,ll L,ll R,ll mod){
	if(T[1][rt]<mod){
		return ;
	}
	if(l==r){
		T[0][rt]=T[0][rt]%mod;
		T[1][rt]=T[1][rt]%mod;
		return ;
	}
	ll mid=(l+r)>>1;
	if(R<=mid){
		update(rt<<1,l,mid,L,R,mod);
	}
	else if(L>mid){
		update(rt<<1|1,mid+1,r,L,R,mod);
	}
	else{
		update(rt<<1,l,mid,L,mid,mod);
		update(rt<<1|1,mid+1,r,mid+1,R,mod);
	}
	T[0][rt]=T[0][rt<<1]+T[0][rt<<1|1];
	T[1][rt]=max(T[1][rt<<1],T[1][rt<<1|1]);
}

void update1(ll rt,ll l,ll r,ll pos,ll val){
	if(l==r){
		T[0][rt]=val;
		T[1][rt]=val;
		return ;
	}
	ll mid=(l+r)>>1;
	if(pos<=mid){
		update1(rt<<1,l,mid,pos,val);
	}
	else{
		update1(rt<<1|1,mid+1,r,pos,val);
	}
	T[0][rt]=T[0][rt<<1]+T[0][rt<<1|1];
	T[1][rt]=max(T[1][rt<<1],T[1][rt<<1|1]);
}

ll query(ll rt,ll l,ll r,ll L,ll R){
	if(l==L&&R==r){
		return T[0][rt];
	}
	ll mid=(l+r)>>1;
	if(R<=mid){
		return query(rt<<1,l,mid,L,R);
	}
	else if(L>mid){
		return query(rt<<1|1,mid+1,r,L,R);
	}
	else{
		return query(rt<<1,l,mid,L,mid)+query(rt<<1|1,mid+1,r,mid+1,R);
	}
}

int main(void){
	ll tmp,l,r,x,k;
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	create(1,1,n);
	while(m--){
		scanf("%lld",&tmp);
		if(tmp==1){
			scanf("%lld %lld",&l,&r);
			printf("%lld\n",query(1,1,n,l,r));
		}
		else if(tmp==2){
			scanf("%lld %lld %lld",&l,&r,&x);
			update(1,1,n,l,r,x);
		}
		else{
			scanf("%lld %lld",&k,&x);
			update1(1,1,n,k,x);
		}
	}
	return 0;
}
