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
	int l;
	int r;
	int sum;
	int add;
	int mid(){
		return (l+r)>>1;
	}
}t[maxsize<<2];

int n,k,q;

void create(int rt,int l,int r){
	t[rt].l=l;
	t[rt].r=r;
	t[rt].add=0;
	if(l==r){
		t[rt].sum=1;
		return ;
	}
	create(rt<<1,l,t[rt].mid());
	create(rt<<1|1,t[rt].mid()+1,r);
	t[rt].sum=t[rt<<1].sum|t[rt<<1|1].sum;
}

void pushdown(int rt){
	if(t[rt].add){
		t[rt<<1].sum=t[rt].sum;
		t[rt<<1|1].sum=t[rt].sum;
		t[rt<<1].add=t[rt].add;
		t[rt<<1|1].add=t[rt].add;
		t[rt].add=0;
	}
}

void update(int rt,int l,int r,int val){
	if(t[rt].l==l&&t[rt].r==r){
		t[rt].sum=val;
		t[rt].add=val;
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
	t[rt].sum=t[rt<<1].sum|t[rt<<1|1].sum; 
}

int query(int rt,int l,int r){
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
		return query(rt<<1,l,t[rt].mid())|query(rt<<1|1,t[rt].mid()+1,r);
	}
}

int solve(int x){
	int ans=0;
	while(x){
		if(x&1)
			ans++;
		x=x>>1;
	}
	return ans;
}

int main(void){
	char ch[30];
	int l,r,val,tmp;
	scanf("%d %d %d",&n,&k,&q);
	create(1,1,n);
	while(q--){
		scanf("%s",ch);
		if(ch[0]=='C'){
			scanf("%d %d %d",&l,&r,&val);
			if(l>r)
				swap(l,r); 
			update(1,l,r,1<<(val-1));
		}
		else{
			scanf("%d %d",&l,&r);
			if(l>r)
				swap(l,r);
			tmp=query(1,l,r);
			printf("%d\n",solve(tmp));
		}
	}
	return 0;
}
