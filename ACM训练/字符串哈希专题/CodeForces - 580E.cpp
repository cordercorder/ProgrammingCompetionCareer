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
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e5+10;

int n,m,k;
char s[maxn];
char ch[10];
int L,R,d;
ll seed=131LL,base[2][maxn],res[2][maxn],sum[2][maxn];
ll T[2][maxn<<2],add[maxn<<2];
const ll mod[2]={1000000007LL,998244352LL};

void create(int rt,int l,int r){
	if(l==r){
		T[0][rt]=res[0][l];
		T[1][rt]=res[1][l];
		return ;
	}
	int mid=(l+r)>>1;
	create(rt<<1,l,mid);
	create(rt<<1|1,mid+1,r);
	T[0][rt]=(T[0][rt<<1]+T[0][rt<<1|1])%mod[0];
	T[1][rt]=(T[1][rt<<1]+T[1][rt<<1|1])%mod[1];
}

void cal(int id,int rt,int l,int r,int mid){
	T[id][rt<<1]=add[rt]*(sum[id][mid-1]-sum[id][l-1]+base[id][l-1])%mod[id];
	T[id][rt<<1]=(T[id][rt<<1]+mod[id])%mod[id];
	T[id][rt<<1|1]=add[rt]*(sum[id][r-1]-sum[id][mid]+base[id][mid])%mod[id];
	T[id][rt<<1|1]=(T[id][rt<<1|1]+mod[id])%mod[id];	
}

void pushdown(int rt,int l,int r){
	if(add[rt]){
		int mid=(l+r)>>1;
		cal(0,rt,l,r,mid);
		cal(1,rt,l,r,mid);
		add[rt<<1]=add[rt];
		add[rt<<1|1]=add[rt];
		add[rt]=0;
	}
}

void update(int rt,int l,int r,int L,int R,ll val){
	if(l==L&&R==r){
		add[rt]=val;
		T[0][rt]=add[rt]*(sum[0][R-1]-sum[0][L-1]+base[0][L-1])%mod[0];
		T[0][rt]=(T[0][rt]+mod[0])%mod[0];
		T[1][rt]=add[rt]*(sum[1][R-1]-sum[1][L-1]+base[1][L-1])%mod[1];
		T[1][rt]=(T[1][rt]+mod[1])%mod[1];
		return ;
	}
	pushdown(rt,l,r);
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
	T[0][rt]=(T[0][rt<<1]+T[0][rt<<1|1])%mod[0];
	T[1][rt]=(T[1][rt<<1]+T[1][rt<<1|1])%mod[1];
}

ll query(int id,int rt,int l,int r,int L,int R){
	if(l==L&&R==r){
		return T[id][rt];
	}
	pushdown(rt,l,r);
	int mid=(l+r)>>1;
	if(R<=mid){
		return query(id,rt<<1,l,mid,L,R);
	}
	else if(L>mid){
		return query(id,rt<<1|1,mid+1,r,L,R);
	}
	else{
		return (query(id,rt<<1,l,mid,L,mid)+query(id,rt<<1|1,mid+1,r,mid+1,R))%mod[id];
	}
}

void solve(){
	if(R-L+1==d){
		puts("YES");
		return ;
	}	
	ll ans1=query(0,1,1,n,L,R-d);
	ll ans2=query(0,1,1,n,L+d,R);
	ans1=ans1*base[0][d]%mod[0];
	if(ans1==ans2){
		ans1=query(1,1,1,n,L,R-d);
		ans2=query(1,1,1,n,L+d,R);
		ans1=ans1*base[1][d]%mod[1];
		if(ans1==ans2){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	else{
		puts("NO");
	}
}

void handle(){
	base[0][0]=1;
	base[1][0]=1;
	sum[0][0]=1;
	sum[1][0]=1;
	for(int i=1;i<=n;i++){
		base[0][i]=seed*base[0][i-1]%mod[0];
		base[1][i]=seed*base[1][i-1]%mod[1];
		sum[0][i]=(sum[0][i-1]+base[0][i])%mod[0];
		sum[1][i]=(sum[1][i-1]+base[1][i])%mod[1];
	}
	for(int i=0;i<n;i++){
		res[0][i+1]=base[0][i]*(ull)s[i]%mod[0];
		res[1][i+1]=base[1][i]*(ull)s[i]%mod[1];
	}
	create(1,1,n);
}

int main(void){
	int num,tmp;
	scanf("%d %d %d",&n,&m,&k);
	scanf("%s",s);
	handle();
	num=m+k;
	while(num--){
		scanf("%d",&tmp);
		if(tmp==1){
			scanf("%d %d %s",&L,&R,ch);
			update(1,1,n,L,R,(ll)ch[0]);
		}
		else{
			scanf("%d %d %d",&L,&R,&d);
			solve();
		}
	}
	return 0;
}
