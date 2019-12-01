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

vector<int> e[maxn];
int n,m;
int depth[maxn],pre[maxn];

void pre_handle(int u,int fa){
    depth[u]=depth[fa]+1;
    pre[u]=fa;
    int v;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i];
        pre_handle(v,u);
    }
}

void solve(int u,int v){
    if(depth[u]<depth[v]){
        swap(u,v);
    }
    while(depth[u]>depth[v]){
        u=pre[u];
    }
    while(u!=v){
        u=pre[u];
        v=pre[v];
    }
    printf("%d\n",u);
}

int main(void){
    int u,v;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        e[u].push_back(v);
    }
    scanf("%d",&m);
    depth[0]=0;
    pre_handle(1,0);
    while(m--){
        scanf("%d %d",&u,&v);
        solve(u,v);
    }
    return 0;
}
