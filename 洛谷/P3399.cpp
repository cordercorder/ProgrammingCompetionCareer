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

const int maxn=1010;

int N,M;
int D[maxn],C[maxn];
ll dp[maxn][maxn];

void solve(){
    for(int i=1;i<=N;i++){
        for(int j=i;j<=M;j++){
            dp[i-1][j]=min(dp[i-1][j],dp[i-1][j-1]);
        }
        for(int j=i;j<=M;j++){
            dp[i][j]=dp[i-1][j-1]+D[i]*C[j];
        }
    }
    ll ans=(ll)1e18;
    for(int i=N;i<=M;i++){
        ans=min(ans,dp[N][i]);
    }
    printf("%lld\n",ans);
}

int main(void){
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++)
        scanf("%d",&D[i]);
    for(int i=1;i<=M;i++)
        scanf("%d",&C[i]); 
    solve();
    return 0;
}
