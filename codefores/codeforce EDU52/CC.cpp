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
typedef pair<ll,ll> pii;
/*head------[@cordercorder]*/

const ll maxn=2e5+10;

ll n,k;
ll num[maxn],T[maxn<<2],add[maxn<<2];
ll Max,Min;

void pushdown(ll rt,ll l,ll r){
	if(add[rt]){
		ll mid=(l+r)>>1;
		T[rt<<1]+=(mid-l+1)*add[rt];
		T[rt<<1|1]+=(r-mid)*add[rt];
		add[rt<<1]+=add[rt];
		add[rt<<1|1]+=add[rt];
		add[rt]=0; 
	}
}

void update(ll rt,ll l,ll r,ll L,ll R,ll val){
	if(l==L&&R==r){
		T[rt]+=(r-l+1)*val;
		add[rt]+=val;
		return ;
	}
	pushdown(rt,l,r);
	ll mid=(l+r)>>1;
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
	T[rt]=T[rt<<1]+T[rt<<1|1];
}


ll query(ll rt,ll l,ll r,ll L,ll R){
	if(l==L&&R==r){
		return T[rt];
	}
	pushdown(rt,l,r);
	ll mid=(l+r)>>1;
	if(R<=mid){
		return query(rt<<1,l,mid,L,R);
	}
	else if(L>mid){
		return query(rt<<1|1,mid+1,r,L,R);
	}
	else{
		return query(rt<<1,l,mid,L,mid)+query(rt<<1|1,mid+1,r,mid+1,R);
	}
}

ll cal(ll R){
	ll l=Min+1,r=R,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(query(1,1,maxn,mid,R)>k){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	if(query(1,1,maxn,l,R)>k)
		l--;
	return l;
}

void solve(){
	ll pos=Max;
	ll ans=0;
	while(1){
		if(pos<Min+1)
			break;
		pos=cal(pos);
		pos--;
		ans++;
	}
	cout<<ans<<'\n';
}

int main(void){
	FC;
	ll tmp;
	cin>>n>>k;
	Max=0;
	Min=(ll)(2e5+10);
	for(ll i=1;i<=n;i++){
		cin>>tmp;
		Max=max(Max,tmp);
		Min=min(Min,tmp);
		update(1,1,maxn,1,tmp,1);
	}
	solve();
	return 0;
}
