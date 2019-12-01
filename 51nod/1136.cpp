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

int N;

int phi(int x){
    int ans=x,res=x;
    for(int i=2;i*i<=res;i++){
        if(res%i==0){
            ans=ans/i*(i-1);
            while(res%i==0){
                res/=i;
            }
        }
    }
    if(res>1){
        ans=ans/res*(res-1);
    }
    return ans;
}

int main(void){
    scanf("%d",&N);
    printf("%d\n",phi(N));
    return 0;
}
