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

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e5+10;

ll T[maxn<<2];
ll add[maxn<<2];
bool isv[maxn<<2];
ll A[maxn];
ll n,q;

void create(ll rt,ll l,ll r){
	if(l==r){
		T[rt]=A[l];
		return ;
	}
	ll mid=(l+r)>>1;
	create(rt<<1,l,mid);
	create(rt<<1|1,mid+1,r);
	T[rt]=T[rt<<1]+T[rt<<1|1];
}

void pushdown(ll rt,ll l,ll r){
	if(isv[rt]){
		ll mid=(l+r)>>1; 
		T[rt<<1]+=(mid-l+1)*add[rt];
		T[rt<<1|1]+=(r-mid)*add[rt];
		add[rt<<1]+=add[rt];
		add[rt<<1|1]+=add[rt];
		isv[rt<<1]=1;
		isv[rt<<1|1]=1;
		add[rt]=0;
		isv[rt]=0;
	}
}

void update(ll rt,ll l,ll r,ll L,ll R,ll val){
	if(l==L&&R==r){
		T[rt]+=val*(r-l+1);
		add[rt]+=val;
		isv[rt]=1;
		return ;
	}
	pushdown(rt,l,r);
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

int main(void){
	char s[20];
	ll a,b,c;
	while(scanf("%lld %lld",&n,&q)!=EOF){
		for(ll i=1;i<=n;i++){
			scanf("%lld",&A[i]);
		}
		create(1,1,n);
		while(q--){
			scanf("%s",s);
			if(s[0]=='Q'){
				scanf("%lld %lld",&a,&b);
				printf("%lld\n",query(1,1,n,a,b));
			}
			else{
				scanf("%lld %lld %lld",&a,&b,&c);
				update(1,1,n,a,b,c);
			}
		}
	}
	return 0;
}
