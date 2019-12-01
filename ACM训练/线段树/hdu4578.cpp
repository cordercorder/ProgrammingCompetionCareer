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
const int MOD=10007;

ll n,m;
ll add[maxn<<2],p1[maxn<<2],p2[maxn<<2],p3[maxn<<2],change[maxn<<2],mul[maxn<<2];

void pushdown(ll rt,ll l,ll r){
	ll mid=(l+r)>>1;
	if(change[rt]){//把一个区间的数变为一个数 
		p1[rt<<1]=change[rt]*(mid-l+1)%MOD;
		p1[rt<<1|1]=change[rt]*(r-mid)%MOD;
		p2[rt<<1]=change[rt]*change[rt]*(mid-l+1)%MOD;
		p2[rt<<1|1]=change[rt]*change[rt]*(r-mid)%MOD;
		p3[rt<<1]=change[rt]*change[rt]*change[rt]*(mid-l+1)%MOD;
		p3[rt<<1|1]=change[rt]*change[rt]*change[rt]*(r-mid)%MOD;
		change[rt<<1]=change[rt];
		change[rt<<1|1]=change[rt];
		change[rt]=0;
		add[rt<<1]=0;
		add[rt<<1|1]=0;
		mul[rt<<1]=1;
		mul[rt<<1|1]=1;
	}
	if(mul[rt]!=1){//将一个区间同时乘上一个数 
		p1[rt<<1]=(p1[rt<<1]*mul[rt])%MOD;
		p1[rt<<1|1]=(p1[rt<<1|1]*mul[rt])%MOD;
		p2[rt<<1]=(p2[rt<<1]*mul[rt]*mul[rt]%MOD)%MOD;
		p2[rt<<1|1]=(p2[rt<<1|1]*mul[rt]*mul[rt]%MOD)%MOD;
		p3[rt<<1]=(p3[rt<<1]*mul[rt]*mul[rt]*mul[rt]%MOD)%MOD;
		p3[rt<<1|1]=(p3[rt<<1|1]*mul[rt]*mul[rt]*mul[rt]%MOD)%MOD;
		add[rt<<1]=(add[rt<<1]*mul[rt])%MOD;
		add[rt<<1|1]=(add[rt<<1|1]*mul[rt])%MOD;
		mul[rt<<1]=(mul[rt<<1]*mul[rt])%MOD;
		mul[rt<<1|1]=(mul[rt<<1|1]*mul[rt])%MOD;
		mul[rt]=1;
	}
	if(add[rt]){//将一个区间同时加上一个数 
		p3[rt<<1]=(p3[rt<<1]+3*p2[rt<<1]*add[rt]%MOD+3*p1[rt<<1]*add[rt]*add[rt]%MOD+add[rt]*add[rt]*add[rt]*(mid-l+1)%MOD)%MOD;
		p3[rt<<1|1]=(p3[rt<<1|1]+3*p2[rt<<1|1]*add[rt]%MOD+3*p1[rt<<1|1]*add[rt]*add[rt]%MOD+(r-mid)*add[rt]*add[rt]*add[rt]%MOD)%MOD;
		p2[rt<<1]=(p2[rt<<1]+2*p1[rt<<1]*add[rt]%MOD+(mid-l+1)*add[rt]*add[rt]%MOD)%MOD;
		p2[rt<<1|1]=(p2[rt<<1|1]+2*p1[rt<<1|1]*add[rt]%MOD+(r-mid)*add[rt]*add[rt]%MOD)%MOD;
		p1[rt<<1]=(p1[rt<<1]+(mid-l+1)*add[rt]%MOD)%MOD;
		p1[rt<<1|1]=(p1[rt<<1|1]+(r-mid)*add[rt]%MOD)%MOD;
		add[rt<<1]=(add[rt<<1]+add[rt])%MOD;
		add[rt<<1|1]=(add[rt<<1|1]+add[rt])%MOD;
		add[rt]=0;
	}
}

void update(ll rt,ll l,ll r,ll L,ll R,ll val,ll f){
	if(l==L&&R==r){
		if(f==1){//add
			p3[rt]=(p3[rt]+3*p2[rt]*val%MOD+3*p1[rt]*val*val%MOD+(r-l+1)*val*val*val%MOD)%MOD;
			p2[rt]=(p2[rt]+2*p1[rt]*val%MOD+(r-l+1)*val*val%MOD)%MOD;
			p1[rt]=(p1[rt]+(r-l+1)*val%MOD)%MOD;
			add[rt]=(add[rt]+val)%MOD;
		}
		else if(f==2){//multiply
			p1[rt]=p1[rt]*val%MOD;
			p2[rt]=p2[rt]*val*val%MOD;
			p3[rt]=p3[rt]*val*val*val%MOD;
			add[rt]=add[rt]*val%MOD;
			mul[rt]=mul[rt]*val%MOD;
		}
		else{//change
			p1[rt]=(r-l+1)*val%MOD;
			p2[rt]=(r-l+1)*val*val%MOD;
			p3[rt]=(r-l+1)*val*val*val%MOD;
			change[rt]=val;
			add[rt]=0;//改变一个区间的数时同时取消其它标记 
			mul[rt]=1;
		}
		return ;
	}
	pushdown(rt,l,r);
	ll mid=(l+r)>>1;
	if(R<=mid){
		update(rt<<1,l,mid,L,R,val,f);
	}
	else if(L>mid){
		update(rt<<1|1,mid+1,r,L,R,val,f);
	}
	else{
		update(rt<<1,l,mid,L,mid,val,f);
		update(rt<<1|1,mid+1,r,mid+1,R,val,f);
	}
	p1[rt]=(p1[rt<<1]+p1[rt<<1|1])%MOD;
	p2[rt]=(p2[rt<<1]+p2[rt<<1|1])%MOD;
	p3[rt]=(p3[rt<<1]+p3[rt<<1|1])%MOD;
}

ll query(ll rt,ll l,ll r,ll L,ll R,ll f){
	if(l==L&r==R){
		if(f==1){
			return p1[rt];
		}
		else if(f==2){
			return p2[rt];
		}
		else{
			return p3[rt];
		}
	}
	ll mid=(l+r)>>1;
	pushdown(rt,l,r);
	if(R<=mid){
		return query(rt<<1,l,mid,L,R,f);
	}
	else if(L>mid){
		return query(rt<<1|1,mid+1,r,L,R,f);
	}
	else{
		return (query(rt<<1,l,mid,L,mid,f)+query(rt<<1|1,mid+1,r,mid+1,R,f))%MOD;
	}
}

int main(void){
	ll x,y,c,tmp;
	while(scanf("%lld %lld",&n,&m)!=EOF){
		if(n==0&m==0)
			break;
		ll len=(n<<2);
		for(ll i=0;i<=(len);i++){
			p1[i]=0;
			p2[i]=0;
			p3[i]=0;
			mul[i]=1;
			add[i]=0;
			change[i]=0;
		}
		while(m--){
			scanf("%lld %lld %lld %lld",&tmp,&x,&y,&c);
			if(tmp==1){
				update(1,1,n,x,y,c,1);
			}
			else if(tmp==2){
				update(1,1,n,x,y,c,2);
			}
			else if(tmp==3){
				update(1,1,n,x,y,c,3);
			}
			else{
				printf("%lld\n",query(1,1,n,x,y,c)%MOD);
			}
		}
	}
	return 0;
}
