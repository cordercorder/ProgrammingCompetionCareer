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
# include<ctime>

# define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=5e4+10;

int n,m;
int a[maxn];
int b[maxn];
int Max[maxn<<2];
int ans[maxn];

void create(int rt,int l,int r){
	if(l==r){
		Max[rt]=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	create(rt<<1,l,mid);
	create(rt<<1|1,mid+1,r);
	Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
}

void update(int rt,int  l,int r,int val,int &id){
	if(l==r){
		if(Max[rt]>=val)
			id=l;
		return ;
	}
	int mid=(l+r)>>1;
	if(Max[rt<<1]>=val){
		update(rt<<1,l,mid,val,id);
	}
	else{
		update(rt<<1|1,mid+1,r,val,id);
	}
	Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
}

void update(int rt,int l,int r,int x){
	if(l==r){
		Max[rt]++;
		return ;
	}
	int mid=(l+r)>>1;
	if(x<=mid){
		update(rt<<1,l,mid,x);
	}
	else{
		update(rt<<1|1,mid+1,r,x);
	}
	Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
}

void handle(int rt,int l,int r){
	if(l==r){
		ans[l]=Max[rt];
		return ;
	}
	int mid=(l+r)>>1;
	handle(rt<<1,l,mid);
	handle(rt<<1|1,mid+1,r);
}

int main(void){
	int id;
	while(scanf("%d %d",&m,&n)!=EOF){
		for(int i=1;i<=m;i++){
			scanf("%d",&a[i]);
		}
		create(1,1,m);
		for(int i=1;i<=n;i++){
			id=-1;
			scanf("%d",&b[i]);
			update(1,1,m,b[i],id);
			//deb(id);
			if(id==-1||id<=1)
				continue;
			update(1,1,m,id-1);
		}
		handle(1,1,m);
		for(int i=1;i<=m;i++){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}
