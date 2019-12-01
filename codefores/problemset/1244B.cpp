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

const int maxn=1010;

int t,n;
char s[maxn];
int ans;
vector<int> e[maxn+maxn];
bool isv[maxn+maxn];
int dp[maxn+maxn];

void dfs(int u,int depth){
    ans=max(ans,depth);
    isv[u]=true;
    for(int v:e[u]){
        if(!isv[v]){
            dfs(v,depth+1);
        }
    }
}

void solve(){
    ans=0;
    for(int i=1;i+1<=n;i++){
        e[i].push_back(i+1);
        e[i+1].push_back(i);
        e[n+i].push_back(n+i+1);
        e[n+i+1].push_back(n+i);
        if(s[i]=='1'){
            e[i].push_back(n+i);
            e[n+i].push_back(i);
        }
    }
    if(s[n]=='1'){
        e[n].push_back(n+n);
        e[n+n].push_back(n);
    }
    for(int i=1;i<=2*n;i++){
        isv[i]=false;
    }
    dfs(1,1);
    for(int i=1;i<=2*n;i++){
        isv[i]=false;
    }
    dfs(2*n,1);
    for(int i=1;i<=2*n;i++){
        e[i].clear();
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",s+1);
        solve();
    }
    return 0;
}
