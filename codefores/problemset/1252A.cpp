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

const int maxn=(int)1e5+10;

int n,ans[maxn];
pii a[maxn];

void solve(){
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        ans[a[i].second]=n-i+1;
    } 
    for(int i=1;i<=n;i++){
        if(i>1)
            printf(" ");
        printf("%d",ans[i]);
    }
}

int main(void){
    
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].first);
        a[i].second=i;
    } 
    solve();
    return 0;
}
