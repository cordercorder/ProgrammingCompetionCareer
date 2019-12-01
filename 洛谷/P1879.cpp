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

const int mod=100000000; 
const int maxn=20;

int ma[maxn][maxn];
int res[maxn];
int m,n;
int dp[maxn][(1<<12)+10];

bool check(int x){
    if((x&(x<<1))>0&&(x&(x>>1))>0){
        return false;
    }
    return true;
}

void solve(){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            res[i]=res[i]*2+ma[i][j];
        }
    }
    dp[0][0]=1;
    for(int i=1;i<=m;i++){
        for(int j=0;j<(1<<n);j++){
            if(check(j)&&(res[i]&j)==j){//j是res[j]的子集 
                for(int k=0;k<(1<<n);k++){
                    if((j&k)==0)
                        dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<(1<<n);i++){
        ans=(ans+dp[m][i])%mod;
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d %d",&m,&n);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&ma[i][j]);
        }
    }
    solve();
    return 0;
}
