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

const int maxn=400;

char s[maxn];
int n,ans;

int handle(int pos){
    int sum=0;
    int i=(pos-1+n)%n;
    char ch=s[i];
    if(ch=='w'){
        while(s[i]=='w'){
            i=(i-1+n)%n;
            sum++;
        }
    }
    ch=s[i];
    while(s[i]==ch|s[i]=='w'){
        i=(i-1+n)%n;
        sum++;
    }
    i=pos;
    ch=s[pos];
    if(ch=='w'){
        while(s[i]=='w'){
            i=(i+1)%n;
            sum++;
        }
    }
    ch=s[i];
    while(s[i]==ch||s[i]=='w'){
        i=(i+1)%n;
        sum++;
    }
    return sum;
}

void solve(){
    ans=0;
    for(int i=0;i<n;){
        int j=i;
        while(j<n&&(s[j]==s[i]||s[j]=='w')){
            j++;
        }
        ans=max(ans,j-i);
        if(j<n){
            ans=max(ans,handle(j));
        }
        i=j;
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d",&n);
    scanf("%s",s);
    solve();
    return 0;
}
