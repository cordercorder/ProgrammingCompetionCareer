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

const ll maxn=(ll)2e5+10ll;

ll t,n,s;

struct node{
    ll l;
    ll r;
}res[maxn];

bool check(ll x){
    ll sum=0;
    vector<ll> small,large,remain;
    for(ll i=1;i<=n;i++){
        if(res[i].r<x){
            small.push_back(i);
        }
        else if(res[i].l>x){
            large.push_back(i);
        }
        else{
            remain.push_back(i);
        }
    }
    if((ll)small.size()>n/2)
        return false;
    if((ll)large.size()>n/2)
        return true;
    sort(remain.begin(),remain.end(),[](const ll &a,const ll &b)->bool{
        return res[a].l<res[b].l;
    });
    for(ll id:small){
        sum+=res[id].l;
    }
    for(ll id:large){
        sum+=res[id].l;
    }
    ll lim=n/2-(ll)small.size();
    ll i,j;
    for(i=0,j=0;i<(ll)remain.size()&&j<lim;i++,j++){
        sum+=res[remain[i]].l;
    }
    for(;i<(ll)remain.size();i++){
        sum+=x;
    }
    return sum<=s;
}

void solve(){
    ll l=1,r=(ll)1e9+10,mid;
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
    scanf("%lld",&t);
    while(t--){
        scanf("%lld %lld",&n,&s);
        for(ll i=1;i<=n;i++){
            scanf("%lld %lld",&res[i].l,&res[i].r);
        }
        solve();
    }
    return 0;
}
