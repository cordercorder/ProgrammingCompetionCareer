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

const int maxn=(int)1e6+10;

int h[maxn],n;
int dp[maxn];

void solve(){
    for(int i=1;i<=n+2;i++){
        if(i==1){
            dp[i]=dp[i-1]+h[i];
        }
        else if(i==2){
            dp[i]=dp[i-1]+h[i];
            dp[i]=min(dp[i],dp[i-2]+h[i]);
        }
        else{
            dp[i]=dp[i-1]+h[i];
            dp[i]=min(dp[i],dp[i-3]+h[i]);
            dp[i]=min(dp[i],dp[i-2]+h[i]);
        }
    }
    int mine=dp[n];
    for(int i=n+1;i<=n+2;i++)
        mine=min(mine,dp[i]);
    printf("%d\n",mine);
}

int main(void){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&h[i]);
    solve();
    return 0;
}
