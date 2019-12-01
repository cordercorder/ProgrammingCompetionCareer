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
const int maxn_n=4*maxn;

int t;
int res[maxn_n];
int n;
int cnt;
int l[maxn],r[maxn];
int T[maxn_n<<2];
int add[maxn_n<<2];
int num[maxn_n];
set<int> ans;

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
	if(L==l&&R==r){
		T[rt]=val;
		add[rt]=val;
		return ;
	}
	int mid=(l+r)>>1;
	pushdown(rt);
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

void query(int rt,int l,int r){
	if(l==r){
		num[l]=T[rt];
		return ;
	}
	pushdown(rt);
	int mid=(l+r)>>1;
	query(rt<<1,l,mid);
	query(rt<<1|1,mid+1,r);
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
	int nl,nr;
	for(int i=1;i<=n;i++){
		nl=lower_bound(res+1,res+1+len,l[i])-res;
		nr=lower_bound(res+1,res+1+len,r[i])-res;
		update(1,1,len,nl,nr,i);
	}
	query(1,1,len);
	for(int i=1;i<=len;i++){
		if(num[i]){
			ans.insert(num[i]);
		}
	}
	printf("%d\n",(int)ans.size());
	ans.clear();
}

int main(void){
	scanf("%d",&t);
	while(t--){
		cnt=0; 
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d",&l[i],&r[i]);
			res[++cnt]=l[i];
			res[++cnt]=r[i];
		}
		solve();
	}
	return 0;
}
