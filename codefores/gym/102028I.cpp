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

const ll maxn=(ll)1e5+10ll;

ll a[maxn],n,sum[maxn],ans[maxn],sumret[maxn];
ll T,ret[maxn];

void solve(){
    ans[1]=0;
    ans[2]=sum[n];
    for(ll i=1;i<=n/2;i++){
        ret[i]=sum[n-i+1]-sum[i];
        sumret[i]=sumret[i-1]+ret[i];
    }
    ll j=1;
    for(ll i=3;i<=n;i++){
        if(i%2==1){
            ans[i]=ans[i-1]+sumret[j];
        }
        else{
            ans[i]=ans[i-1]+sumret[j]+ret[j+1];
            j++;
        }
    }
    for(ll i=1;i<=n;i++){
        if(i>1)
            printf(" ");
        printf("%lld",ans[i]);
    }
    puts("");
}

int main(void){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        sum[1]=0;
        for(ll i=1;i<n;i++){
            scanf("%lld",&a[i]);
            sum[i+1]=sum[i]+a[i];
        }
        solve();
    }
    return 0;
}
