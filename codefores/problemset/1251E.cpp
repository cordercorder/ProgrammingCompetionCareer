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

const ll maxn=(ll)2e5+10;

ll t,n;
ll m[maxn],p[maxn],remain[maxn];
vector<ll> res[maxn];

void solve(){
    for(ll i=1;i<=n;i++){
        res[m[i]].push_back(p[i]);
    }
    remain[0]=(ll)res[0].size();
    for(ll i=1;i<=n;i++){
        remain[i]=remain[i-1]+(ll)res[i].size();
    }
    ll cnt=0,ans=0;
    priority_queue<ll,vector<ll>,greater<ll> > q;
    for(ll i=n;i>=1;i--){
        for(ll x:res[i]){
            q.push(x);
        }
        while(remain[i-1]+cnt<i){
            ans+=q.top();
            q.pop();
            cnt++;
        }
    }
    printf("%lld\n",ans);
}

int main(void){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        for(ll i=1;i<=n;i++){
            scanf("%lld %lld",&m[i],&p[i]);
        }
        solve();
        for(ll i=0;i<=n;i++){
            res[i].clear();
        }
    }
    return 0;
}
