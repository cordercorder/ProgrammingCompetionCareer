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

const ll mod=9999973ll;
const int maxn=110;

ll dp[maxn][maxn][maxn];

ll N,M;

ll C2(ll x){
    return x*(x-1)/2ll;
}

void solve(){
    dp[0][0][0]=1;
    for(int i=1;i<=N;i++){
        for(int j=0;j<=M;j++){
            for(int k=0;k<=M-j;k++){
                dp[i][j][k]=dp[i-1][j][k];
                if(k>=1){
                    dp[i][j][k]=(dp[i][j][k]+dp[i-1][j+1][k-1]*(j+1)%mod)%mod;
                }
                if(j>=1){
                    dp[i][j][k]=(dp[i][j][k]+dp[i-1][j-1][k]*(M-(j-1)-k)%mod)%mod;
                }
                if(k>=2){
                    dp[i][j][k]=(dp[i][j][k]+dp[i-1][j+2][k-2]*C2(j+2)%mod)%mod;
                }
                if(j>=2){
                    dp[i][j][k]=(dp[i][j][k]+dp[i-1][j-2][k]*C2(M-(j-2)-k)%mod)%mod;
                }
                if(k>=1){
                    dp[i][j][k]=(dp[i][j][k]+dp[i-1][j][k-1]*j*(M-j-(k-1))%mod)%mod;
                }
            }
        }
    }
    ll ans=0;
    for(int i=0;i<=M;i++){
        for(int j=0;j<=M;j++){
            ans=(ans+dp[N][i][j])%mod;
        }
    }
    printf("%lld\n",ans);
}

int main(void){
    scanf("%lld %lld",&N,&M);
    solve();
    return 0;
}
