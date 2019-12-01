#include<bits/stdc++.h>
 
using namespace std;
 
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define deb(args...) std::cerr<<"DEBUG------"<<'\n';std::cerr<<#args<<"------>";err(args)
#define online

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

ll n,t[maxn],sum[maxn][3];

void solve(){
    for(ll i=1;i<=n;i++){
        sum[i][0]=sum[i-1][0];
        sum[i][1]=sum[i-1][1];
        sum[i][2]=sum[i-1][2];
        if(t[i]>0){
            sum[i][0]++;
        }
        else if(t[i]<0){
            sum[i][1]++;
        }
        else{
            sum[i][2]++;
        }
    }
    ll ans=n+1;
    for(ll i=1;i<n;i++){
        ans=min(ans,sum[n][2]+sum[i][0]+sum[n][1]-sum[i][1]);
    } 
    printf("%lld\n",ans);
}

int main(void){

#ifdef online
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&t[i]);
    }
    solve();
    return 0;
}
