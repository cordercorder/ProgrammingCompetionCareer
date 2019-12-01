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

const int maxn=5e4+10;

struct node{
	int l;
	int r;
	int l_len;
	int r_len;
	int t_len;
	int flag;
}t[maxn<<2];

int n,m;

void create(int rt,int l,int r){
	t[rt].l=l;
	t[rt].r=r;
	t[rt].l_len=t[rt].r_len=t[rt].t_len=r-l+1;//开始时房间全部可用 
	t[rt].flag=-1;
	if(l==r)
		return ;
	int mid=(l+r)>>1;
	create(rt<<1,l,mid);
	create(rt<<1|1,mid+1,r);
}

void pushdown(int rt){
	if(t[rt].flag!=-1){
		t[rt<<1].flag=t[rt<<1|1].flag=t[rt].flag;
		if(t[rt].flag==0){
			t[rt<<1].l_len=t[rt<<1].r_len=t[rt<<1].t_len=0;
			t[rt<<1|1].l_len=t[rt<<1|1].r_len=t[rt<<1|1].t_len=0;
		}
		else{
			t[rt<<1].l_len=t[rt<<1].r_len=t[rt<<1].t_len=t[rt<<1].r-t[rt<<1].l+1;
			t[rt<<1|1].l_len=t[rt<<1|1].r_len=t[rt<<1|1].t_len=t[rt<<1|1].r-t[rt<<1|1].l+1; 
		}
		t[rt].flag=-1;
	}
}

void push_up(int rt){
	t[rt].t_len=max(t[rt<<1].t_len,t[rt<<1|1].t_len);
	t[rt].t_len=max(t[rt].t_len,t[rt<<1].r_len+t[rt<<1|1].l_len);
	t[rt].l_len=t[rt<<1].l_len;
	t[rt].r_len=t[rt<<1|1].r_len;
	if(t[rt<<1].l_len==t[rt<<1].r-t[rt<<1].l+1){
		t[rt].l_len=t[rt<<1].l_len+t[rt<<1|1].l_len;
	}
	if(t[rt<<1|1].r_len==t[rt<<1|1].r-t[rt<<1|1].l+1){
		t[rt].r_len=t[rt<<1|1].r_len+t[rt<<1].r_len;
	}
}

void update(int rt,int l,int r,int val){
	if(t[rt].l==l&&t[rt].r==r){
		t[rt].flag=val;
		if(val==0)
			t[rt].t_len=t[rt].l_len=t[rt].r_len=0;
		else{
			t[rt].t_len=t[rt].l_len=t[rt].r_len=t[rt].r-t[rt].l+1;
		}
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(r<=mid){
		update(rt<<1,l,r,val);
	}
	else if(l>mid){
		update(rt<<1|1,l,r,val);
	}
	else{
		update(rt<<1,l,mid,val);
		update(rt<<1|1,mid+1,r,val);
	}
	push_up(rt);
} 

int query(int rt,int x){
	if(t[rt].l==t[rt].r&&x==1){
		return t[rt].l;
	}
	pushdown(rt);
	if(t[rt<<1].t_len>=x){
		return query(rt<<1,x);
	}
	else if(t[rt<<1].r_len+t[rt<<1|1].l_len>=x){
		return t[rt<<1].r-t[rt<<1].r_len+1;
	}
	else if(t[rt<<1|1].t_len>=x){
		return query(rt<<1|1,x);
	}
	else{
		return 0;
	}
}

int main(void){
	int val,l,r;
	int pos,x;
	while(scanf("%d %d",&n,&m)!=EOF){
		create(1,1,n);
		while(m--){
			scanf("%d",&val);
			if(val==1){
				scanf("%d",&x);
				pos=query(1,x);
				printf("%d\n",pos);
				if(pos){
					update(1,pos,pos+x-1,0);
				}
			}
			else{
				scanf("%d %d",&l,&x);
				update(1,l,l+x-1,1);
			}
		}
	}
	return 0;
}
