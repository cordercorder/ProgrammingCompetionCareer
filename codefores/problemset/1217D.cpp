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

const int maxn=5050;

vector<int> e[maxn];
pii edge[maxn];
int n,m;
int in[maxn];

void solve(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push(i);
        }
    }
    int now,sum=0,v;
    while(!q.empty()){
        now=q.front();
        q.pop();
        sum++;
        for(int i=0;i<(int)e[now].size();i++){
            v=e[now][i];
            in[v]--;
            if(in[v]==0){
                q.push(v);
            }
        }
    }
    if(sum==n){
        puts("1");
        for(int i=1;i<=m;i++){
            if(i>1)
                printf(" ");
            printf("1");
        }
        return ;
    }
    puts("2");
    for(int i=1;i<=m;i++){
        if(i>1)
            printf(" ");
        if(edge[i].first>edge[i].second){
            printf("1");
        }
        else{
            printf("2");
        }
    }
}

int main(void){
    int u,v;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        edge[i]=pii(u,v);
        e[u].push_back(v);
        e[v].push_back(u);
        in[v]++;
    }
    solve();
    return 0;
}
