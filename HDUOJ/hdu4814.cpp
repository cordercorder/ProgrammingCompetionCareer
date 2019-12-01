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

int bit[110];
int n;

void solve(){
    bit[50]=n;
    bool f=true;
    int L,R,tmp;
    while(f){
        f=false;
        for(int i=50;i<=100;i++){
            if(bit[i]>=2){
                bit[i+1]+=bit[i]/2;
                bit[i-2]+=bit[i]/2;
                bit[i]%=2;
                f=true;
            }
        }
        for(int i=49;i>=2;i--){
            if(bit[i]>=2){
                bit[i+1]+=bit[i]/2;
                bit[i-2]+=bit[i]/2;
                bit[i]%=2;
                f=true;
            }
        }
        for(int i=100;i>=1;i--){
            if(bit[i]>=1&&bit[i-1]>=1){
                tmp=min(bit[i],bit[i-1]);
                bit[i+1]+=tmp;
                bit[i]-=tmp;
                bit[i-1]-=tmp;
                f=true;
            }
        }
    }
    for(L=100;bit[L]==0;L--);
    for(R=0;bit[R]==0;R++);
    for(int i=L;i>=50;i--){
        printf("%d",bit[i]);
    }
    if(R<50){
        printf(".");
        for(int i=49;i>=R;i--){
            printf("%d",bit[i]);
        }
    }
    puts("");
}

int main(void){
    while(scanf("%d",&n)!=EOF){
        solve();
        memset(bit,0,sizeof(bit));
    }
    return 0;
}
