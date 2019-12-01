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
ll n,m;
ll t;
ll T[maxn<<2],add[maxn<<2];

void create(ll rt,ll l,ll r){
	if(l==r){
		T[rt]=a[l];
		return ;
	}
	ll mid=(l+r)>>1;
	create(rt<<1,l,mid);
	create(rt<<1|1,mid+1,r);
	T[rt]=T[rt<<1]+T[rt<<1|1];
}

void pushdown(ll rt,ll l,ll r){
	if(add[rt]){
		ll mid=(l+r)>>1;
		T[rt<<1]+=(mid-l+1)*add[rt];
		T[rt<<1|1]+=(r-mid)*add[rt];
		add[rt<<1]+=add[rt];
		add[rt<<1|1]+=add[rt];
		add[rt]=0;
	}
}

void update(ll rt,ll l,ll r,ll L,ll R,ll x){
	if(l==L&&R==r){
		T[rt]+=(r-l+1)*x;
		add[rt]+=x;
		return ;
	}
	pushdown(rt,l,r);
	ll mid=(l+r)>>1;
	if(R<=mid){
		update(rt<<1,l,mid,L,R,x);
	}
	else if(L>mid){
		update(rt<<1|1,mid+1,r,L,R,x);
	}
	else{
		update(rt<<1,l,mid,L,mid,x);
		update(rt<<1|1,mid+1,r,mid+1,R,x);
	}
	T[rt]=T[rt<<1]+T[rt<<1|1];
}

void update1(ll rt,ll l,ll r,ll L,ll R){
	if(T[rt]==(r-l+1))
		return ;
	if(l==r){
		T[rt]=(ll)sqrt(T[rt]);
		return ;
	}
	pushdown(rt,l,r);
	ll mid=(l+r)>>1;
	if(R<=mid){
		update1(rt<<1,l,mid,L,R);
	}
	else if(L>mid){
		update1(rt<<1|1,mid+1,r,L,R);
	}
	else{
		update1(rt<<1,l,mid,L,mid);
		update1(rt<<1|1,mid+1,r,mid+1,R);
	}
	T[rt]=T[rt<<1]+T[rt<<1|1];
}

ll query(ll rt,ll l,ll r,ll L,ll R){
	if(l==L&&R==r){
		return T[rt];
	}
	pushdown(rt,l,r);
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

void print(ll rt,ll l,ll r){
	if(l==r){
		printf("%lld",T[rt]);
		return ;
	}
	pushdown(rt,l,r);
	ll mid=(l+r)>>1;
	print(rt<<1,l,mid);
	print(rt<<1|1,mid+1,r);
}

int main(void){
	ll tmp,l,r,x;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld",&n,&m);
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		create(1,1,n); 
		while(m--){
			scanf("%lld",&tmp);
			if(tmp==1){
				scanf("%lld %lld %lld",&l,&r,&x);
				update(1,1,n,l,r,x);
			}
			else if(tmp==2){
				scanf("%lld %lld",&l,&r);
				update1(1,1,n,l,r);
			}
			else{
				scanf("%lld %lld",&l,&r);
				printf("%lld\n",query(1,1,n,l,r));
			}
			//print(1,1,n);
			//puts("");
		}
	}
	return 0;
}
