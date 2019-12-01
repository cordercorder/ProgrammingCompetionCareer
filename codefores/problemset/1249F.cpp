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

const int maxn=210;

vector<int> e[maxn];
int dp[maxn][maxn];
int n,k,a[maxn],tmp[maxn];

void dfs(int u,int fa){
    dp[u][0]=a[u];
    for(int v:e[u]){
        if(v!=fa){
            dfs(v,u);
            for(int i=0;i<=k+1;i++)
                tmp[i]=dp[u][i];
            for(int i=0;i<=k+1;i++){
                for(int j=0;j<=k+1;j++){
                    if(i+j+1<=k)
                        continue;
                    int d=min(i,j+1);
                    tmp[d]=max(tmp[d],dp[u][i]+dp[v][j]);
                }
            }
            for(int i=0;i<=k+1;i++)
                dp[u][i]=tmp[i];
        }
    }
    for(int i=k;i>=0;i--)
        dp[u][i]=max(dp[u][i],dp[u][i+1]);
}

void solve(){
    dfs(1,0);
    printf("%d\n",dp[1][0]);
}

int main(void){
    int u,v;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    solve();
    return 0;
}
