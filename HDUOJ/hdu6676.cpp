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

const int maxn=(1<<21)+100;

int T;
char s[maxn];

void solve(){
    int len=strlen(s+1),ret,ans=0;
    for(int i=20;i>=1;i--){
        ret=(1<<i);
        for(int j=1;j<=len;){
            int k=j;
            while(k<=len&&s[k]=='?'){
                k++;
            }
            if(j==k){
                j=k+1;
            }
            else{
                if(k-j>=ret-1){
                    if(j+ret-1==len+1||s[j+ret-1]=='^'){
                        for(int u=j,v=0;v+1<ret;u++,v++){
                            s[u]='+';
                        }
                        ans+=ret;
                        break;
                    }
                    else if(k-j>=ret){
                        for(int u=j,v=0;v+1<ret;u++,v++){
                            s[u]='+';
                        }
                        s[j+ret-1]='^';
                        ans+=ret;
                        break;
                    }
                }
                j=k;
            }
        }
    }
    for(int i=1;i<=len;i++){
        if(s[i]=='?'){
            s[i]='^';
        }
    }
//    puts(s+1);
    int sum=0,tmp;
    for(int i=1;i<=len;){
        int j=i;
        while(j<=len&&s[j]=='^'){
            j++;
        }
        if(j==i){
            i=j+1;
        }
        else{
            tmp=j-i+1;
            if(i!=1){
                tmp--;
            }
            if(j!=len+1){
                tmp--;
            }
            tmp=tmp%2;
            sum^=tmp;
            i=j;
        }
    }
    ans+=sum;
    printf("%d\n",ans);
}

int main(void){
    scanf("%d",&T);
    while(T--){
        scanf("%s",s+1);
        solve();
    }
    return 0;
}
