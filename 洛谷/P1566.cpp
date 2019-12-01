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

const int maxn=35;

int t;
int a[maxn],n;
int f[maxn*1000],maxe;

void solve(){
    memset(f,0,sizeof(f));
    f[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=maxe;j>=a[i];j--)
            f[j]+=f[j-a[i]];
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=f[a[i]];
    }
    sum-=n;
    printf("%d\n",sum);
}

int main(void){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        maxe=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            maxe=max(maxe,a[i]);
        }
        solve();
    }
    return 0;
}
