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

int n,x;
int lose[maxn],win[maxn],use[maxn];
ll dp[maxn][maxn];

void solve(){
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++)
            dp[i][j]=dp[i-1][j]+lose[i];
        for(int j=use[i];j<=x;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j-use[i]]+win[i]);
        }
    }
    ll ans=dp[n][x]*5ll;
    printf("%lld\n",ans);
}

int main(void){    
    scanf("%d %d",&n,&x);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&lose[i],&win[i],&use[i]);
    }
    solve();
    return 0;
}
