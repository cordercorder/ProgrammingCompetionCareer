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

int n;

void solve(){
    for(int i=2;i*i<=n;i++){
        if(n%(i*i)==0){
            puts("0");
            return ;
        }
    }
    int tmp=n,ans=0;
    for(int i=2;i*i<=tmp;i++){
        if(tmp%i==0){
            ans++;
            while(tmp%i==0){
                tmp/=i;
            }
        }
    }
    if(tmp!=1){
        ans++;
    }
    if(ans%2==0){
        puts("1");
    }
    else{
        puts("-1");
    }
}

int main(void){
    scanf("%d",&n);
    solve();
    return 0;
}
