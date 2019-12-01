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

const int maxn=550;

char s[maxn];
int num[30];

void solve(){
    int len=strlen(s+1);
    int lim=(len+1)/2;
    for(int i=1;s[i]!='\0';i++){
        num[(int)(s[i]-'a')]++;
    }
    for(int i=0;i<26;i++){
        if(num[i]>lim){
            puts("Impossible");
            return ;
        }
    }
    puts("Possible");
}

int main(void){
    scanf("%s",s+1);
    solve();
    return 0;
}
