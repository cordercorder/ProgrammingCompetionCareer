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
using pii=pair<ll,ll>;
 
/*head------[@cordercorder]*/

const int maxn=(int)1e3+10;

ll a[maxn],n;
pii p[maxn];
ll id[maxn];

void solve(){
    sort(p+1,p+1+n,greater<pii>());
    ll sum=0;
    for(ll i=1;i<=n;i++){
        sum=sum+p[i].first*(i-1ll)+1ll;
        id[i]=p[i].second;
    }
    printf("%lld\n",sum);
    for(ll i=1;i<=n;i++){
        if(i>1){
            printf(" ");
        }
        printf("%lld",id[i]);
    }
}

int main(void){
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        p[i].first=a[i];
        p[i].second=i;
    }
    solve();
    return 0;
}
