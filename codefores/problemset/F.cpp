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

const int maxn=(int)2e5+10;

int n,k;
int p[maxn],q[maxn];
vector<int> e[maxn],g[maxn];
int low[maxn],dfn[maxn],scc,belong[maxn],cnt,deg[maxn],rk[maxn];
bool in[maxn];
stack<int> S;

void tarjan(int u){
    int v;
    low[u]=++cnt;
    dfn[u]=low[u];
    S.push(u);
    in[u]=true;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i];
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(in[v]&&low[u]>dfn[v]){
            low[u]=dfn[v];
        }
    }
    if(low[u]==dfn[u]){
        scc++;
        do{
            v=S.top();
            S.pop();
            in[v]=false;
            belong[v]=scc;
        }while(v!=u);
    }
}

void solve(){
    for(int i=1;i+1<=n;i++){
        e[p[i]].push_back(p[i+1]);
        e[q[i]].push_back(q[i+1]);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    if(scc<k){
        puts("NO");
        return ;
    }
    int v,u,sum=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<(int)e[i].size();j++){
            v=e[i][j];
            if(belong[v]!=belong[i]){
                g[belong[i]].push_back(belong[v]);
                deg[belong[v]]++;
            }
        }
    }
    queue<int> q;
    for(int i=1;i<=scc;i++){
        if(deg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        u=q.front();
        q.pop();
        rk[u]=min(sum,k-1);
        sum++;
        for(int i=0;i<(int)g[u].size();i++){
            v=g[u][i];
            deg[v]--;
            if(deg[v]==0){
                q.push(v);
            }
        }
    }
    puts("YES");
    for(int i=1;i<=n;i++){
        printf("%c",(char)(rk[belong[i]]+'a'));
    }
}

int main(void){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&q[i]);
    }
    solve();
    return 0;
}
