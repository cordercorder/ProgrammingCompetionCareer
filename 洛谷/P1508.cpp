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

const ll maxn=210;

ll m,n;
ll a[maxn][maxn];
ll f[maxn][maxn];

void solve(){
    for(ll i=1;i<=m;i++){
        for(ll j=1;j<=n;j++){
            f[i][j]=f[i-1][j]+a[i][j];
            if(j>=1){
                f[i][j]=max(f[i-1][j-1]+a[i][j],f[i][j]);
            }
            if(j+1<=n){
                f[i][j]=max(f[i][j],f[i-1][j+1]+a[i][j]);
            }
        }
    }
    ll ans=f[m][(n+1)/2];
    if((n+1)/2-1>=1){
        ans=max(ans,f[m][(n+1)/2-1]);
    }
    if((n+1)/2+1<=n){
        ans=max(ans,f[m][(n+1)/2+1]);
    }
    printf("%lld\n",ans);
}

int main(void){
    scanf("%lld %lld",&m,&n);
    for(ll i=1;i<=m;i++){
        for(ll j=1;j<=n;j++){
            scanf("%lld",&a[i][j]);
        }
    }
    solve();
    return 0;
}
