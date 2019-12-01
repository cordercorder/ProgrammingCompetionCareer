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

# define ll long long

using namespace std;

const int maxsize=1e6+10;

struct node{
	int l;
	int r;
	int sum;
};

node t[maxsize*4];
int n,m;

void create(int num,int l,int r){
	t[num].l=l;
	t[num].r=r;
	if(r==l){
		scanf("%d",&t[num].sum);
		return ;
	}
	int mid=(l+r)/2;
	create(num*2,l,mid);
	create(num*2+1,mid+1,r);
	t[num].sum=t[num*2].sum+t[num*2+1].sum;
}

int query(int num,int ql,int qr){
	int nl,nr,mid;
	nl=t[num].l;
	nr=t[num].r;
	if(nl==ql&&nr==qr){
		return t[num].sum;
	}
	mid=(nl+nr)/2;
	if(qr<=mid){
		return query(num*2,ql,qr);
	}
	else if(ql>mid){
		return query(num*2+1,ql,qr);
	}
	else{
		return query(num*2,ql,mid)+query(num*2+1,mid+1,qr);
	}
}

int main(void){
	int i;
	int l,r;
	while(scanf("%d %d",&n,&m)!=EOF){
		create(1,1,n);
		while(m--){
			scanf("%d %d",&l,&r);
			printf("%d\n",query(1,l,r));
		}
	}
	return 0;
}
