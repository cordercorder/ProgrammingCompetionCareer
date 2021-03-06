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

char s[110];

void solve(){
    int ans=0,len=strlen(s),sum=0,i;
    for(i=0;i<len;i+=2){
        ans++;
    }
//    deb(i,len);
    if(i==len+1){
        ans--;
        for(i=1;i<len;i++){
            if(s[i]=='1'){
                ans++;
                break;
            }
        }
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%s",s);
    solve();
    return 0;
}
