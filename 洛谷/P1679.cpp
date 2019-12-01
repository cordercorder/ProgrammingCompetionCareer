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

const int inf=(int)1e9;

int m;
int dp[100010];

void solve(){
    vector<int> pre;
    for(int i=1;i*i*i*i<=m;i++){
        pre.push_back(i*i*i*i);
    }
    for(int i=0;i<=m;i++)
        dp[i]=inf;
    dp[0]=0;
    for(int i=0;i<(int)pre.size();i++){
        for(int j=pre[i];j<=m;j++){
            dp[j]=min(dp[j],dp[j-pre[i]]+1);
        }
    }
    printf("%d\n",dp[m]);
}

int main(void){
    scanf("%d",&m);
    solve();
    return 0;
}
