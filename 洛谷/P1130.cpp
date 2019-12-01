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

const ll maxn=2010;

ll N,M;
ll ma[maxn][maxn],dp[maxn][maxn];

void solve(){
    for(ll i=0;i<M;i++)
        dp[i][0]=ma[i][0];
    for(ll j=1;j<N;j++){
        for(ll i=0;i<M;i++){
            dp[i][j]=min(dp[(i-1+M)%M][(j-1+N)%N],dp[i][(j-1+N)%N])+ma[i][j];
        }
    }
    ll mine=0;
    for(ll i=0;i<M;i++)
        if(dp[i][N-1]<dp[mine][N-1])
            mine=i;
    printf("%lld\n",dp[mine][N-1]);
}

int main(void){
    scanf("%lld %lld",&N,&M);
    for(ll i=0;i<M;i++){
        for(ll j=0;j<N;j++)
            scanf("%lld",&ma[i][j]);
    }
    solve();
    return 0;
}
