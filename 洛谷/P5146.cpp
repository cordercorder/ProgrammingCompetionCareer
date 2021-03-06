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

const ll maxn=(ll)1e6+10ll;

ll A[maxn],n;
ll mine[maxn];

void solve(){
    mine[1]=A[1];
    for(ll i=2;i<=n;i++)
        mine[i]=min(mine[i-1],A[i]);
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ans=max(ans,A[i]-mine[i]);
    }
    printf("%lld\n",ans);
}

int main(void){
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
        scanf("%lld",&A[i]);
    solve();
    return 0;
}
