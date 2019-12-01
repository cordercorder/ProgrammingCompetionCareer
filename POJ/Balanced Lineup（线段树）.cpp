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

const int maxsize=5e4+10;

struct node{
	int l;
	int r;
	int Max;
	int Min;
	int mid(){
		return (l+r)>>1;
	}
}t[maxsize<<2];

int n,q;
int a[maxsize];

void create(int num,int l,int r){
	t[num].l=l;
	t[num].r=r;
	if(l==r){
		t[num].Max=a[l];
		t[num].Min=a[l];
		return ;
	}
	create(num<<1,l,t[num].mid());
	create(num<<1|1,t[num].mid()+1,r);
	t[num].Max=max(t[num<<1].Max,t[num<<1|1].Max);
	t[num].Min=min(t[num<<1].Min,t[num<<1|1].Min);
}

int query(int num,int l,int r,bool flag){
	if(t[num].l==l&&t[num].r==r){
		if(flag)
			return t[num].Max;
		return t[num].Min;
	}
	if(r<=t[num].mid()){
		return query(num<<1,l,r,flag);
	}
	else if(l>t[num].mid()){
		return query(num<<1|1,l,r,flag);
	}
	else{
		if(flag){
			return max(query(num<<1,l,t[num].mid(),flag),query(num<<1|1,t[num].mid()+1,r,flag));
		}
		else{
			return min(query(num<<1,l,t[num].mid(),flag),query(num<<1|1,t[num].mid()+1,r,flag)); 
		}
	}
}

int main(void){
	int l,r;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	create(1,1,n);
	while(q--){
		scanf("%d %d",&l,&r);
		printf("%d\n",query(1,l,r,1)-query(1,l,r,0));
	}
	return 0;
}
