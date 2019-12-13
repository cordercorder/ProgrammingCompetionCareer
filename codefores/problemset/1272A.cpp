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

ll q;
ll a[3];
ll ans=0;

void dfs(ll pos){
    if(pos==3){
        ll sum=0;
        for(ll i=0;i<3;i++){
            for(ll j=i+1;j<3;j++){
                sum+=abs(a[j]-a[i]);
            }
        }
        ans=min(ans,sum);
        return ;
    }
    dfs(pos+1);
    ll tmp=a[pos];
    a[pos]=tmp+1;
    dfs(pos+1);
    a[pos]=tmp-1;
    dfs(pos+1);
    a[pos]=tmp;
}

int main(void){
    scanf("%lld",&q);
    while(q--){
        for(ll i=0;i<3;i++){
            scanf("%lld",&a[i]);
        }
        ans=(ll)1e18;
        dfs(0);
        printf("%lld\n",ans);
    }
    return 0;
}