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

const ll maxn=30;

ll V,N;
ll a[maxn];
ll dp[maxn][10010];

void solve(){
    dp[0][0]=1;
    for(ll i=1;i<=V;i++){
        for(ll j=0;j<=N;j++){
            for(ll k=0;k*a[i]<=j;k++){
                dp[i][j]+=dp[i-1][j-k*a[i]];
            }
        }
    }
    printf("%lld\n",dp[V][N]);
}

int main(void){
    scanf("%lld %lld",&V,&N);
    for(ll i=1;i<=V;i++)
        scanf("%lld",&a[i]);
    solve();
    return 0;
}
