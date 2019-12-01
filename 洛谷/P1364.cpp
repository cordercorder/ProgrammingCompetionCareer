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

const ll maxn=110;

vector<ll> e[maxn];
ll n;
ll num[maxn],dp[maxn];
ll sum[maxn],S,ret;

void dfs(ll u,ll pre,ll depth){
    ll v;
    sum[u]=num[u];
    S+=depth*num[u];
    for(ll i=0;i<(ll)e[u].size();i++){
        v=e[u][i];
        if(v==pre)
            continue;
        dfs(v,u,depth+1);
        sum[u]+=sum[v];
    }
}

void dfs2(ll u,ll pre){
    ll v;
    for(ll i=0;i<(ll)e[u].size();i++){
        v=e[u][i];
        if(v==pre)
            continue;
        dp[v]=(dp[u]-sum[v]+ret-sum[v]);
        dfs2(v,u);
    }
} 

void solve(){
    S=0;
    dfs(1,0,0);
    dp[1]=S;
    dfs2(1,0);
    ll id=1;
    for(ll i=1;i<=n;i++){
        if(dp[i]<dp[id]){
            id=i;
        }
    }
    printf("%lld\n",dp[id]);
}

int main(void){
    ll u,v;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&num[i]);
        ret+=num[i];
        scanf("%lld %lld",&u,&v);
        if(u!=0){
            e[i].push_back(u);
            e[u].push_back(i);
        }
        if(v!=0){
            e[i].push_back(v);
            e[v].push_back(i);
        }
    }
    solve();
    return 0;
}
