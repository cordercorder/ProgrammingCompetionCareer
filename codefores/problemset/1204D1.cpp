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

const int maxn=2010;

char s[maxn],ans[maxn];

void solve(){
    int cnt=0,sum[2];
    bool f;
    for(int i=1;s[i]!='\0';i++){
        if(s[i]=='0'){
            ans[++cnt]='0';
        }
        else{
            sum[0]=0;
            sum[1]=0;
            f=false;
            for(int j=i+1;s[j]!='\0';j++){
                sum[(int)(s[j]-'0')]++;
                if(sum[0]>sum[1]){
                    f=true;
                    break;
                }
            }
            if(f){
                ans[++cnt]='1';
            }
            else{
                ans[++cnt]='0';
            }
        }
    }
    ans[cnt+1]='\0';
    puts(ans+1);
}

int main(void){
    scanf("%s",s+1); 
    solve();
    return 0;
}
