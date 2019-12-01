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

const int maxn=210;

int q,n;
int a[maxn];
int pos;

bool solve(){
    for(int i=pos,j=1;j<n;i++,j++){
        if(a[i%n]+1!=a[(i+1)%n]){
            return false;
        }
    }
    return true;
}

bool solve1(){
    for(int i=pos,j=1;j<n;i--,j++){
        if(a[(i+n)%n]+1!=a[(i-1+n)%n]){
            return false;
        }
    }
    return true;
}

int main(void){
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(a[i]==1){
                pos=i;
            }
        }
        if(solve()||solve1()){
            puts("YES");
        }
        else{
            puts("NO");
        }
    }
    return 0;
}
