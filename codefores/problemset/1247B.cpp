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

int t;
int n,k,d;
int a[maxn];
int cnt[1000010];

void solve(){
    int ans=n+10,sum=0;
    int i=1;
    for(;i<=d;i++){
        if(cnt[a[i]]==0){
            sum++;
        }
        cnt[a[i]]++;
    }
    ans=min(ans,sum);
    for(;i<=n;i++){
        if(cnt[a[i-d]]==1){
            sum--;
        }
        cnt[a[i-d]]--;
        if(cnt[a[i]]==0){
            sum++;
        }
        cnt[a[i]]++;
        ans=min(ans,sum);
    }
    printf("%d\n",ans);
} 

int main(void){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&k,&d);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        solve();
        for(int i=1;i<=n;i++){
            cnt[a[i]]=0;
        }
    }
    return 0;
}
