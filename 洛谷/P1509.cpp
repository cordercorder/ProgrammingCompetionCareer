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

int n;
int m,r;
int rmb[maxn],rp[maxn],t[maxn];
int f[maxn][maxn],g[maxn][maxn];

void solve(){
    for(int i=1;i<=n;i++){
        for(int j=m;j>=rmb[i];j--){
            for(int k=r;k>=rp[i];k--){
                if(f[j][k]<f[j-rmb[i]][k-rp[i]]+1){
                    f[j][k]=f[j-rmb[i]][k-rp[i]]+1;
                    g[j][k]=g[j-rmb[i]][k-rp[i]]+t[i];
                }
                else if(f[j][k]==f[j-rmb[i]][k-rp[i]]+1){
                    g[j][k]=min(g[j][k],g[j-rmb[i]][k-rp[i]]+t[i]);
                }
            }
        }
    }
    printf("%d\n",g[m][r]);
}

int main(void){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&rmb[i],&rp[i],&t[i]);
    }
    scanf("%d %d",&m,&r);
    solve();
    return 0;
}
