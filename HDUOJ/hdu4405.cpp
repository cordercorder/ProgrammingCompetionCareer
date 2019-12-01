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

int N,M;
double dp[maxn];
vector<int> e[maxn];
bool isv[maxn];

void dfs(int u,double val){
    isv[u]=true;
    dp[u]=val;
    for(int v:e[u]){
        if(!isv[v]){
            dfs(v,val);
        }
    }
}

void solve(){
    for(int i=0;i<=N+10;i++){
        dp[i]=0;
        isv[i]=false;
    }
    dfs(N,0.0);
    for(int i=N-1;i>=0;i--){
        if(isv[i])
            continue;
        for(int j=i+1;j<=i+6;j++){
            dp[i]+=(dp[j]+1.0)/6.0;
        }
        isv[i]=true;
        dfs(i,dp[i]);
    }
    printf("%.4f\n",dp[0]);
}

int main(void){
    int u,v;
    while(scanf("%d %d",&N,&M)!=EOF){
        if(N==0&&M==0)
            break;
        for(int i=1;i<=M;i++){
            scanf("%d %d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        solve();
        for(int i=1;i<=N;i++){
            e[i].clear();
        }
    }
    return 0;
}
