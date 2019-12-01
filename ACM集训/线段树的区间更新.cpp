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
	int add;//ÑÓ³Ù±ê¼Ç;
	int sum;
	int Max;
	int Min;
}t[maxsize<<2];

int a[maxsize],n;

void create(int num,int l,int r){
	cout<<"ok"<<endl;
	t[num].l=l;
	t[num].r=r;
	t[num].add=0;
	if(l==r){
		t[num].sum=a[l];
		t[num].Max=a[l];
		t[num].Min=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	create(num<<1,l,mid);
	create(num<<1|1,mid+1,r);
	t[num].sum=t[num<<1].sum+t[num<<1|1].sum;
	t[num].Max=max(t[num<<1].Max,t[num<<1|1].Max);
	t[num].Min=min(t[num<<1].Min,t[num<<1|1].Min);
}


void pushdown(int num){
	if(t[num].add){
		t[num<<1].sum+=(t[num<<1].r-t[num<<1].l+1)*t[num].add;
		t[num<<1|1].sum+=(t[num<<1|1].r-t[num<<1|1].l+1)*t[num].add;
		t[num<<1].Max+=t[num].add;
		t[num<<1|1].Max+=t[num].add;
		t[num<<1].Min=t[num].add;
		t[num<<1|1].Min=t[num].add;
		t[num<<1].add=t[num].add;
		t[num<<1|1].add=t[num].add;
		t[num].add=0;
	}
}

void update(int num,int l,int r,int val){
	if(l<=t[num].l&&r>=t[num].r){
		t[num].sum+=(t[num].r-t[num].l+1)*val;
		t[num].Max+=val;
		t[num].Min+=val;
		t[num].add+=val;//
		return ;
	}
	pushdown(num);
	if(t[num].l>r||t[num].r<l)
		return ;
	update(num<<1,l,r,val);
	update(num<<1|1,l,r,val);
	t[num].sum=t[num<<1].sum+t[num<<1|1].sum;
	t[num].Max=max(t[num<<1].Max,t[num<<1|1].Max);
	t[num].Min=min(t[num<<1].Min,t[num<<1|1].Min);
}

int query(int num,int l,int r){
	if(l<=t[num].l&&r>=t[num].r){
		//return t[num].Max;
		//return t[num].Min;
		return t[num].sum;
	}
	pushdown(num);
	if(t[num].l>r||t[num].r<l){
		return 0;
	}
	//int sum=0;
	//int Max=0;
	//int Min=1e9+10;
	return query(num<<1,l,r)+query(num<<1|1,l,r);
}

int main(void){
	
	int l,r,k,val,q;
	while(scanf("%d %d",&n,&q)!=EOF){
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		create(1,1,n);
		while(q--){
			scanf("%d",&k);
			if(k==1){
				scanf("%d %d %d",&l,&r,&val);
				update(1,l,r,val);
			}
			else{
				scanf("%d %d",&l,&r);
				printf("%d\n",query(1,l,r)); 
			}
		}
	}
	return 0;
}
