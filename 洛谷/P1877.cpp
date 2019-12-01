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

const int maxn=50;
const int inf=1e9;

int beginLevel,maxLevel;
int n,c[55];
bool f[55][1010];

void solve(){
    f[0][beginLevel]=true;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=maxLevel;j++){
            if(j-c[i]>=0){
                f[i][j]|=f[i-1][j-c[i]];
            }
            if(j+c[i]<=maxLevel){
                f[i][j]|=f[i-1][j+c[i]];
            }
        }
    }
    for(int i=maxLevel;i>=0;i--){
        if(f[n][i]){
            printf("%d\n",i);
            return ;
        }
    }
    puts("-1");
}

int main(void){
    scanf("%d %d %d",&n,&beginLevel,&maxLevel);
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    solve();
    return 0;
}
