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

const int maxn=(int)1e5+10;

int n,m,k;
vector<int> e[maxn];
int d[maxn],w[maxn],dp[maxn][200];

void dfs(int u){
    int v,lim=d[u];
    dp[u][d[u]]=w[u];
    if(d[u]==0){
        lim=k;
    }
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i];
        dfs(v);
        for(int j=1;j<=lim;j++){
            dp[u][j]+=dp[v][j];
        }
    }
}

void dfs2(int u){
    
    int v;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i];
        dfs2(v);
        
    }
}

void solve(){
    dfs(1);
    puts("");
    for(int i=1;i<=k;i++){
        printf("%d ",dp[4][i]);
    }
    puts("");
    for(int i=1;i<=k;i++){
        printf("%d ",dp[2][i]);
    }
    puts("");
    int ans=0;
    for(int i=1;i<=k;i++){
        ans=max(ans,dp[1][i]);
        deb(dp[1][i]);
    }
    printf("%d\n",ans);
}

int main(void){
    int p,v;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=2;i<=n;i++){
        scanf("%d",&p);
        e[p].push_back(i);
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&v);
        scanf("%d %d",&d[v],&w[v]);
    }
    solve();
    return 0;
}
