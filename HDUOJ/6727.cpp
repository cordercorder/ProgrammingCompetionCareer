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

const ll mod=(ll)1e9+7ll;
const ll maxn=(ll)1e5+10ll;
const ll inf=(ll)1e9;

ll T,n;
ll e[maxn][2],mine[maxn],sum[maxn];
ll root,deg[maxn],p[maxn],tot;
ll base[maxn];

void pre_handle(){
    base[0]=1;
    for(int i=1;i<=100000;i++){
        base[i]=base[i-1]*233ll%mod;
    }
}

void pre_dfs(ll u){
    mine[u]=u;
    sum[u]=1;
    if(e[u][0]!=0){
        pre_dfs(e[u][0]);
        mine[u]=min(mine[e[u][0]],mine[u]);
        sum[u]+=sum[e[u][0]];
    }
    if(e[u][1]!=0){
        pre_dfs(e[u][1]);
        mine[u]=min(mine[e[u][1]],mine[u]);
        sum[u]+=sum[e[u][1]];
    }
}

void dfs(ll u){
    if(mine[u]==u){
        if(e[u][0]==0&&e[u][1]==0){
            p[u]=++tot;
        }
        else if(e[u][0]==0){
            p[u]=++tot;
            dfs(e[u][1]);
        }
        else if(e[u][1]==0){
            p[u]=++tot;
            dfs(e[u][0]);
        }
        else{
            int x=e[u][0];
            int y=e[u][1];
            if(sum[x]==sum[y]){
                if(mine[x]>mine[y]){
                    swap(x,y);
                }
                dfs(x);
                p[u]=++tot;
                dfs(y);
            }
            else{
                if(sum[x]>sum[y]){
                    swap(x,y);
                }
                dfs(x);
                p[u]=++tot;
                dfs(y);
            }
        }
    }
    else{
        int x=e[u][0],y=e[u][1];
        if(mine[x]>mine[y]){
            swap(x,y);
        }
        dfs(x);
        p[u]=++tot;
        if(y!=0){
            dfs(y);
        }
    }
}

void solve(){
    mine[0]=inf;
    for(int i=1;i<=n;i++){
        if(deg[i]==0){
            root=i;
            break;
        }
    }
    tot=0;
    pre_dfs(root);
    dfs(root);
//    for(int i=1;i<=n;i++){
//        printf("%lld ",p[i]);
//    }
//    puts("");
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans=(ans+(p[i]^(ll)i)%mod*base[i]%mod)%mod;
    }
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++){
        deg[i]=0;
    }
}

int main(void){
    pre_handle();
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%d %d",&e[i][0],&e[i][1]);
            if(e[i][0]!=0){
                deg[e[i][0]]++;
            }
            if(e[i][1]!=0){
                deg[e[i][1]]++;
            }
        }
        solve();
    }
    return 0;
}
