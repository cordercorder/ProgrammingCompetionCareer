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

const int maxn=(int)2e5+10;

int n,k;
char s[maxn];
bool isv[30];

void solve(){
    ll ans=0;
    for(int i=1;i<=n;){
        int j=i;
        ll len=0;
        while(j<=n&&isv[(int)(s[j])-'a']){
            j++;
            len++;
        }
        if(j==i){
            i=j+1;
        }
        else{
            i=j;
            ans+=len*(len+1)/2;
        }
    }
    printf("%lld\n",ans);
}

int main(void){
    char str[10];
    scanf("%d %d",&n,&k);
    scanf("%s",s+1);
    for(int i=0;i<k;i++){
        scanf("%s",str);
        isv[(int)(str[0]-'a')]=true;
    }
    solve();
    return 0;
}