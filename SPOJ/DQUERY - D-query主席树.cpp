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


const int maxn=3e4+10;

int a[maxn];
int n,q;
int la[1000000+100];
int root[maxn];
int cnt;

struct node{
	int l;
	int r;
	int sum;
}p[maxn*40];

int create(int l,int r){
	int nc=++cnt;
	p[nc].sum=0;
	p[nc].l=0;
	p[nc].r=0;
	if(l==r){
		return nc;
	}
	int mid=(l+r)>>1;
	p[nc].l=create(l,mid);
	p[nc].r=create(mid+1,r);
	return nc;
}

int update(int pos,int c,int val,int l,int r){
	int nc=++cnt;
	p[nc]=p[c];
	p[nc].sum+=val;
	if(l==r){
		return nc;
	}
	int mid=(l+r)>>1;
	if(mid>=pos){
		p[nc].l=update(pos,p[c].l,val,l,mid);
	}
	else{
		p[nc].r=update(pos,p[c].r,val,mid+1,r);
	}
	return nc;
}

int query(int pos,int c,int l,int r){
	if(l==r){
		return p[c].sum;
	}
	int mid=(l+r)>>1;
	if(mid>=pos){
		return p[p[c].r].sum+query(pos,p[c].l,l,mid);
	}
	else{
		return query(pos,p[c].r,mid+1,r);
	}
}


int main(void){
	int l,r;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		cnt=0;
		memset(la,-1,sizeof(la));
		root[0]=create(1,n);
		for(int i=1;i<=n;i++){
			if(la[a[i]]==-1){
				root[i]=update(i,root[i-1],1,1,n);
			}
			else{
				int tmp=update(la[a[i]],root[i-1],-1,1,n);
				root[i]=update(i,tmp,1,1,n);
			}
			la[a[i]]=i;
		}
		scanf("%d",&q);
		while(q--){
			scanf("%d %d",&l,&r);
			printf("%d\n",query(l,root[r],1,n));
		}
	}
	return 0;
}
