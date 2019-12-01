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

const int maxn=(int)1e6+10;
const ll mod=998244353ll;

int L,K,len;
char s[maxn];
ll base[maxn];
ll h[maxn];
ll seed=131;
map<ll,bool> isv;

void handle(){
    ll res=0;
    base[0]=1;
    for(int i=1;i<=len;i++){
        base[i]=base[i-1]*seed%mod;
    }
    for(int i=1;i<=len;i++){
        h[i]=base[i]*(ll)s[i]%mod;
    }
}

ll q_mod(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1){
            ans=ans*a%mod;
        }
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}

void solve(){
    ll sum=0,tmp,inv;
    len=strlen(s+1);
    handle();
    int i;
    for(i=1;i<=L&&i<=len;i++){
        sum=(sum+h[i])%mod;
    }
    isv[sum]=true;
    for(;i<=len;i++){
        sum=(sum-h[i-L]+mod)%mod;
        sum=(sum+h[i])%mod;
        tmp=q_mod(seed,i-L);
        inv=q_mod(tmp,mod-2);
        isv[sum*inv%mod]=true;
    }
    printf("%lld\n",(ll)isv.size());
}

int main(void){
    scanf("%d %d",&L,&K);
    scanf("%s",s+1);
    solve();
    return 0;
}
