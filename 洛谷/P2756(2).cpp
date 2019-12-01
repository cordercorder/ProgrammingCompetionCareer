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

const int maxn=110;
const int inf=(int)1e9;

int m,n;
vector<int> e[maxn];
int belong[maxn];
bool isv[maxn];

bool dfs(int u){
    for(int v:e[u]){
        if(!isv[v]){
            isv[v]=true;
            if(belong[v]==-1||dfs(belong[v])){
                belong[v]=u;
                return true;
            }
        }
    }
    return false;
}

void clr(){
    for(int i=1;i<=n;i++){
        isv[i]=false;
    }
}

void solve(){
    int ans=0;
    memset(belong,-1,sizeof(belong));
    for(int i=1;i<=m;i++){
        clr();
        if(dfs(i)){
            ans++;
        }
    }
    if(ans==0){
        puts("No Solution!");
        return ;
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++){
        if(belong[i]!=-1){
            printf("%d %d\n",belong[i],i);
        }
    }
}

int main(void){
    int u,v;
    scanf("%d %d",&m,&n);
    while(scanf("%d %d",&u,&v)&&(u!=-1)&&(v!=-1)){
        e[u].push_back(v);
    }
    solve();
    return 0;
}
