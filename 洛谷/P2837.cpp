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

const int maxn=30010;

int a[maxn],n;
int dp[maxn][2];

void solve(){
    for(int i=1;i<=n;i++){
        if(a[i]==1){
            dp[i][0]=dp[i-1][0];
            dp[i][1]=min(dp[i-1][0],dp[i-1][1])+1;
        }
        else{
            dp[i][0]=dp[i-1][0]+1;
            dp[i][1]=min(dp[i-1][0],dp[i-1][1]);
        }
    }
    printf("%d\n",min(dp[n][0],dp[n][1]));
}

int main(void){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    solve();
    return 0;
}
