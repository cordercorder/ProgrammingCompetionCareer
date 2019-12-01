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

int T;
int n,m;
double ans[2];

void solve(){
    if(n==1){
        ans[0]=1.0;
    }
    else{
        ans[0]=0.5;
    }
    ans[1]=(double)m+1.0;
    ans[1]/=(double)m*2.0;
    printf("%.6f %.6f\n",ans[0],ans[1]);
}

int main(void){
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++){
        scanf("%d %d",&n,&m);
        printf("Case #%d: ",ca);
        solve();
    }
    return 0;
}
