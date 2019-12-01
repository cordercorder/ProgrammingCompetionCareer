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

const int maxn=110;

int q;
int a[maxn],n;

void solve(){
    sort(a+1,a+1+n);
    bool f=false;
    for(int i=1;i+1<=n;i++){
        if(a[i]+1==a[i+1]){
            f=true;
            break;
        }
    }
    if(f){
        puts("2");
    }
    else{
        puts("1");
    }
}

int main(void){
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        solve();
    }
    return 0;
}
