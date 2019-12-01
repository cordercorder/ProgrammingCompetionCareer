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

const int maxn=1e4+10;
	
int L[maxn],R[maxn];
int res[maxn*4];
int cnt;
int n;
int T[maxn*16],add[maxn*16];
int num[maxn*4];
int t;

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
		num[l]=T[rt];
		return ;
	}
	pushdown(rt);
	int mid=(l+r)>>1;
	handle(rt<<1,l,mid);
	handle(rt<<1|1,mid+1,r);
}

void solve(){
	memset(T,0,sizeof(T));
	memset(add,0,sizeof(add));
	memset(num,0,sizeof(num));
	sort(res+1,res+1+cnt);
	int len=unique(res+1,res+1+cnt)-res-1;
	int tmp=len;
	for(int i=2;i<=tmp;i++){
		if(res[i]-res[i-1]>1){
			res[++len]=res[i-1]+1;
		}
	}
	sort(res+1,res+1+len);
	int l,r;
	for(int i=1;i<=n;i++){
		l=lower_bound(res+1,res+1+len,L[i])-res;	
		r=lower_bound(res+1,res+1+len,R[i])-res;
		update(1,1,len,l,r,i);
	}
	handle(1,1,len);
	set<int> ans;
	for(int i=1;i<=len;i++){
		if(num[i])
			ans.insert(num[i]);
	}
	printf("%d\n",(int)ans.size());
	ans.clear();
}

int main(void){
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d",&n);
			cnt=0;
			for(int i=1;i<=n;i++){
				scanf("%d %d",&L[i],&R[i]);
				res[++cnt]=L[i]; 
				res[++cnt]=R[i];
			}
			solve();
		}
	}
	return 0;
}
