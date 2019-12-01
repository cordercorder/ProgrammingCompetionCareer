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

int n,m;
int LL[maxn<<2],RR[maxn<<2];
stack<int> S;

void push_up(int rt,int l,int r){
	LL[rt]=LL[rt<<1];
	RR[rt]=RR[rt<<1|1];
	int mid=(l+r)>>1;
	if(mid-l+1==LL[rt<<1]){
		LL[rt]+=LL[rt<<1|1];
	}
	if(r-mid==RR[rt<<1|1]){
		RR[rt]+=RR[rt<<1];
	}
}

void create(int rt,int l,int r){
	if(l==r){
		LL[rt]=1;
		RR[rt]=1;
		return ;
	} 
	int mid=(l+r)>>1;
	create(rt<<1,l,mid);
	create(rt<<1|1,mid+1,r);
	push_up(rt,l,r);
}

void update(int rt,int l,int r,int pos,int val){
	if(l==r){
		LL[rt]=val;
		RR[rt]=val;
		return; 
	}
	int mid=(l+r)>>1;
	if(pos<=mid){
		update(rt<<1,l,mid,pos,val);
	}
	else{
		update(rt<<1|1,mid+1,r,pos,val);
	}
	push_up(rt,l,r);
}

int query(int rt,int l,int r,int pos){
	if(l==r||r-l+1==RR[rt]){
		return RR[rt];
	}
	int mid=(l+r)>>1;
	if(pos<=mid){
		if(pos>=mid+1-RR[rt<<1]){
			return query(rt<<1,l,mid,pos)+query(rt<<1|1,mid+1,r,mid+1);
		}
		else{
			return query(rt<<1,l,mid,pos);
		}
	}
	else{
		if(pos<=mid+LL[rt<<1|1]){
			return query(rt<<1,l,mid,mid)+query(rt<<1|1,mid+1,r,pos);
		}
		else{
			return query(rt<<1|1,mid+1,r,pos);
		}
	}
}

int main(void){
	char s[5];
	int x;
	while(scanf("%d %d",&n,&m)!=EOF){
		create(1,1,n);
		while(m--){
			scanf("%s",s);
			if(s[0]=='D'){
				scanf("%d",&x);
				S.push(x);
				update(1,1,n,x,0);
			}
			else if(s[0]=='Q'){
				scanf("%d",&x);
				printf("%d\n",query(1,1,n,x));
			}
			else if(s[0]=='R'){
				update(1,1,n,S.top(),1);
				S.pop();
			}
		}
	}
	return 0;
}
