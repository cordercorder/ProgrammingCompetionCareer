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

const int maxn=(int)2e5+10;

int q;
vector<int> e[maxn];
int n,p[maxn],ans[maxn];
bool isv[maxn];
vector<int> rev;

void dfs(int u){
    isv[u]=true;
    rev.push_back(u);
    for(int v:e[u]){
        if(!isv[v]){
            dfs(v);
        }
    }
}

void solve(){
    for(int i=1;i<=n;i++){
        if(!isv[i]){
            dfs(i);
            for(int v:rev){
                ans[v]=(int)rev.size();
            }
            rev.clear();
        }
    }
    for(int i=1;i<=n;i++){
        if(i>1){
            printf(" ");
        }
        printf("%d",ans[i]);
    }
    puts("");
}

int main(void){
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&p[i]);
            e[i].push_back(p[i]);
        }
        solve();
        for(int i=1;i<=n;i++){
            e[i].clear();
            isv[i]=false;
        }
    }
    return 0;
}
