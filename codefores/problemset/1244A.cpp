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

int t;
int a,b,c,d,k;

void solve(){
    for(int i=0;i<=k;i++){
        for(int j=0;j<=k-i;j++){
            if(i*c>=a&&j*d>=b){
                printf("%d %d\n",i,j);
                return ;
            }
        }
    }
    puts("-1");
}

int main(void){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
        solve();
    }
    return 0;
}
