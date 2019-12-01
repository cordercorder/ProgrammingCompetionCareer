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

const int maxn=(int)1e5+10;

int n,q,block;
int V[maxn];
vector<int> e[maxn];
int L[maxn],R[maxn],tot,id[maxn],ans[maxn];
int nxt[maxn*32][2],cnt[maxn*32],root[maxn]; 

void dfs(int u){
    L[u]=++tot;
    id[tot]=u;
    int v;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i];
        dfs(v);
    }
    R[u]=tot;
}

int add(int edi,int x){
    int pos=++tot;
    nxt[pos][0]=nxt[edi][0];// copy node
    nxt[pos][1]=nxt[edi][1];
    cnt[pos]=cnt[edi]+1;
    int p=pos,v,ret;
    for(int i=30;i>=0;i--){
        v=(x>>i)&1;
        ++tot;
        ret=nxt[p][v];
        nxt[tot][0]=nxt[ret][0];
        nxt[tot][1]=nxt[ret][1];
        cnt[tot]=cnt[ret]+1;
        nxt[p][v]=tot;
        p=nxt[p][v];
    }
    return pos;
}

int cal(int l,int r,int x){
    int ans=0,v;
    for(int i=30;i>=0;i--){
        v=(x>>i)&1;
        if(cnt[nxt[r][1-v]]-cnt[nxt[l][1-v]]>0){
            ans|=(1<<i);
            l=nxt[l][1-v];
            r=nxt[r][1-v];
        }
        else{
            l=nxt[l][v];
            r=nxt[r][v];
        }
    }
    return ans;
}

int main(void){
    int u,x;
    while(scanf("%d %d",&n,&q)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",&V[i]);
        }
        for(int i=2;i<=n;i++){
            scanf("%d",&u);
            e[u].push_back(i);
        }
        tot=0;
        dfs(1);
        tot=0;
        root[0]=0;
        nxt[0][0]=0;
        nxt[0][1]=0;
        cnt[0]=0;
        for(int i=1;i<=n;i++){
            root[i]=add(root[i-1],V[id[i]]);
        }
        for(int i=1;i<=q;i++){
            scanf("%d %d",&u,&x);
            printf("%d\n",cal(root[L[u]-1],root[R[u]],x));
        }
        for(int i=1;i<=n;i++){
            e[i].clear();
        }
    }
    return 0;
}
