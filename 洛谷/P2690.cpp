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

const int maxn=3010;
const int inf=(int)1e9;

int T,W;
int a[maxn];
int f[maxn][35][2];

void solve(){
    f[0][0][1]=-inf;
    for(int i=1;i<=T;i++){
        for(int j=0;j<=W;j++){
            for(int k=0;k<2;k++){
                f[i][j][k]=f[i-1][j][k]+(a[i]==(k+1));
                if(j>=1){
                    f[i][j][k]=max(f[i][j][k],f[i-1][j-1][1-k]+(a[i]==(k+1)));
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<=W;i++){
        for(int j=0;j<2;j++){
            ans=max(ans,f[T][i][j]);
        }
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d %d",&T,&W);
    for(int i=1;i<=T;i++){
        scanf("%d",&a[i]);
    }
    solve();
    return 0;
}
