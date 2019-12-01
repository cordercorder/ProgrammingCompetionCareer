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
const long long maxw=1e16+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=3e3+10;

ll n,m;
ll a[maxn];
ll p[maxn],c[maxn];
ll T[maxn<<2];
ll dp[maxn][maxn];
ll tmp;

void create(ll rt,ll l,ll r){
	if(l==r){
		T[rt]=a[l];
		return ;
	}
	ll mid=(l+r)>>1;
	create(rt<<1,l,mid);
	create(rt<<1|1,mid+1,r); 
	T[rt]=max(T[rt<<1],T[rt<<1|1]);
}

void update(ll rt,ll l,ll r,ll pos,ll val){
	if(l==r){
		T[rt]+=val;
		return ;
	}
	ll mid=(l+r)>>1;
	if(pos<=mid){
		update(rt<<1,l,mid,pos,val);
	}
	else{
		update(rt<<1|1,mid+1,r,pos,val);
	}
	T[rt]=max(T[rt<<1],T[rt<<1|1]);
}

ll query(ll rt,ll l,ll r,ll L,ll R){
	if(l==L&&R==r){
		return T[rt];
	}
	ll mid=(l+r)>>1;
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

bool check(){
	if(tmp>query(1,1,m-1,1,m-1))
		return 1;
	return 0;
}

ll solve(ll x,ll sum){
	if(check()){
		return 0;
	}
	if(x>n){
		return maxw;
	}
	if(dp[x][sum]>=0){
		return dp[x][sum];
	}
	ll res1,res2;
	tmp++;
	update(1,1,m-1,p[x]-1,-1);
	res1=solve(x+1,sum+1)+c[x];
	update(1,1,m-1,p[x]-1,1);
	tmp--;
	res2=solve(x+1,sum);
	return dp[x][sum]=min(res1,res2);
}

int main(void){
	ll pp,cc;
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld %lld",&pp,&cc);
		a[pp]++;
		p[i]=pp;
		c[i]=cc;
	}
	if(m==1){
		puts("0");
		return 0;
	}
	tmp=a[1];
	for(ll i=2;i<=m;i++){
		a[i-1]=a[i];
	}
	memset(dp,-1,sizeof(dp));
	create(1,1,m-1); 
	printf("%lld\n",solve(1,0));	
	return 0;
}
