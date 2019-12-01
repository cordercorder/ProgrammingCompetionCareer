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

const ll maxn=1010;
const ll inf=(ll)1e18;

ll N,M,C;
ll a[maxn][maxn],sum[maxn][maxn];

void solve(){
    for(ll i=1;i<=N;i++){
        for(ll j=1;j<=M;j++){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
        }
    }
    ll ans=-inf,tmp;
    ll x=-1,y=-1;
    for(ll i=1;i+C-1<=N;i++){
        for(ll j=1;j+C-1<=M;j++){
            tmp=sum[i+C-1][j+C-1]-sum[i-1][j+C-1]-sum[i+C-1][j-1]+sum[i-1][j-1];
            if(tmp>ans){
                x=i;
                y=j;
                ans=tmp;
            }
        }
    }
    printf("%lld %lld\n",x,y);
}

int main(void){
    scanf("%lld %lld %lld",&N,&M,&C);
    for(ll i=1;i<=N;i++){
        for(ll j=1;j<=M;j++){
            scanf("%lld",&a[i][j]);
        }
    }
    solve();
    return 0;
}
