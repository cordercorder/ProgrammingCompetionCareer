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

const int maxn=110;

int n,m;
int a[maxn][maxn],sum[maxn][maxn];

void solve(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
    }
    int ans=0;
    int lim=min(n,m);
    for(int len=1;len<=lim;len++){
        for(int i=1;i+len-1<=n;i++){
            for(int j=1;j+len-1<=m;j++){
                if(sum[i+len-1][j+len-1]-sum[i-1][j+len-1]-sum[i+len-1][j-1]+sum[i-1][j-1]==(len*len)){
                    ans=max(ans,len);
                }
            }
        }
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    }
    solve();
    return 0;
}
