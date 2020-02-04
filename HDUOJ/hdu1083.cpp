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


const int maxn=310;

vector<int> e[maxn];

bool isv[maxn];
int P,N,T;
int link[maxn];

bool dfs(int u){
    for(int v:e[u]){
        if(!isv[v]){
            isv[v]=true;
            if(link[v]==-1||dfs(link[v])){
                link[v]=u;
                return true;
            }
        }
    }
    return false;
}

int main(void){
    int u,k;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&P,&N);
        for(int i=1;i<=P;i++){
            scanf("%d",&k);
            for(int j=0;j<k;j++){
                scanf("%d",&u);
                e[i].push_back(u);
            }
        }
        for(int i=1;i<=N;i++){
            link[i]=-1;
        }
        bool f=true;
        for(int i=1;i<=P&&f;i++){
            for(int j=1;j<=N;j++){
                isv[j]=false;
            }
            if(!dfs(i)){
                f=false;
            }
        }
        if(f){
            puts("YES");
        }
        else{
            puts("NO");
        }
        for(int i=1;i<=P;i++){
            e[i].clear();
        }
    }
    return 0;
}