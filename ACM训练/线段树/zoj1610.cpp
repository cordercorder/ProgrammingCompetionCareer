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

const int maxn=8e3+10;

int T[maxn<<2];
int add[maxn<<2];
int n;
int res[maxn];
int num[maxn];

void pushdown(int rt){
	if(add[rt]){
		T[rt<<1]=add[rt];
		T[rt<<1|1]=add[rt];
		add[rt<<1]=add[rt];
		add[rt<<1|1]=add[rt];
		add[rt]=0;
	}
}

void update(int rt,int l,int r,int L,int R,int val){
	if(l==L&&R==r){
		T[rt]=val;
		add[rt]=val;
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

void handle(int rt,int l,int r){
	if(l==r){
		res[l]=T[rt];
		//if(l==1){
			//deb(T[rt]);
		//}
		return ;
	}
	pushdown(rt);
	int mid=(l+r)>>1;
	handle(rt<<1,l,mid);
	handle(rt<<1|1,mid+1,r);
}

void solve(){
	handle(1,1,8001);
	memset(num,0,sizeof(num));
	for(int i=1;i<=8001;){
		if(res[i]!=0){
			num[res[i]]++;
		}
		int j=i+1;
		while(j<=8001&&res[j]==res[i]){
			j++;
		}
		i=j;
	}
	for(int i=1;i<=8001;i++){
		if(num[i]){
			printf("%d %d\n",i-1,num[i]);
		}
	}
	printf("\n");
}

int main(void){
	int x1,x2,c;
	while(scanf("%d",&n)!=EOF){
		memset(T,0,sizeof(T));
		memset(add,0,sizeof(add));
		memset(res,0,sizeof(res));
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&x1,&x2,&c);
			++x1;
			++c;
			update(1,1,8001,x1,x2,c);
			//handle(1,1,8001);
		}
		solve();
	}
	return 0;
}
