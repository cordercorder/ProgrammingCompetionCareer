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

const int maxn=5e4+10;

int Max[maxn<<2],Min[maxn<<2];
int a[maxn];

int n,q;

void create(int rt,int l,int r){
	if(l==r){
		Max[rt]=a[l];
		Min[rt]=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	create(rt<<1,l,mid);
	create(rt<<1|1,mid+1,r);
	Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
	Min[rt]=min(Min[rt<<1],Min[rt<<1|1]);
}

int query_Max(int rt,int l,int r,int L,int R){
	if(L==l&&R==r){
		return Max[rt];
	}
	int mid=(l+r)>>1;
	if(R<=mid){
		return query_Max(rt<<1,l,mid,L,R);
	}
	else if(L>mid){
		return query_Max(rt<<1|1,mid+1,r,L,R);
	}
	else{
		return max(query_Max(rt<<1,l,mid,L,mid),query_Max(rt<<1|1,mid+1,r,mid+1,R));
	}
}

int query_Min(int rt,int l,int r,int L,int R){
	if(L==l&&R==r){
		return Min[rt];
	}
	int mid=(l+r)>>1;
	if(R<=mid){
		return query_Min(rt<<1,l,mid,L,R);
	}
	else if(L>mid){
		return query_Min(rt<<1|1,mid+1,r,L,R);
	}
	else{
		return min(query_Min(rt<<1,l,mid,L,mid),query_Min(rt<<1|1,mid+1,r,mid+1,R));
	}
}

int main(void){
	int A,B;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	create(1,1,n);
	while(q--){
		scanf("%d %d",&A,&B);
		printf("%d\n",query_Max(1,1,n,A,B)-query_Min(1,1,n,A,B));
	}
	return 0;
}
