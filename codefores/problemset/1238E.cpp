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

const int maxn=(int)1e5+10;
const int inf=(int)1e9;

int n,m;
char s[maxn];
int cost[25][25];
int dp[(1<<20)+10];

int cal(int x){
    int ans=0;
    while(x>0){
        if(x&1)
            ans++;
        x>>=1;
    }
    return ans;
}

void solve(){
    for(int i=0;i+1<n;i++){
        if(s[i+1]!=s[i]){
            cost[s[i+1]-'a'][s[i]-'a']++;
            cost[s[i]-'a'][s[i+1]-'a']++;
        }
    }
    for(int i=0;i<(1<<m);i++){
        dp[i]=inf;
    }
    dp[0]=0;
    for(int i=0;i<(1<<m);i++){
        int cnt=cal(i);
        for(int j=0;j<m;j++){
            if((i&(1<<j))==0){
                int tmp=dp[i];
                for(int k=0;k<m;k++){
                    if((i&(1<<k))>0){
                        tmp+=cost[j][k]*cnt;
                    }
                    else{
                        tmp-=cost[j][k]*cnt;
                    }
                }
                dp[i|(1<<j)]=min(dp[i|(1<<j)],tmp);
            }
        }
    }
    printf("%d\n",dp[(1<<m)-1]);
}

int main(void){
    scanf("%d %d",&n,&m);
    scanf("%s",s);
    solve();
    return 0;
}
