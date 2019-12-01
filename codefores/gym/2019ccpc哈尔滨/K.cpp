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

const ll maxn=(ll)1e5+10;

ll T;
ll n,k;
ll w[maxn],sum;

int main(void){
    scanf("%lld",&T);
    while(T--){
        sum=0;
        scanf("%lld %lld",&n,&k);
        for(ll i=1;i<=n;i++){
            scanf("%lld",&w[i]);
            sum+=w[i];
        }
        for(ll i=1;i<=n;i++){
            if(i>1)
                printf(" ");
            printf("%.8f",(double)w[i]+(double)w[i]*k/sum);
        }
        puts("");
    }
    return 0;
}
