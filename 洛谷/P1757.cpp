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

const int maxn=1010;

int m,n;
vector<pii> group[110];
int dp[110][maxn];

void solve(){
    for(int i=1;i<=100;i++){
        for(pii item:group[i]){
            for(int j=0;j<=m;j++){
                if(j<item.first)
                    dp[i][j]=max(dp[i][j],dp[i-1][j]);
                else
                    dp[i][j]=max(max(dp[i][j],dp[i-1][j]),dp[i-1][j-item.first]+item.second);
            }
        }
        if(group[i].empty())
            for(int j=0;j<=m;j++)
                dp[i][j]=dp[i-1][j];
    }
    printf("%d\n",dp[100][m]);
}

int main(void){
    int a,b,c;
    scanf("%d %d",&m,&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&a,&b,&c);
        group[c].push_back(pii(a,b));
    }
    solve();
    return 0;
}
