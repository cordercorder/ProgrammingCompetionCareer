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

ll nb,ns,nc;
ll pb,ps,pc;
ll r;
ll cntb,cnts,cntc;
char s[110];

bool check(ll x){
    ll tmpb,tmps,tmpc;
    tmpb=max(x*cntb-nb,0ll);
    tmps=max(x*cnts-ns,0ll);
    tmpc=max(x*cntc-nc,0ll);
//    deb(tmpb,tmps,tmpc);
    tmpb=tmpb*pb;
    tmps=tmps*ps;
    tmpc=tmpc*pc;
    return (tmpb+tmps+tmpc)<=r;
}

void solve(){
    for(int i=1;s[i]!='\0';i++){
        if(s[i]=='B'){
            cntb++;
        }
        else if(s[i]=='S'){
            cnts++;
        }
        else{
            cntc++;
        }
    }
    ll l=0,r=(ll)1e13,mid;
    while(l<r){
        mid=(l+r)>>1;
        if(check(mid)){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    printf("%lld\n",l-1);
}

int main(void){
    scanf("%s",s+1);
    scanf("%lld %lld %lld",&nb,&ns,&nc);
    scanf("%lld %lld %lld",&pb,&ps,&pc);
    scanf("%lld",&r);    
    solve();
    return 0;
}
