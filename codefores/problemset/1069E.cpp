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

// #define local

const ll maxn=(ll)3e5+10ll;

ll a[maxn],n,sum;

void solve(){
    ll ans=0;
    bool f=true;
    ans+=a[1]/2;
    for(ll i=2;i<=n;i++){
        f=!f;
        if(f){
            ans+=a[i]/2;
        }
        else{
            ans+=(a[i]+1)/2;
        }
    }
    // deb(ans);
    ans=min(ans,sum-ans);
    printf("%lld\n",ans);
}

int main(void){
#ifdef local
    freopen("a.in","r",stdin);
#endif
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    solve();
    return 0;
}