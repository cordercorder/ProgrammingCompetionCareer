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
ll a,b,n,S;

void solve(){
    ll x=min(a,S/n);
    ll res=S-x*n;
    if(b>=res){
        puts("YES");
    }
    else{
        puts("NO");
    }
}

int main(void){
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld %lld %lld",&a,&b,&n,&S);
        solve();
    }
    return 0;
}
