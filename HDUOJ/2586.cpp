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

const int maxn=(int)4e4+10;

struct node{
    int to;
    int w;
};

vector<node> e[maxn];
int T;
int n,m;
int depth[maxn],pre[maxn],dis[maxn];

void dfs(int u,int fa,int w){
    depth[u]=depth[fa]+1;
    pre[u]=fa;
    dis[u]=w;
    int v,ww;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i].to;
        ww=e[u][i].w;
        if(v!=fa){
            dfs(v,u,ww);
        }
    }
}

int solve(int u,int v){
    if(depth[u]<depth[v]){
        swap(u,v);
    }
    int ans=0;
    while(depth[u]>depth[v]){
        ans+=dis[u];
        u=pre[u];
    }
    while(u!=v){
        ans+=dis[u];
        ans+=dis[v];
        u=pre[u];
        v=pre[v];
    }
    return ans;
}

int main(void){
    int u,v,w;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<n;i++){
            scanf("%d %d %d",&u,&v,&w);
            e[u].push_back({v,w});
            e[v].push_back({u,w});
        }
        depth[0]=0;
        dfs(1,0,0);
        while(m--){
            scanf("%d %d",&u,&v);
            printf("%d\n",solve(u,v));
        }
        for(int i=1;i<=n;i++){
            e[i].clear();
        }
    }
    return 0;
}
