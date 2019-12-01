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

ll n,m,q;
ll sx,sy,ex,ey;
ll k1,k2;

void pre_handle(){
    k1=n,k2=m;
    ll tmp=__gcd(n,m);
    k1/=tmp;
    k2/=tmp;
}

void solve(){
    sy--;
    ey--;
    if(sy/k1==ey/k2){
        puts("YES");
    }
    else{
        puts("NO");
    }
}

void solve1(){
    sy--;
    ey--;
    if(sx==1&&ex==1){
        if(sy/k1==ey/k1){
            puts("YES");
        }
        else{
            puts("NO");
        }
    }
    else{
        if(sy/k2==ey/k2){
            puts("YES");
        }
        else{
            puts("NO");
        }
    }
}

int main(void){
    scanf("%lld %lld %lld",&n,&m,&q);
    pre_handle();
    while(q--){
        scanf("%lld %lld %lld %lld",&sx,&sy,&ex,&ey);
        if(sx==1&&ex==2){
            solve();
        }
        else if(sx==2&&ex==1){
            swap(sy,ey);
            solve();
        }
        else{
            solve1();
        }
    }
    return 0;
}
