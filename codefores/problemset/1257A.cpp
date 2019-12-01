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

int arr[maxn];

int t;
int n,x,a,b;

int main(void){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d",&n,&x,&a,&b);
        if(a>b)
            swap(a,b);
        int tmp=a-1+n-b;
        if(x>=tmp){
            printf("%d\n",n-1);
        }
        else{
            printf("%d\n",b-a+x);
        }
    }
    return 0;
}
