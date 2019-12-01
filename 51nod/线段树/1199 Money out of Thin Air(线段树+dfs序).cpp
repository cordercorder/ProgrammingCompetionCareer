# include<iostream>
# include<algorithm>
# include<cstring>
# include<string>
# include<cmath>
# include<queue>
# include<stack>
# include<set>
# include<vector>
# include<cstdio>
# include<cstdlib>
# include<map>
# include<deque>
# include<limits.h>
# include<ctime>

# define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

const int maxn=5e4+10;

vector<ll> p[maxn];

ll m,n;
ll t[maxn<<2],add[maxn<<2];
ll st[maxn],ed[maxn],cnt;
ll w[maxn];
ll num[maxn];
ll pre[maxn];

void dfs(ll id){
	st[id]=++cnt;
	pre[cnt]=id;
	ll u;
	for(ll i=0;i<(ll)p[id].size();i++){
		u=p[id][i];
		dfs(u);
	}
	ed[id]=cnt;
}

void create(ll rt,ll l,ll r){
	add[rt]=0;
	if(l==r){
		t[rt]=num[l];
		return ;
	}
	ll mid=(l+r)>>1;
	create(rt<<1,l,mid);
	create(rt<<1|1,mid+1,r);
	t[rt]=t[rt<<1]+t[rt<<1|1];
}

void pushdown(ll rt,ll llen,ll rlen){
	if(add[rt]){
		t[rt<<1]+=add[rt]*llen;
		t[rt<<1|1]+=add[rt]*rlen;
		add[rt<<1]+=add[rt];
		add[rt<<1|1]+=add[rt];
		add[rt]=0;
	}
}

void update(ll rt,ll l,ll r,ll L,ll R,ll val){
	if(l==L&&R==r){
		t[rt]+=(r-l+1)*val;
		add[rt]+=val;
		return ;
	}
	ll mid=(l+r)>>1;
	pushdown(rt,mid-l+1,r-mid);
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
	t[rt]=t[rt<<1]+t[rt<<1|1];
}

ll query(ll rt,ll l,ll r,ll L,ll R){
	if(l==L&&R==r){
		return t[rt];
	}
	ll mid=(l+r)>>1;
	pushdown(rt,mid-l+1,r-mid);
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

void handle(ll rt,ll l,ll r){
	if(l==r){
		w[pre[l]]=t[rt];
		return ;
	}
	ll mid=(l+r)>>1;
	pushdown(rt,mid-l+1,r-mid);
	handle(rt<<1,l,mid);
	handle(rt<<1|1,mid+1,r);
}

int main(void){
	ll f,tmp;
	ll x,y,z;
	char s[5];
	while(scanf("%lld %lld",&n,&m)!=EOF){
		w[0]=0;
		for(ll i=1;i<n;i++){
			scanf("%lld %lld",&f,&tmp);
			p[f].push_back(i);
			w[i]=tmp;
		}
		cnt=0;
		dfs(0);
		for(ll i=0;i<n;i++){
			num[st[i]]=w[i];
		}
		create(1,1,n);
		while(m--){
			scanf("%s %lld %lld %lld",s,&x,&y,&z);
			if(s[0]=='S'){
				tmp=query(1,1,n,st[x],st[x]);
				if(tmp<y)
					update(1,1,n,st[x],st[x],z);
			}
			else{
				//deb(st[x]);
				//deb(ed[x]);
				tmp=query(1,1,n,st[x],ed[x]);
				if(tmp<y*(ed[x]-st[x]+1)){
					update(1,1,n,st[x],ed[x],z);
				}
				//if(tmp<y*((ll)p[x].size()+1)){
				//	update(1,1,n,st[x],ed[x],z);
				//}
			}
		}
		handle(1,1,n);
		for(ll i=0;i<n;i++){
			printf("%lld\n",w[i]);
		}
		for(ll i=0;i<n;i++){
			p[i].clear();
		}
	}
	return 0;
}
