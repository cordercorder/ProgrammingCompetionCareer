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

const int maxn=3e4+10;

ll n;
ll a[maxn];
ll q,t;
map<ll,ll> mp;
ll sum[maxn<<2];
ll ans[100005];

struct node{
	ll l;
	ll r;
	ll id;
	bool operator<(const node &a)const{
		return r<a.r;
	}
}Q[100005];

void update(ll rt,ll l,ll r,ll pos,ll val){
	if(l==r){
		sum[rt]=val;
		return ;
	}
	ll mid=(l+r)>>1;
	if(pos<=mid){
		update(rt<<1,l,mid,pos,val);
	}
	else{
		update(rt<<1|1,mid+1,r,pos,val);
	}
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

ll query(ll rt,ll l,ll r,ll L,ll R){
	if(l==L&&R==r){
		return sum[rt];
	}
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

void solve(){
	sort(Q+1,Q+1+q);
	ll cnt=1;
	memset(sum,0,sizeof(sum));
	for(ll i=1;i<=q;i++){
		while(cnt<=Q[i].r){
			if(mp[a[cnt]]){
				update(1,1,n,mp[a[cnt]],0);
				mp[a[cnt]]=cnt;
				update(1,1,n,cnt,a[cnt]);
			}
			else{
				mp[a[cnt]]=cnt;
				update(1,1,n,cnt,a[cnt]);
			}
			cnt++;
		}
		ans[Q[i].id]=query(1,1,n,Q[i].l,Q[i].r);
		//deb(Q[i].l);
		//deb(Q[i].r);
		//deb(ans[Q[i].id]);
	}
	for(ll i=1;i<=q;i++){
		printf("%lld\n",ans[i]);
	}
	mp.clear();
}

int main(void){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		scanf("%lld",&q);
		for(ll i=1;i<=q;i++){
			scanf("%lld %lld",&Q[i].l,&Q[i].r);
			Q[i].id=i;
		}
		solve();
	}
	return 0;
}
