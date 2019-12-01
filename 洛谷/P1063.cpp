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

const ll maxn=110;

ll n,dp[maxn][maxn];
ll a[maxn];

void solve(){
    for(ll len=2;len<=n;len++){
        for(ll i=0;i<n;i++){
            ll j=(i+len-1)%n;
            for(ll k=i;k!=j;k=(k+1)%n){
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[(k+1)%n][j]+a[i]*a[(k+1)%n]*a[(j+1)%n]);
            }
        }
    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        ans=max(ans,dp[i][(i+n-1)%n]);
    }
    printf("%lld\n",ans);
}

int main(void){
    scanf("%lld",&n);
    for(ll i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    solve();
    return 0;
}
