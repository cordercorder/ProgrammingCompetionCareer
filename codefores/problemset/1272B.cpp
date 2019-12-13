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

const int maxn=(int)1e5+10;

char s[maxn];
int q;

void solve(){
    int sum[4]={0,0,0,0};
    for(int i=1;s[i]!='\0';i++){
        if(s[i]=='L'){
            sum[0]++;
        }
        else if(s[i]=='R'){
            sum[1]++;
        }
        else if(s[i]=='U'){
            sum[2]++;
        }
        else{
            sum[3]++;
        }
    }
    // for(int i=0;i<4;i++){
    //     printf("%d ",sum[i]);
    // }
    // puts("");
    int cnt=0;
    for(int i=0;i<4;i++){
        if(sum[i]==0){
            cnt++;
        }
    }
    if(cnt>0){
        if(sum[0]>0&&sum[1]>0){
            puts("2");
            puts("LR");
        }
        else if(sum[2]>0&&sum[3]>0){
            puts("2");
            puts("UD");
        }
        else{
            puts("0");
        }
    }
    else{
        int tmp1=min(sum[0],sum[1]);
        int tmp2=min(sum[2],sum[3]);
        int ans=(tmp1+tmp2)*2;
        printf("%d\n",ans);
        for(int i=0;i<tmp1;i++){
            printf("R");
        }
        for(int i=0;i<tmp2;i++){
            printf("D");
        }
        for(int i=0;i<tmp1;i++){
            printf("L");
        }
        for(int i=0;i<tmp2;i++){
            printf("U");
        }
        puts("");
    }
}

int main(void){
    scanf("%d",&q);
    while(q--){
        scanf("%s",s+1);
        solve();
    }
    return 0;
}