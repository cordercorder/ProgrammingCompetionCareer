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

int T[maxn<<2],add[maxn<<2];
int n,q;
int t;

template<typename T>
void _read(T &ret){
	char ch=getchar();
	bool f=0;
    ret=0;
    while(ch<'0'||ch>'9'){
    	if(ch=='-'){
    		f=1;
		}
    	ch=getchar();
	}
    while(ch>='0'&&ch<='9'){
    	ret=ret*10+(ch-'0');
    	ch=getchar();
	}
    if(f)
    	ret=-ret;
}

void create(int rt,int l,int r){
	add[rt]=0;
	if(l==r){
		T[rt]=1;
		return ;
	}
	int mid=(l+r)>>1;
	create(rt<<1,l,mid);
	create(rt<<1|1,mid+1,r);
	T[rt]=T[rt<<1]+T[rt<<1|1];
}

void pushdown(int rt,int l,int r){
	if(add[rt]){
		int mid=(l+r)>>1;
		T[rt<<1]=(mid-l+1)*add[rt];
		T[rt<<1|1]=(r-mid)*add[rt];
		add[rt<<1]=add[rt];
		add[rt<<1|1]=add[rt];
		add[rt]=0;
	}
}

void update(int rt,int l,int r,int L,int R,int val){
	if(l==L&&r==R){
		T[rt]=val*(r-l+1);
		add[rt]=val;
		return ;
	}
	int mid=(l+r)>>1;
	pushdown(rt,l,r);
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

int main(void){
	int x,y;
	int z;
	while(scanf("%d",&t)!=EOF){
		for(int i=1;i<=t;i++){
			scanf("%d %d",&n,&q);
			create(1,1,n);
			while(q--){
				//scanf("%d %d %d",&x,&y,&z);
				_read<int>(x);
				_read<int>(y);
				_read<int>(z);
				update(1,1,n,x,y,z);
			}
			printf("Case %d: The total value of the hook is ",i);
			printf("%d.\n",T[1]);
		}
	}
	return 0;
}
