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

const int maxn=1010;

int n,m,d;
int c[maxn],sum[maxn];
int pos[maxn],ans[maxn];

void solve(){
    pos[1]=1;
    for(int i=2;i<=m;i++){
        pos[i]=pos[i-1]+c[i-1];
    }
    pos[m+1]=n+1;
    for(int i=m+1;i>1;i--){
        if(pos[i]-(pos[i-1]+c[i-1]-1)>d){
            pos[i-1]=pos[i]-d-c[i-1]+1;
        }
    }
    for(int i=m+1;i>1;i--){
        if(pos[i]-(pos[i-1]+c[i-1]-1)>d){
            puts("NO");
            return ;
        }
    }
    if(pos[1]>d){
        puts("NO");
        return ;
    }
    puts("YES");
    for(int i=1;i<=m;i++){
        for(int j=pos[i];j<=pos[i]+c[i]-1;j++){
            ans[j]=i;
        }
    }
    for(int i=1;i<=n;i++){
        if(i>1)
            printf(" ");
        printf("%d",ans[i]);
    }
}

int main(void){
    scanf("%d %d %d",&n,&m,&d);
    for(int i=1;i<=m;i++){
        scanf("%d",&c[i]);
        sum[i]=sum[i-1]+c[i];
    }
    solve();
    return 0;
}
