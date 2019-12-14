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

int l[maxn],r[maxn],a[maxn],n;

void solve(){
    int ans=0;
    l[1]=1;
    ans=max(ans,l[1]);
    for(int i=2;i<=n;i++){
        if(a[i]>a[i-1]){
            l[i]=l[i-1]+1;
        }
        else{
            l[i]=1;
        }
        ans=max(ans,l[i]);
    }
    r[n]=1;
    for(int i=n-1;i>=1;i--){
        if(a[i]<a[i+1]){
            r[i]=r[i+1]+1;
        }
        else{
            r[i]=1;
        }
        ans=max(ans,r[i]);
    }
    for(int i=1;i+2<=n;i++){
        if(a[i]<a[i+2]){
            ans=max(ans,l[i]+r[i+2]);
        }
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    solve();
    return 0;
}