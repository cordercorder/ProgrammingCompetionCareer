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

const int maxn=(int)1e5+10;

int l,w;
int a[maxn],sum[maxn];

void solve(){
    int ans=(int)1e9+10;
    for(int i=1;i<w;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=l;i<w;i++){
        ans=min(ans,sum[i]-sum[i-l]);
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d %d",&w,&l);
    for(int i=1;i<w;i++){
        scanf("%d",&a[i]);
    }
    solve();
    return 0;
}
