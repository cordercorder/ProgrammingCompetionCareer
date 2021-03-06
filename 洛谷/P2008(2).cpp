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

const int maxn=(int)1e4+10;
const int inf=1e9;

int f[maxn],g[maxn],a[maxn],pos[15];
int n;

void solve(){
    int ret;
    for(int i=1;i<=n;i++){
        f[i]=1;
        g[i]=a[i];
        for(int j=a[i];j>=0;j--){
            if(pos[j]==0)
                continue;
            if(f[pos[j]]+1>f[i]){
                f[i]=f[pos[j]]+1;
                g[i]=g[pos[j]]+a[i];
            }
        }
        int mine=inf;
        for(int j=a[i];j>=0;j--){
            if(pos[j]==0)
                continue;
            if(f[pos[j]]+1==f[i]){
                mine=min(mine,pos[j]);
            }
        }
        if(mine!=inf){
            g[i]=g[mine]+a[i];
        }
        pos[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(i>1)
            printf(" ");
        printf("%d",g[i]);
    }
}

int main(void){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    solve();
    return 0;
}
