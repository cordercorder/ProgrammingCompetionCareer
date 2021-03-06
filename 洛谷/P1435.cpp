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

const int maxn=1010;

char s[maxn];

int f[maxn][maxn];

void solve(){
    int len=strlen(s+1);
    for(int i=1;i<=len;i++){
        f[i][i]=1;
    } 
    for(int l=2;l<=len;l++){
        for(int i=1;i+l-1<=len;i++){
            int j=i+l-1;
            if(s[i]==s[j])
                f[i][j]=f[i+1][j-1]+2;
            else
                f[i][j]=max(f[i+1][j],f[i][j-1]);
        }
    }
    printf("%d\n",len-f[1][len]);
}

int main(void){
    scanf("%s",s+1);
    solve();
    return 0;
}
