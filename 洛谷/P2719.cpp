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

const int maxn=1300;

int n;
double dp[maxn][maxn];

void solve(){
    n/=2;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i<=1&&j<=1){
                dp[i][j]=0;
            }
            else if(i==0||j==0){
                dp[i][j]=1;
            }
            else{
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])*0.5;
            }
        }
    }
    printf("%.4f\n",dp[n][n]);
}

int main(void){
    scanf("%d",&n);
    solve();
    return 0;
}
