# include<iostream>
# include<algorithm>
# include<cstring>
# include<string>
# include<cmath>
# include<queue>
# include<stack>
# include<set>
# include<vector>
# include<cstdio>
# include<cstdlib>
# include<map>
# include<deque>
# include<limits.h>

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

const int maxsize=1e5+10;
const int mod=998244353;

struct node{
	int l;
	int r;
	int Min;
	int add;
}t[2][maxsize<<2];

int T;
int n,m;

void create(int id,int rt,int l,int r){
	t[id][rt].l=l;
	t[id][rt].r=r;
	t[id][rt].add=0;
	if(l==r){
		t[id][rt].Min=0;
		return ;
	}
	int mid=(l+r)>>1;
	create(id,rt<<1,l,mid);
	create(id,rt<<1|1,mid+1,r);
	t[id][rt].Min=min(t[id][rt<<1].Min,t[id][rt<<1|1].Min);
}

void pushdown(int id,int rt){
	if(t[id][rt].add){
		t[id][rt<<1].Min+=t[id][rt].add;
		t[id][rt<<1|1].Min+=t[id][rt].add;
		t[id][rt<<1].add+=t[id][rt].add;
		t[id][rt<<1|1].add+=t[id][rt].add;
		t[id][rt].add=0;
	}
}

void update(int id,int rt,int l,int r,int val){
	if(l==r){
		t[id][rt].Min+=val;
		t[id][rt].add+=val;
		return ;
	}
	pushdown(id,rt);
	int mid=(t[id][rt].l+t[id][rt].r)>>1;
	if(r<=mid){
		update(id,rt<<1,l,r,val);
	}
	else if(l>mid){
		update(id,rt<<1|1,l,r,val);
	}
	else{
		update(id,rt<<1,l,mid,val);
		update(id,rt<<1|1,mid+1,r,val);
	}
	t[id][rt].Min=min(t[id][rt<<1].Min,t[id][rt<<1|1].Min);
}

int query(int id,int rt,int l,int r){
	if(l==t[id][rt].l&&r==t[id][rt].r){
		return t[id][rt].Min;
	}
	pushdown(id,rt);
	int mid=(t[id][rt].l+t[id][rt].r)>>1;
	if(r<=mid){
		return query(id,rt<<1,l,r);
	}
	else if(l>mid){
		return query(id,rt<<1|1,l,r);
	}
	else{
		return min(query(id,rt<<1,l,mid),query(id,rt<<1|1,mid+1,r));
	}
}

ll q_mod(ll a,ll b){
	ll ans=1;
	while(b){
		if(b){
			ans=ans*a%mod;
		}
		b=b>>1;
		a=a*a%mod;
	}
	return ans;
}

int main(void){
	int l,r,x,tmp;
	ll ans;
	while(scanf("%d",&T)!=EOF){
		while(T--){
			scanf("%d %d",&n,&m);
			create(0,1,1,n);
			create(1,1,1,n);
			while(m--){
				scanf("%d %d %d",&l,&r,&x);
				if(x==2){
					update(0,1,l,r,1);
				}
				else{
					update(1,1,l,r,1);
				}
			}
			tmp=query(0,1,1,n);
			ans=q_mod((ll)2,tmp);
			tmp=query(1,1,1,n);
			ans=ans*q_mod((ll)3,tmp);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
