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

int m[maxn],t[maxn];
int n,M,T;
int dp[210][210];

void solve(){
    for(int i=1;i<=n;i++){
        for(int j=M;j>=m[i];j--){
            for(int k=T;k>=t[i];k--){
                if(dp[j-m[i]][k-t[i]]+1>dp[j][k]){
                    dp[j][k]=dp[j-m[i]][k-t[i]]+1;
                }
            }
        }
    }
    printf("%d\n",dp[M][T]);
}

int main(void){
    scanf("%d %d %d",&n,&M,&T);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&m[i],&t[i]);
    }
    solve();
    return 0;
}
