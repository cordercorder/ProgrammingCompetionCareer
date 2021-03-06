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

const int maxn=25;

int m,n;
int h[maxn];
int f[maxn],g[maxn];

void solve(){
    for(int i=1;i<=n;i++){
        f[i]=1;
        g[i]=1;
        for(int j=1;j<i;j++){
            if(h[j]<=h[i]){
                if(f[j]+1>f[i]){
                    g[i]=g[j];
                    f[i]=f[j]+1;
                }
                else if(f[j]+1==f[i]){
                    g[i]+=g[j];
                }
            }
        }
    }
    int maxe=1;
    for(int i=1;i<=n;i++){
        if(f[i]>=f[maxe]){
            maxe=i;
        }
    }
    printf("%d %d\n",f[maxe],g[maxe]);
}

int main(void){
    scanf("%d",&m);
    while(m--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&h[i]);
        }
        solve();
    }
    return 0;
}
