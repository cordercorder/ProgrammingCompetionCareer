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

int T,n;
vector<int> e[maxn];
int in[maxn],out[maxn],id[maxn],ans[maxn];
int tot,block;
bool isv[maxn];

struct node{
    int l;
    int r;
    int id;
};

void dfs(int u,int fa){
    int v;
    in[u]=++tot;
    id[tot]=u;
    for(int i=0;i<(int)e[u].size();i++){
        v=e[u][i];
        if(v==fa)
            continue;
        dfs(v,u);
    }
    out[u]=tot;
}

void solve(){
    tot=0;
    dfs(1,0);
    vector<node> Q;
    block=sqrt(n);
    for(int i=1;i<=n;i++){
        Q.push_back({in[i],out[i],i});
        // deb(in[i],out[i]);
    }
    sort(Q.begin(),Q.end(),[](const node &a,const node &b)->bool{
        int x1=a.l/block,x2=b.l/block;
        if(x1<x2)
            return true;
        else if(x1==x2&&a.r<b.r)
            return true;
        return false;
    });
    int L=1,R=0,sum=0,val;
    for(int i=0;i<n;i++){
        while(R<Q[i].r){
            R++;
            val=id[R];
            isv[val]=true;
            if(isv[val-1]&&isv[val+1]){
                sum--;
            }
            else if(!isv[val-1]&&!isv[val+1]){
                sum++;
            }
        }
        while(R>Q[i].r){
            val=id[R];
            isv[val]=false;
            if(isv[val-1]&&isv[val+1]){
                sum++;
            }
            else if(!isv[val-1]&&!isv[val+1]){
                sum--;
            }
            R--;
        }
        while(L<Q[i].l){
            val=id[L];
            isv[val]=false;
            if(isv[val-1]&&isv[val+1]){
                sum++;
            }
            else if(!isv[val-1]&&!isv[val+1]){
                sum--;
            }
            L++;
        }
        while(L>Q[i].l){
            L--;
            val=id[L];
            isv[val]=true;
            if(isv[val-1]&&isv[val+1]){
                sum--;
            }
            else if(!isv[val-1]&&!isv[val+1]){
                sum++;
            }
        }
        ans[Q[i].id]=sum;
    }
    for(int i=1;i<=n;i++){
        if(i>1)
            printf(" ");
        printf("%d",ans[i]);
        isv[i]=false;
        e[i].clear();
    }
    puts("");
}

int main(void){
    int u,v;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++){
        scanf("%d",&n);
        for(int i=1;i<n;i++){
            scanf("%d %d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        printf("Case #%d: ",ca);
        solve();
    }
    return 0;
}
