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

ll f[25*2][25*2],n;

void solve(){
    f[0][0]=1;
    for(ll i=1;i<=2*n;i++){
        for(ll j=0;j<=i&&j<=n;j++){
            if(j-1>=0)
                f[i][j]+=f[i-1][j-1];
            f[i][j]+=f[i-1][j+1];
        }
    }
    printf("%lld\n",f[2*n][0]);
}

int main(void){
    scanf("%lld",&n);
    solve();
    return 0;
}
