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

int n,c;
int a[maxn],b[maxn];
int t[maxn][2];

void solve(){
    t[1][0]=0;
    t[1][1]=c;
    for(int i=2;i<=n;i++){
        t[i][0]=min(t[i-1][0],t[i-1][1])+a[i-1];
        t[i][1]=min(t[i-1][0]+c,t[i-1][1])+b[i-1];
    }
    for(int i=1;i<=n;i++){
        if(i>1){
            printf(" ");
        }
        printf("%d",min(t[i][0],t[i][1]));
    }
}

int main(void){
    scanf("%d %d",&n,&c);
    for(int i=1;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<n;i++){
        scanf("%d",&b[i]);
    }
    solve();
    return 0;
}
