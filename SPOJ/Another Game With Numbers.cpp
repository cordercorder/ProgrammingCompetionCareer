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

const int maxn=20;

ll N,K;
ll a[maxn];

ll lcm(ll a,ll b){
    return a*b/__gcd(a,b);
}

void solve(){
    ll ans=0,res,cnt;
    ll lim=(1<<K);
    for(int i=0;i<lim;i++){
        res=1;
        cnt=0;
        for(int j=0;j<K;j++){
            if((i>>j)&1){
                res=lcm(res,a[j+1]);
                cnt++;
            }
        }
        if(cnt&1){
            ans+=N/res;
        }
        else{
            if(cnt>0)
                ans-=N/res;
        }
    }
    printf("%lld\n",N-ans);
}

int main(void){
    scanf("%lld %lld",&N,&K);
    for(int i=1;i<=K;i++){
        scanf("%lld",&a[i]);
    }
    solve();
    return 0;
}
