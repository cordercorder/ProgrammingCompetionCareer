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
ll n,a[maxn];

void create(ll rt,ll l,ll r){
	add[rt]=0;
	if(l==r){
		T[rt]=a[l];
		return ;
	}
	ll mid=(l+r)>>1;
	create(rt<<1,l,mid);
	create(rt<<1|1,mid+1,r);
	T[rt]=T[rt<<1]+T[rt<<1|1];
}

void update(ll rt,ll l,ll r,ll L,ll R){
	if(l==r){
		T[rt]=sqrt(T[rt]);
		return ;
	}
	if(T[rt]==(r-l+1))
		return;
	ll mid=(l+r)>>1;
	if(R<=mid){
		update(rt<<1,l,mid,L,R);
	}
	else if(L>mid){
		update(rt<<1|1,mid+1,r,L,R);
	}
	else{
		update(rt<<1,l,mid,L,mid);
		update(rt<<1|1,mid+1,r,mid+1,R);
	}
	T[rt]=T[rt<<1]+T[rt<<1|1];
}

ll query(ll rt,ll l,ll r,ll L,ll R){
	if(l==L&&R==r){
		return T[rt];
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
	ll q;
	ll t,x,y;
	ll sum=0;
	while(scanf("%lld",&n)!=EOF){
		sum++;
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		create(1,1,n);
		scanf("%lld",&q);
		printf("Case #%lld:\n",sum);
		while(q--){
			scanf("%lld %lld %lld",&t,&x,&y);
			if(x>y){
				swap(x,y);
			}
			if(t==0){
				update(1,1,n,x,y);
			}
			else{
				printf("%lld\n",query(1,1,n,x,y));
			}
		}
		printf("\n");
	}
	return 0;
}
