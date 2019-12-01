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
const long long maxw=(long long)1e17+(long long)10;
 
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
 
/*head------[@cordercorder]*/

const ll maxn=(ll)2e5+10ll;

ll pre[maxn],cnt[maxn];

struct node{
    ll u;
    ll v;
    ll w;
}edge[maxn];

struct Q{
    ll id;
    ll val;
}q[maxn];

ll ans[maxn],sum;

ll n,m;

ll Find(ll x){
    return pre[x]==0?x:pre[x]=Find(pre[x]);
}

void Union(ll x,ll y){
    ll nx=Find(x),ny=Find(y);
    if(nx!=ny){
        sum-=(cnt[nx]*(cnt[nx]-1)/2ll);
        sum-=(cnt[ny]*(cnt[ny]-1)/2ll);
        pre[nx]=ny;
        cnt[ny]+=cnt[nx];
        sum+=(cnt[ny]*(cnt[ny]-1)/2ll);
        cnt[nx]=0;
    }
}

void solve(){
    sort(q+1,q+1+m,[](const Q &a,const Q &b)->bool{
        return a.val<b.val;
    });
    sort(edge+1,edge+n,[](const node &a,const node &b)->bool{
        return a.w<b.w;
    });
    for(int i=1;i<=n;i++){
        cnt[i]=1;
    }
    int ii=1;
    sum=0;
    for(int i=1;i<=m;i++){
        while(ii<n&&edge[ii].w<=q[i].val){
            Union(edge[ii].u,edge[ii].v);
            ii++;
        }
        ans[q[i].id]=sum;
    }
    for(int i=1;i<=m;i++){
        if(i>1){
            printf(" ");
        }
        printf("%lld",ans[i]);
    }
}

int main(void){
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<n;i++){
        scanf("%lld %lld %lld",&edge[i].u,&edge[i].v,&edge[i].w);
    }
    for(int i=1;i<=m;i++){
        scanf("%lld",&q[i].val);
        q[i].id=i;
    }
    solve();
    return 0;
}
