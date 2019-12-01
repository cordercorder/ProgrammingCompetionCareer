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

const int maxn=(int)1e6+10;

char s[maxn];
int dp[(1<<20)+10];

void solve(){
    int len=strlen(s),status,tmp,cnt;
    for(int i=0;i<len;i++){
        status=0;
        cnt=0;
        for(int j=i;j<len;j++){
            tmp=(int)(s[j]-'a');
            if(status&(1<<tmp)){
                break;
            }
            cnt++;
            status|=(1<<tmp);
            dp[status]=cnt;
        }
    }
    for(int i=0;i<(1<<20);i++){
        for(int j=0;j<20;j++){
            if(i&(1<<j)){
                dp[i]=max(dp[i],dp[i^(1<<j)]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<(1<<20);i++){
        ans=max(ans,dp[i]+dp[i^((1<<20)-1)]);
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%s",s);
    solve();
    return 0;
}
