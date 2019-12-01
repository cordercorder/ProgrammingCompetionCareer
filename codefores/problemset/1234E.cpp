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

const ll maxn=(ll)2e5+10ll;

ll n,m;
ll x[maxn],f[maxn],sum[maxn];

void add(ll l,ll r,ll val){
    if(l>r){
        return ;
    }
    f[l]+=val;
    f[r+1]-=val;
}

void solve(){
    ll a,b;
    for(int i=1;i<m;i++){
        a=x[i];
        b=x[i+1];
        if(a==b){
            continue;
        }
        if(a>b){
            swap(a,b);
        }
        add(1,a-1,b-a);
        add(a,a,b-1);
        add(a+1,b-1,b-a-1);
        add(b,b,a);
        add(b+1,n,b-a);
    }
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+f[i];
    }
    for(int i=1;i<=n;i++){
        if(i>1){
            printf(" ");
        }
        printf("%lld",sum[i]);
    }
}

int main(void){
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%lld",&x[i]);
    }
    solve();
    return 0;
}
