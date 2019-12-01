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

char s[maxn];
int num[maxn];

void solve(){
    int len=strlen(s);
    for(int i=0;i<len;i++){
        num[i]=(int)(s[i]-'0');
    }
    
    for(int i=0;i<len;i++){
        if(num[i]%8==0){
            puts("YES");
            printf("%d",num[i]);
            return;
        }
        for(int j=i+1;j<len;j++){
            if((num[i]*10+num[j])%8==0){
                puts("YES");
                printf("%d%d",num[i],num[j]);
                return;
            }
            for(int k=j+1;k<len;k++){
                if((num[i]*100+num[j]*10+num[k])%8==0){
                    puts("YES");
                    printf("%d%d%d\n",num[i],num[j],num[k]);
                    return;
                }
            }
        }
    }
    puts("NO");
}

int main(void){
    scanf("%s",s);
    solve();
    return 0;
}
