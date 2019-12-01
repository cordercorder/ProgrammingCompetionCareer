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

const ll maxn=(ll)1e5+10ll;

ll T,n;
vector<ll> e[maxn];
ll l[maxn],r[maxn];
ll dp[maxn][2];

void dfs(ll u,ll fa){
    ll v;
    for(int i=0;i<(ll)e[u].size();i++){
        v=e[u][i];
        if(v!=fa){
            dfs(v,u);
            dp[u][0]+=max(dp[v][0]+abs(l[v]-l[u]),dp[v][1]+abs(r[v]-l[u]));
            dp[u][1]+=max(dp[v][0]+abs(l[v]-r[u]),dp[v][1]+abs(r[v]-r[u]));
        }
    }
}

void solve(){
    dfs(1,0);
    printf("%lld\n",max(dp[1][0],dp[1][1]));
    for(int i=1;i<=n;i++){
        e[i].clear();
        dp[i][0]=0;
        dp[i][1]=0;
    }
}

int main(void){
    ll u,v;
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        for(int i=1;i<n;i++){
            scanf("%lld %lld",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            scanf("%lld %lld",&l[i],&r[i]);
        }
        solve();
    }
    return 0;
}
