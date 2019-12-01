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

const int maxn=50000;

int w[maxn],d[maxn];
int n,m;
int T[maxn<<2];
bool isv[maxn<<2];

void create(int rt,int l,int r){
	if(l==r){
		T[rt]=w[l];
		return ;
	}
	int mid=(l+r)>>1;
	create(rt<<1,l,mid);
	create(rt<<1|1,mid+1,r);
	T[rt]=min(T[rt<<1],T[rt<<1|1]);
}

int query(int rt,int l,int r,int val){
	if(T[rt]>=val)
		return n+1;
	if(l==r){
		return l;
	}
	int mid=(l+r)>>1;
	if(T[rt<<1]<val){
		return query(rt<<1,l,mid,val);
	}
	else{
		return query(rt<<1|1,mid+1,r,val);
	}
}

void update(int rt,int l,int r,int pos){
	if(l==r){
		T[rt]=0;
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

void solve(){
	int ans=0,pos;
	create(1,1,n);	
	for(int i=1;i<=m;i++){
		pos=query(1,1,n,d[i]);
		greater<int>()
		upper_bound()
		lower_bound()
		
		//deb(pos);
		if(pos==1){
			update(1,1,n,pos);
			continue;
		}
		update(1,1,n,pos-1);
		//update(1,1,n,pos,n);
		ans++;
	}
	printf("%d\n",ans);
}

int main(void){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&d[i]);
	}
	solve();
	return 0;
}
