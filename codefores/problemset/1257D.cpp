#include<bits/stdc++.h>

using namespace std;

#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define deb(args...) std::cerr<<"DEBUG------"<<'\n';std::cerr<<#args<<"------>";err(args)

void err(){
    std::cerr<<'\n'<<"END OF DEBUG"<<'\n'<<'\n';
}

template<typename T,typename... Args>
void err(T a,Args... args){
    std::cerr<<a<<", ";
    err(args...);
}

template<template<typename...> class T,typename t,typename... Args>
void err(T<t> a, Args... args){
    for(auto x: a){
        std::cerr<<x<<", ";
    }
    err(args...);
}

const long double PI=acos(-1.0);  
const long double eps=1e-6;

using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

/*head------[@cordercorder]*/

const ll maxn=(ll)2e5+10ll;

ll t,a[maxn],n,m;
ll maxe_m,maxe_h,suf[maxn];

ll st[maxn][25];
ll Log[maxn];

struct node{
    ll p;
    ll s;
}res[maxn];

void ST(){
	Log[0]=-1;
	for(ll i=1;i<=n;i++){
		st[i][0]=a[i];
		Log[i]=Log[i>>1]+1;
	}
	for(ll j=1;(1<<j)<=n;j++){
		for(ll i=1;i+(1<<j)-1<=n;i++){
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
}
ll query(ll L,ll R){
	ll len=R-L+1,k=-1;
	k=Log[len];
	return max(st[L][k],st[R-(1<<k)+1][k]); 
}

bool cmp(const node &a,const node &b){
    return a.s<b.s;
}

bool check(ll id,ll x){
    node now;
    ll tmp=query(id,id+x-1);
    now.s=x;
    ll pos=lower_bound(res+1,res+1+m,now,cmp)-res;
//    deb(id,pos,x,tmp,suf[pos]);
    if(pos==m+1)
        return false;
    if(suf[pos]>=tmp)
        return true;
    return false;
}

void solve(){
    ST();
    sort(res+1,res+1+m,cmp);
    suf[m+1]=0;
    for(ll i=m;i>=1;i--){
        suf[i]=max(suf[i+1],res[i].p);
    }
    ll ans=0;
    for(ll i=1;i<=n;){
        ll l=1,r=n-i+1+1,mid;
        while(l<r){
            mid=(l+r)>>1;
            if(check(i,mid)){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
//        deb('s',l);
        if(!check(i,l))
            l--;
        i+=l;
//        deb('e',l);
        ans++;
    }
    printf("%lld\n",ans);
}

int main(void){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        maxe_m=0;
        maxe_h=0;
        for(ll i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            maxe_m=max(maxe_m,a[i]);
        }
        scanf("%lld",&m);
        for(ll i=1;i<=m;i++){
            scanf("%lld %lld",&res[i].p,&res[i].s);
            maxe_h=max(maxe_h,res[i].p);
        }
        if(maxe_h<maxe_m){
            puts("-1");
            continue;
        }
        solve();
    }
    return 0;
}
