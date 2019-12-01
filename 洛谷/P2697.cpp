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

const int maxn=(int)1e6+10;
const int inf=(int)1e9;

char s[maxn];
int sum[maxn];
int mine[4*maxn],maxe[4*maxn];

void solve(){
    int len=strlen(s+1);
    for(int i=1;i<=len;i++){
        sum[i]=sum[i-1]+(s[i]=='R');
    }
    for(int i=0;i<4*maxn;i++){
        mine[i]=inf;
        maxe[i]=-inf;
    }
    for(int i=0;i<=len;i++){
        mine[maxn+2*sum[i]-i]=min(mine[maxn+2*sum[i]-i],i);
        maxe[maxn+2*sum[i]-i]=max(maxe[maxn+2*sum[i]-i],i);
    }
    int ans=0;
    for(int i=0;i<4*maxn;i++){
        if(mine[i]!=inf){
            ans=max(ans,maxe[i]-mine[i]);
        }
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%s",s+1);
    solve();
    return 0;
}
