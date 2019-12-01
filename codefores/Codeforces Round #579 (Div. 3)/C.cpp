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

const ll maxn=(ll)4e5+10ll;

ll n,a[maxn];

ll F(ll x){
    ll ans=0ll;
    for(ll i=1;i*i<=x;i++){
        if(x%i==0){
            ans++;
            if(x/i!=i){
                ans++;
            } 
        }
    }
    return ans;
}

void solve(){
    ll tmp=a[1];
    for(ll i=2;i<=n;i++){
        tmp=__gcd(tmp,a[i]);
    }
    printf("%lld\n",F(tmp));
}

int main(void){
    
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    solve();
    return 0;
}
