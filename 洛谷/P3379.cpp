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

const int maxn=(int)5e5+10;

int N,M,S;
vector<int> e[maxn];
int depth[maxn];
int pre[maxn][22];

void dfs(int u,int fa){
    depth[u]=depth[fa]+1;
    pre[u][0]=fa;
    for(int i=1;i<=20;i++){
        pre[u][i]=pre[pre[u][i-1]][i-1];
    }
    int v;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i];
        if(v!=fa){
            dfs(v,u);
        }
    }
}

int solve(int u,int v){
    if(depth[u]<depth[v]){
        swap(u,v);
    }
    for(int i=20;i>=0;i--){
        if(depth[u]-depth[v]>=(1<<i)){
            u=pre[u][i];
        }
    }
    if(u==v){
        return u;
    }
    for(int i=20;i>=0;i--){
        if(pre[u][i]!=pre[v][i]){
            u=pre[u][i];
            v=pre[v][i];
        }
    }
    return pre[u][0];
}

int main(void){
    int u,v;
    scanf("%d %d %d",&N,&M,&S);
    for(int i=1;i<N;i++){
        scanf("%d %d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(S,0);
    while(M--){
        scanf("%d %d",&u,&v);
        printf("%d\n",solve(u,v));
    }
    return 0;
}
