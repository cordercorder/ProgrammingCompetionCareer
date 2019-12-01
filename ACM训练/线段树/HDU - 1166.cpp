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

const long double PI=acos(-1.0); 
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=5e4+10;

int T[maxn<<2];
int n,a[maxn];
int t;

void create(int rt,int l,int r){
	if(l==r){
		T[rt]=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	create(rt<<1,l,mid);
	create(rt<<1|1,mid+1,r);
	T[rt]=T[rt<<1]+T[rt<<1|1];
}

void update(int rt,int l,int r,int pos,int val){
	if(l==r){
		T[rt]+=val;
		return ;
	}
	int mid=(l+r)>>1;
	if(pos<=mid){
		update(rt<<1,l,mid,pos,val);
	}
	else{
		update(rt<<1|1,mid+1,r,pos,val);
	}
	T[rt]=T[rt<<1]+T[rt<<1|1];
}

int query(int rt,int l,int r,int L,int R){
	if(l==L&&R==r){
		return T[rt];
	}
	int mid=(l+r)>>1;
	if(R<=mid){
		return query(rt<<1,l,mid,L,R);
	}
	else if(L>mid){
		return query(rt<<1|1,mid+1,r,L,R);
	}
	else{
		return query(rt<<1,l,mid,L,mid)+query(rt<<1|1,mid+1,r,mid+1,R);
	}
}

int main(void){
	char s[10];
	int x,y;
	scanf("%d",&t);
	for(int k=1;k<=t;k++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		create(1,1,n);
		printf("Case %d:\n",k);
		while(scanf("%s",s)){
			if(s[0]=='A'){
				scanf("%d %d",&x,&y);
				update(1,1,n,x,y);
			}
			else if(s[0]=='S'){
				scanf("%d %d",&x,&y);
				update(1,1,n,x,-y);
			}
			else if(s[0]=='Q'){
				scanf("%d %d",&x,&y);
				printf("%d\n",query(1,1,n,x,y));
			}
			else if(s[0]=='E'){
				break;
			}
		}
	}
	return 0;
}
