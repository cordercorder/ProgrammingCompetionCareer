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

int l,r;

bool check(int x){
    int tmp;
    map<int,bool> isv;
    while(x>0){
        tmp=x%10;
        if(isv[tmp]){
            return false;
        }
        else{
            isv[tmp]=true;
        }
        x/=10;
    }
    return true;
}

void solve(){
    for(int i=l;i<=r;i++){
        if(check(i)){
            printf("%d\n",i);
            return ;
        }
    }
    puts("-1");
}

int main(void){
    scanf("%d %d",&l,&r);
    solve();
    return 0;
}
