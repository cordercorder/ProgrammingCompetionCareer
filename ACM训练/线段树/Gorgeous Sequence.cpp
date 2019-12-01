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
ll n,m;
ll T[maxn<<2],Max[maxn<<2],Max_s[maxn<<2],num[maxn<<2];
ll a[maxn];

void push_up(ll rt){
	T[rt]=T[rt<<1]+T[rt<<1|1];
	Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
	num[rt]=0;
	Max_s[rt]=max(Max_s[rt<<1],Max_s[rt<<1|1]);
	if(Max[rt<<1]!=Max[rt<<1|1]){
		Max_s[rt]=max(Max_s[rt],min(Max[rt<<1],Max[rt<<1|1]));
	}
	if(Max[rt]==Max[rt<<1]){
		num[rt]+=num[rt<<1];
	}
	if(Max[rt]==Max[rt<<1|1]){
		num[rt]+=num[rt<<1|1];
	}
}

void create(ll rt,ll l,ll r){
	if(l==r){
		T[rt]=a[l];
		Max[rt]=a[l];
		num[rt]=1;
		Max_s[rt]=-1;
		return ;
	}
	ll mid=(l+r)>>1;
	create(rt<<1,l,mid);
	create(rt<<1|1,mid+1,r);
	push_up(rt);
}

void pushdown(ll rt){
	if(Max[rt]<Max[rt<<1]){
		T[rt<<1]+=(Max[rt]-Max[rt<<1])*num[rt<<1];
		Max[rt<<1]=Max[rt];
	}
	if(Max[rt]<Max[rt<<1|1]){
		T[rt<<1|1]+=(Max[rt]-Max[rt<<1|1])*num[rt<<1|1];
		Max[rt<<1|1]=Max[rt];
	}
}

void update(ll rt,ll l,ll r,ll L,ll R,ll val){
	if(Max[rt]<=val)
		return ;
	if(l==L&&R==r&&val>Max_s[rt]){
		T[rt]+=(num[rt]*(val-Max[rt]));
		Max[rt]=val;
		return ;
	}
	pushdown(rt);
	ll mid=(l+r)>>1;
	if(R<=mid){
		update(rt<<1,l,mid,L,R,val);
	}
	else if(L>mid){
		update(rt<<1|1,mid+1,r,L,R,val);
	}
	else{
		update(rt<<1,l,mid,L,mid,val);
		update(rt<<1|1,mid+1,r,mid+1,R,val);
	}
	push_up(rt);
}

ll query(ll rt,ll l,ll r,ll L,ll R,bool f){
	if(l==L&&R==r){
		if(f)
			return Max[rt];
		return T[rt];
	}
	pushdown(rt);
	ll mid=(l+r)>>1;
	if(R<=mid){
		return query(rt<<1,l,mid,L,R,f);
	}
	else if(L>mid){
		return query(rt<<1|1,mid+1,r,L,R,f);
	}
	else{
		if(f){
			return max(query(rt<<1,l,mid,L,mid,f),query(rt<<1|1,mid+1,r,mid+1,R,f));
		}
		return query(rt<<1,l,mid,L,mid,f)+query(rt<<1|1,mid+1,r,mid+1,R,f);
	}
}

int main(void){
	ll tmp,x,y,ret;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld",&n,&m);
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		create(1,1,n);
		while(m--){
			scanf("%lld",&tmp);
			if(tmp==0){
				scanf("%lld %lld %lld",&x,&y,&ret);
				update(1,1,n,x,y,ret);
			}
			else if(tmp==1){
				scanf("%lld %lld",&x,&y);
				printf("%lld\n",query(1,1,n,x,y,1));
			}
			else{
				scanf("%lld %lld",&x,&y);
				printf("%lld\n",query(1,1,n,x,y,0));
			}	
		}
	}
	return 0;
}
