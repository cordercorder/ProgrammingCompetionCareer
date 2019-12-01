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

int v,n,c;
int k[maxn],m[maxn];
int f[10010];

void solve(){
    for(int i=1;i<=n;i++){
        for(int j=c;j>=m[i];j--){
            f[j]=max(f[j],f[j-m[i]]+k[i]);
        }
    }
    for(int i=0;i<=c;i++){
        if(f[i]>=v){
            printf("%d\n",c-i);
            return ;
        }
    }
    puts("Impossible");
}

int main(void){
    scanf("%d %d %d",&v,&n,&c);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&k[i],&m[i]);
    }
    solve();
    return 0;
}
