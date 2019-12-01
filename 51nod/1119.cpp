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

const ll maxn=(ll)1e6+10ll;
const ll mod=(ll)1e9+7ll;

ll f[maxn*2];
ll m,n;

ll q_mod(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1){
            ans=ans*a%mod;
        }
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}

void pre_handle(){
    f[0]=1;
    for(int i=1;i<=2000000;i++){
        f[i]=f[i-1]*i%mod;
    }
}

ll inv(ll x){
    return q_mod(x,mod-2);
}

ll C(ll N,ll M){
    ll res=f[N];
    ll res2=f[N-M],res3=f[M];
    ll ans=res*inv(res2)%mod*inv(res3)%mod;
    return ans;
}

void solve(){
    pre_handle();
    printf("%lld\n",C(n-1+m-1,n-1));
}

int main(void){
    scanf("%lld %lld",&m,&n);
    solve();
    return 0;
}
