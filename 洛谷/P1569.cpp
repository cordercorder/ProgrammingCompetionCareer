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

const int maxn=1010;
const int inf=(int)1e9;

int a[maxn],n,sum[maxn],f[maxn];

void solve(){
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    if(sum[n]<=0){
        puts("Impossible");
        return ;
    }
    for(int i=1;i<=n;i++){
        f[i]=-inf;
        for(int j=0;j<i;j++){
            if(sum[i]-sum[j]>=0){
                f[i]=max(f[i],f[j]+1);
            }
        }
    }
    printf("%d\n",f[n]);
}

int main(void){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    solve();
    return 0;
}
