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

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

const int maxn=8e3+10;

int t[maxn<<2];
int num[maxn];
int sum[maxn];
int n;

void pushdown(int rt){
	if(t[rt]!=-1){
		t[rt<<1]=t[rt];
		t[rt<<1|1]=t[rt];
		t[rt]=-1;
	}
}

void update(int rt,int l,int r,int L,int R,int val){
	if(l==L&&r==R){
		t[rt]=val;
		return ;
	}
	pushdown(rt);
	int mid=(l+r)>>1;
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
}

void query(int rt,int l,int r){
	if(l==r){
		num[l]=t[rt];
		return ;
	}
	pushdown(rt);
	int mid=(l+r)>>1;
	query(rt<<1,l,mid);
	query(rt<<1|1,mid+1,r);
}

int main(void){
	int x1,x2,c;
	while(scanf("%d",&n)!=EOF){
		memset(t,-1,sizeof(t));
		for(int i=0;i<n;i++){
			scanf("%d %d %d",&x1,&x2,&c);
			if(x1>=x2)
				continue;
			update(1,1,8000,x1+1,x2,c);
		}
		query(1,1,8000);
		int tmp;
		bool flag;
		memset(sum,0,sizeof(sum));
		//for(int i=1;i<=n;i++){
		//	printf("%d ",num[i]);
		//}
		//cout<<endl;
		for(int i=1;i<=8000;){
			int j=i;
			flag=0;
			tmp=num[i];
			while(j<=8000&&num[j]==tmp){
				j++;
				flag=1;
			}
			//cout<<"tmp=="<<tmp<<endl;
			if(tmp!=-1)
				sum[tmp]++;
			i=j;
			if(!flag)
				i++;
		}
		for(int i=0;i<=8000;i++){
			if(sum[i]){
				printf("%d %d\n",i,sum[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
