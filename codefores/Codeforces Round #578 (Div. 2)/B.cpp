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

const int maxn=110;

int t;
int n,m,k;
int h[maxn]; 

void solve(){
    int tmp,res=m;
    for(int i=1;i<n;i++){
        if(abs(h[i]-h[i+1])<=k){
            tmp=h[i+1]-k;
            tmp=max(tmp,0);
            res+=h[i]-tmp;
        }
        else{
            if(h[i]<h[i+1]){
                tmp=h[i+1]-k;
                if(h[i]+res>=tmp){
                    res-=(tmp-h[i]);
                }
                else{
                    puts("NO");
                    return ;
                }
            }
            else{
                tmp=h[i+1]-k;
                tmp=max(tmp,0);
                res+=h[i]-tmp;
            }
        }
    }
    puts("YES");
}

int main(void){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&m,&k);
        for(int i=1;i<=n;i++){
            scanf("%d",&h[i]);
        }
        solve();
    }
    return 0;
}
