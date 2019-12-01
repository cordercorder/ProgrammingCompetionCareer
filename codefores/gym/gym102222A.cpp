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

const int maxn=(int)5e6+10;

int n,p,q,m;
int T;
int ans[maxn],ca;

unsigned int SA,SB,SC;

unsigned int rng61(){
    SA^=SA<<16;
    SA^=SA>>5;
    SA^=SA<<1;
    unsigned int t=SA;
    SA=SB;
    SB=SC;
    SC^=t^SA;
    return SC;
}

void gen(){
    scanf("%d %d %d %d %u %u %u",&n,&p,&q,&m,&SA,&SB,&SC);
    stack<int> S;
    int tmp,maxe=0;
    ll sum=0;
    for(int i=1;i<=n;i++){
        if(rng61()%(p+q)<p){
            tmp=rng61()%m+1;
            maxe=max(maxe,tmp);
            S.push(maxe);
            ans[i]=maxe;
        }
        else{
            if(S.empty()){
                ans[i]=0;
            }
            else{
                S.pop();
                if(S.empty()){
                    ans[i]=0;
                    maxe=0;
                }
                else{
                    ans[i]=S.top();
                    maxe=S.top();
                }
            }
        }
    }
    sum=ans[1];
    for(int i=2;i<=n;i++){
        sum=sum^((ll)i*(ll)ans[i]);
    }
    printf("Case #%d: ",++ca);
    printf("%lld\n",sum);
}

int main(void){
    scanf("%d",&T);
    while(T--){
        gen();
    }
    return 0;
}
