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
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const ll maxn=2e5+10;

ll n,k;
ll v[maxn];
ll ret;
ll T[maxn<<2];
ll num[maxn],Max;

void create(ll rt,ll l,ll r){
	if(l==r){
		T[rt]=v[l];
		return ;
	}
	ll mid=(l+r)>>1;
	create(rt<<1,l,mid);
	create(rt<<1|1,mid+1,r);
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

void solve(){
	create(1,1,n);
	ll i=k/Max;
	ll block,len,sum;
	for(;i<=n;i++){
		block=n/i;
		len=block*i;
		sum=0;
		for(ll j=1;j<=len;j+=block){
			if(j+block-1>len)
				break;	
			sum+=query(1,1,n,j,j+block-1);
		}
		if(sum>k){
			printf("%lld\n",i);
			return ;
		}
	}
}

int main(void){
	ll sum;
	while(scanf("%lld %lld",&n,&k)!=EOF){
		if(n<0&&k<0)
			break;
		Max=-1;
		sum=0;
		for(ll i=1;i<=n;i++){
			scanf("%lld",&v[i]);
			Max=max(Max,v[i]);
			sum+=v[i];
		}
		if(sum<k){
			puts("-1");
			continue;
		}
		if(k<Max){
			puts("1");
			continue;
		}
		solve(); 	
	}
	return 0;
}
