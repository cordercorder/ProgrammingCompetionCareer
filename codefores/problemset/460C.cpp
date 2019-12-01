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
const ll inf=(ll)1e9+10;

ll n,m,w;
ll a[maxn],deta[maxn];
ll mine;

bool check(ll x){
    for(ll i=0;i<=n+1;i++){
        deta[i]=0;
    }
    ll sum=0,cnt=0;
    for(ll i=1;i<=n;i++){
        sum+=deta[i];
        if(sum+a[i]<x){
            ll tmp=x-(a[i]+sum);
            cnt+=tmp;
            if(cnt>m){
                return false;
            }
            deta[i]+=tmp;
            sum+=tmp;
            deta[min(i+w,n+1)]-=tmp;
        }
    }
    return true;
}

void solve(){
    ll l=mine,r=(ll)1e9+m+10,mid;
    while(l<r){
        mid=(l+r)>>1;
        if(check(mid)){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    printf("%lld\n",l-1);
}

int main(void){
    mine=inf;
    scanf("%lld %lld %lld",&n,&m,&w);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        mine=min(a[i],mine);
    }
    solve();
    return 0;
}
