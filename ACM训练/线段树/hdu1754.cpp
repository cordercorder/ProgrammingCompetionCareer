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

const int maxn=2e5+10;

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

struct SegTree{
	int t[maxn<<2];
	int n,m;
	int a[maxn];
	void create(int rt,int l,int r){
		if(l==r){
			t[rt]=a[l];
			return ;
		}
		int mid=(l+r)>>1;
		create(rt<<1,l,mid);
		create(rt<<1|1,mid+1,r);
		t[rt]=max(t[rt<<1],t[rt<<1|1]);
	}
	void update(int rt,int l,int r,int pos,int val){
		if(l==r){
			t[rt]=val;
			return ;
		}
		int mid=(l+r)>>1;
		if(pos<=mid){
			update(rt<<1,l,mid,pos,val);
		}
		else{
			update(rt<<1|1,mid+1,r,pos,val);
		}
		t[rt]=max(t[rt<<1],t[rt<<1|1]);
	}
	int query(int rt,int l,int r,int L,int R){
		if(l==L&&r==R){
			return t[rt];
		}
		int mid=(l+r)>>1;
		if(R<=mid){
			return query(rt<<1,l,mid,L,R);
		}
		else if(L>mid){
			return query(rt<<1|1,mid+1,r,L,R);
		}
		else{
			return max(query(rt<<1,l,mid,L,mid),query(rt<<1|1,mid+1,r,mid+1,R));
		}
	}
}T;

int main(void){
	char s[5];
	int a,b;
	while(scanf("%d %d",&T.n,&T.m)!=EOF){
		for(int i=1;i<=T.n;i++){
			_read(T.a[i]);
			cout<<"ok"<<endl;
		}
		T.create(1,1,T.n);
		for(int i=1;i<=T.m;i++){
			scanf("%s",s);
			_read(a);
			_read(b);
			if(s[0]=='Q'){
				printf("%d\n",T.query(1,1,T.n,a,b));
			}
			else{
				T.update(1,1,T.n,a,b);
			}
		}
	}
	return 0;
}
