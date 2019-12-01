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
using pii=pair<ll,ll>;

/*head------[@cordercorder]*/

const ll maxn=(ll)5e4+10ll;
const ll mod=1000000007ll;

ll A[maxn],n,B[maxn];

ll len[maxn<<2],num[maxn<<2];
ll f[maxn],g[maxn];

void pushup(ll rt){
    len[rt]=max(len[rt<<1],len[rt<<1|1]);
    num[rt]=0;
    if(len[rt]==len[rt<<1]){
        num[rt]=(num[rt]+num[rt<<1])%mod;
    }
    if(len[rt]==len[rt<<1|1]){
        num[rt]=(num[rt]+num[rt<<1|1])%mod;
    }
}

void create(ll rt,ll l,ll r){
    if(l==r){
        num[rt]=1;
        return ;
    }
    ll mid=(l+r)>>1;
    create(rt<<1,l,mid);
    create(rt<<1|1,mid+1,r);
    pushup(rt);
}

void print(ll rt,ll l,ll r,ll pos){
    if(l==r){
        printf("%lld ",len[rt]);
        return ;
    }
    ll mid=(l+r)>>1;
    if(pos<=mid)
        print(rt<<1,l,mid,pos);
    else
        print(rt<<1|1,mid+1,r,pos);
}


ll query_max(ll rt,ll l,ll r,ll L,ll R){
    if(l==L&&R==r)
        return len[rt];
    ll mid=(l+r)>>1;
    if(R<=mid)
        return query_max(rt<<1,l,mid,L,R);
    else if(L>mid)
        return query_max(rt<<1|1,mid+1,r,L,R);
    else
        return max(query_max(rt<<1,l,mid,L,mid),query_max(rt<<1|1,mid+1,r,mid+1,R));
}

pii query_num(ll rt,ll l,ll r,ll L,ll R){
    if(l==L&&R==r)
        return pii(len[rt],num[rt]);
    ll mid=(l+r)>>1;
    if(R<=mid)
        return query_num(rt<<1,l,mid,L,R);
    else if(L>mid)
        return query_num(rt<<1|1,mid+1,r,L,R);
    else{
        pii ans=pii(0,0);
        pii tmp1=query_num(rt<<1,l,mid,L,mid);
        pii tmp2=query_num(rt<<1|1,mid+1,r,mid+1,R);
        ans.first=max(tmp1.first,tmp2.first);
        if(ans.first==tmp1.first)
            ans.second=(ans.second+tmp1.second)%mod;
        if(ans.first==tmp2.first)
            ans.second=(ans.second+tmp2.second)%mod;
        return ans;
    }
}

void upd(ll rt,ll l,ll r,ll pos,ll val){
    if(l==r){
        len[rt]=val;
        return ;
    }
    ll mid=(l+r)>>1;
    if(pos<=mid)
        upd(rt<<1,l,mid,pos,val);
    else
        upd(rt<<1|1,mid+1,r,pos,val);
    pushup(rt);
}

void solve(){
    sort(B+1,B+1+n);
    ll cnt=unique(B+1,B+1+n)-B-1;
    ll pos;
    pii tmp;
    create(1,1,n);
    for(ll i=1;i<=n;i++){
        pos=lower_bound(B+1,B+1+cnt,A[i])-B;
        f[i]=1;
        g[i]=1;
        if(pos-1<1){
            upd(1,1,n,pos,1);
            continue;
        }
        tmp=query_num(1,1,n,1,pos-1);
        f[i]=tmp.first+1;
        if(tmp.first==0)
            g[i]=1;
        else
            g[i]=tmp.second;
        upd(1,1,n,pos,f[i]);
        print(1,1,n,1);
        print(1,1,n,2);
        print(1,1,n,3);
        puts("");
        deb(tmp.second);
    }
    ll maxe=1,ans=0;
    for(ll i=1;i<=n;i++){
        if(f[maxe]<f[i])
            maxe=i;
    }
    for(ll i=1;i<=n;i++){
        printf("%lld ",g[i]);
    }
    puts("");
    for(ll i=1;i<=n;i++){
        printf("%lld ",f[i]);
    }
    puts("");
    
    maxe=f[maxe];
    for(ll i=1;i<=n;i++){
        if(f[i]==maxe){
            ans=(ans+g[i])%mod;
        }
    }
    printf("%lld\n",ans);
}

int main(void){
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&A[i]);
        B[i]=A[i];
    }
    solve();
    return 0;
}
