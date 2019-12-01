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

int T; 
int n,m;
char s[1510][15],t[15],len[1510];
int lim;
int dp[20][20];

void solve(){
    int ans=0;
    int l=strlen(t+1);
    for(int i=1;i<=n;i++){
        dp[0][0]=0;
        for(int j=1;j<=len[i];j++){
            dp[j][0]=j;
        }
        for(int j=1;j<=l;j++){
            dp[0][j]=j;
        }
        for(int j=1;j<=len[i];j++){
            for(int k=1;k<=l;k++){
                dp[j][k]=min(dp[j-1][k]+1,dp[j][k-1]+1);
                dp[j][k]=min(dp[j][k],dp[j-1][k-1]+(int)(s[i][j]!=t[k]));
            }
        }
        if(dp[len[i]][l]<=lim){
            ans++;
        }
//        deb(dp[len[i]][l]);
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%s",s[i]+1);
            len[i]=strlen(s[i]+1);
        }
        printf("Case #%d:\n",ca);
        for(int i=1;i<=m;i++){
            scanf("%s %d",t+1,&lim);
            solve();
        }
    }
    return 0;
}
