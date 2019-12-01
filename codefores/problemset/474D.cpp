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

const ll mod=(ll)1e9+7ll;
const ll maxn=(ll)1e5+10;

ll t,k;
ll dp[maxn],sum[maxn];

void solve(){
    dp[0]=1;
    for(ll i=1;i<maxn;i++){
        dp[i]=dp[i-1]+dp[i-k];
        dp[i]%=mod;
    }
    for(ll i=1;i<maxn;i++){
        sum[i]=sum[i-1]+dp[i];
        sum[i]%=mod;
    }
}

int main(void){
    ll a,b;
    scanf("%lld %lld",&t,&k);
    solve();
    while(t--){
        scanf("%lld %lld",&a,&b);
        ll ans=sum[b]-sum[a-1]+mod;
        ans%=mod;
        printf("%lld\n",ans);
    }
    return 0;
}
