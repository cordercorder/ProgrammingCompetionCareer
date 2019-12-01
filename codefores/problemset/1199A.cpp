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

const int maxn=(int)1e5+10; 

int n,x,y;
int a[maxn];

bool check(int pos){
    for(int i=pos-1,j=0;i>=1&&j<x;i--,j++){
        if(a[i]<=a[pos])
            return false;
    }
    for(int i=pos+1,j=0;i<=n&&j<y;i++,j++){
        if(a[i]<=a[pos]){
            return false;
        }
    }
    return true;
}

void solve(){
    for(int i=1;i<=n;i++){
        if(check(i)){
            printf("%d\n",i);
            return ;
        }
    }
}

int main(void){
    scanf("%d %d %d",&n,&x,&y);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    solve();
    return 0;
}
