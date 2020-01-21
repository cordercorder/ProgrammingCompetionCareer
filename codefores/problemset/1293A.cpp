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
const int inf=(int)1e9+10;

int t;
int n,s,k;
int a[maxn];

int cal(){
    int ans=inf;
    for(int i=s,cnt=0;i<=n&&cnt<1001;i++,cnt++){
        if(!binary_search(a+1,a+1+k,i)){
            ans=min(ans,cnt);
            break;
        }
    }
    for(int i=s,cnt=0;i>=1&&cnt<1001;i--,cnt++){
        if(!binary_search(a+1,a+1+k,i)){
            ans=min(ans,cnt);
            break;
        }
    }
    return ans;
}

int main(void){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&s,&k);
        for(int i=1;i<=k;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+1+k);
        printf("%d\n",cal());
    }
    return 0;
}