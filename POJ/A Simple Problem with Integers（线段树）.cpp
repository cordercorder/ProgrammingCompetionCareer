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

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

const int maxsize=1e5+10;

struct node{
	ll l;
	ll r;
	ll sum;
	ll add;
	ll mid(){
		return (l+r)>>1;
	}
}t[maxsize<<2];

ll n,q;
ll a[maxsize];

void create(ll rt,ll l,ll r){
	t[rt].l=l;
	t[rt].r=r;
	t[rt].add=0;
	if(l==r){
		t[rt].sum=a[l];
		return ;
	}
	create(rt<<1,l,t[rt].mid());
	create(rt<<1|1,t[rt].mid()+1,r);
	t[rt].sum=t[rt<<1].sum+t[rt<<1|1].sum;
}

void pushdown(ll rt){
	if(t[rt].add){
		t[rt<<1].sum+=(t[rt<<1].r-t[rt<<1].l+1)*t[rt].add;
		t[rt<<1|1].sum+=(t[rt<<1|1].r-t[rt<<1|1].l+1)*t[rt].add;
		t[rt<<1].add+=t[rt].add;
		t[rt<<1|1].add+=t[rt].add;
		t[rt].add=0;
	}
}

void update(ll rt,ll l,ll r,ll val){
	if(t[rt].l==l&&t[rt].r==r){
		t[rt].sum+=(t[rt].r-t[rt].l+1)*val;
		t[rt].add+=val;
		return ;
	}
	pushdown(rt);
	if(r<=t[rt].mid()){
		update(rt<<1,l,r,val);
	}
	else if(l>t[rt].mid()){
		update(rt<<1|1,l,r,val);
	}
	else{
		update(rt<<1,l,t[rt].mid(),val);
		update(rt<<1|1,t[rt].mid()+1,r,val);
	}
	t[rt].sum=t[rt<<1].sum+t[rt<<1|1].sum;
}

ll query(ll rt,ll l,ll r){
	if(t[rt].l==l&&t[rt].r==r){
		return t[rt].sum;
	}
	pushdown(rt);
	if(r<=t[rt].mid()){
		return query(rt<<1,l,r);
	}
	else if(l>t[rt].mid()){
		return query(rt<<1|1,l,r);
	} 
	else{
		return query(rt<<1,l,t[rt].mid())+query(rt<<1|1,t[rt].mid()+1,r);
	}
}

int main(void){
	char str[30];
	ll l,r,v;
	while(scanf("%lld %lld",&n,&q)!=EOF){
		for(ll i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		create(1,1,n);
		while(q--){
			scanf("%s",str);
			if(str[0]=='C'){
				scanf("%lld %lld %lld",&l,&r,&v);
				update(1,l,r,v);
			}
			else{
				scanf("%lld %lld",&l,&r);
				printf("%lld\n",query(1,l,r));
			}
		}
	}
	return 0;
}
