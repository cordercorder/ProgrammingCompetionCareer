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

const ll maxn=(ll)2e5+10;
const ll inf=(ll)1e18;

struct node{
    ll l;
    ll cost;
};

ll n,k;
char s[maxn];
vector<node> Q[maxn];
ll dp[maxn];
ll T[maxn<<2];

void create(ll rt,ll l,ll r){
    T[rt]=inf;
    if(l==r){
        return ;
    }
    ll mid=(l+r)>>1;
    create(rt<<1,l,mid);
    create(rt<<1|1,mid+1,r);
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
        return min(query(rt<<1,l,mid,L,mid),query(rt<<1|1,mid+1,r,mid+1,R));
    }
}

void update(ll rt,ll l,ll r,ll pos,ll val){
    if(l==r){
        T[rt]=val;
        return ;
    }
    ll mid=(l+r)>>1;
    if(pos<=mid){
        update(rt<<1,l,mid,pos,val);
    }
    else{
        update(rt<<1|1,mid+1,r,pos,val);
    }
    T[rt]=min(T[rt<<1],T[rt<<1|1]);
}

void solve(){
    for(ll i=1;i<=n;i++){
        Q[i].push_back({i,i});
    }
    for(ll i=1;i<=n;i++){
        if(s[i]=='1'){
            Q[min(n,i+k)].push_back({max(1ll,i-k),i});
        }
    }
    create(1,1,n);
    ll l,mine;
    for(ll i=1;i<=n;i++){
        mine=inf;
        for(int j=0;j<(ll)Q[i].size();j++){
            l=Q[i][j].l;
            if(l-1<1){
                mine=min(mine,Q[i][j].cost);
            }
            else{
                mine=min(query(1,1,n,l-1,i-1)+Q[i][j].cost,mine);
            }
        }
        dp[i]=mine;
        update(1,1,n,i,mine);
    }
    printf("%lld\n",dp[n]);
}

int main(void){
    scanf("%lld %lld",&n,&k);
    scanf("%s",s+1);
    solve();
    return 0;
}
