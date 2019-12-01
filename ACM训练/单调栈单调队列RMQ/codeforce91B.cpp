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
const int maxw=1e9+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e5+10;

int a[maxn];
int ans[maxn];
int n;
int T[maxn<<2];

void create(int rt,int l,int r){
	if(l==r){
		T[rt]=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	create(rt<<1,l,mid);
	create(rt<<1|1,mid+1,r);
	T[rt]=min(T[rt<<1],T[rt<<1|1]);
}

void update(int rt,int l,int r,int pos){
	if(l==r){
		T[rt]=maxw;
		return ;
	}
	int mid=(l+r)>>1;
	if(pos<=mid){
		update(rt<<1,l,mid,pos);
	}
	else{
		update(rt<<1|1,mid+1,r,pos);
	}
	T[rt]=min(T[rt<<1],T[rt<<1|1]);
}

int query(int rt,int l,int r,int val){
	if(l==r){
		return l;
	}
	int mid=(l+r)>>1;
	if(T[rt<<1|1]<val){
		return query(rt<<1|1,mid+1,r,val);
	}
	else{
		return query(rt<<1,l,mid,val);
	}
}

void solve(){
	int pos;
	create(1,1,n);
	for(int i=n;i>=1;i--){
		pos=query(1,1,n,a[i]);
		//deb(pos);
		if(pos<=i){
			ans[i]=-1;
			continue;
		}
		ans[i]=pos-i-1;
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	puts("");
}

int main(void){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	solve();
	return 0;
}
