#include<algorithm>
#include<iostream>
#include<limits.h>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<string>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<ctime>
#include<set>
#include<map>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("data.txt","r",stdin)
#define FOUT freopen("data.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e5+10;

int a[maxn];
int n;
int T[maxn<<2];
int ans;

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

int handle(int rt,int l,int r,int val){
	if(T[rt]>=val)
		return -1;
	if(l==r){
		return l;
	}
	int mid=(l+r)>>1;
	if(T[rt<<1|1]<val){
		handle(rt<<1|1,mid+1,r,val);
	}
	else{
		handle(rt<<1,l,mid,val);
	}
}

void query(int rt,int l,int r,int L,int R,int val){
	if(l==L&&R==r){
		ans=max(ans,handle(rt,l,r,val));
		return ;
	}
	int mid=(l+r)>>1;
	if(R<=mid){
		query(rt<<1,l,mid,L,R,val);
	}
	else if(L>mid){
		query(rt<<1|1,mid+1,r,L,R,val);
	}
	else{
		query(rt<<1,l,mid,L,mid,val);
		query(rt<<1|1,mid+1,r,mid+1,R,val);
	}
}

void solve(){
	create(1,1,n);
	for(int i=1;i<n;i++){
		ans=-1;
		query(1,1,n,i+1,n,a[i]);
		if(ans==-1){
			printf("%d ",ans);
		}
		else{
			printf("%d ",ans-i-1);
		}
	}
	printf("-1\n");
}

int main(void){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	solve();
	return 0;
}
