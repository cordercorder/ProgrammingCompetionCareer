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

int problem[15],work[15],value[15];
int n,m,k,r;
int sum;
int dp[15][1510];

void solve(){
    for(int i=0;i<=sum;i++){
        dp[0][i]=inf;
    }
    dp[0][0]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<=sum;j++){
            if(j<value[i]){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-value[i]]+work[i]);
            }
        }
    }
    int mint=inf;
    for(int i=k;i<=sum;i++){
        mint=min(mint,dp[m][i]);
    }
    int res=r-mint,ans=0;
    sort(problem+1,problem+1+n);
    for(int i=1;i<=n;i++){
        if(res>=problem[i]){
            ans++;
            res-=problem[i];
        }
        else
            break;
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d %d %d %d",&n,&m,&k,&r);
    for(int i=1;i<=n;i++)
        scanf("%d",&problem[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&work[i]);
    for(int i=1;i<=m;i++){
        scanf("%d",&value[i]);
        sum+=value[i];
    }
    solve();
    return 0;
}
