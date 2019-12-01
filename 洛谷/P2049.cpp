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

int N,M,K;
int a[maxn][maxn];
bool dp[maxn][maxn][maxn];

void solve(){
    int tmp=1;
    for(int i=1;i<=M;i++){
        tmp=tmp*a[1][i]%K;
        dp[1][i][tmp]=true;
    }
    for(int i=2;i<=N;i++){
        for(int j=1;j<=M;j++){
            for(int k=0;k<K;k++){
                if(dp[i-1][j][k]){
                    dp[i][j][k*a[i][j]%K]=true;
                }
                if(dp[i][j-1][k]){
                    dp[i][j][k*a[i][j]%K]=true;
                }
            }
        }
    }
    vector<int> ans;
    for(int i=0;i<K;i++){
        if(dp[N][M][i]){
            ans.push_back(i);
        }
    }
    printf("%d\n",(int)ans.size());
    for(int i=0;i<(int)ans.size();i++){
        if(i>0)
            printf(" ");
        printf("%d",ans[i]);
    }
}

int main(void){
    scanf("%d %d %d",&N,&M,&K);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++)
            scanf("%d",&a[i][j]);
    }
    solve();
    return 0;
}
