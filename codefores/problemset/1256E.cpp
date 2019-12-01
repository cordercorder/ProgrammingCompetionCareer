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
const ll inf=(ll)1e18;

ll n,ans[maxn],dp[maxn],pre[maxn];
struct node{
    ll x;
    ll id;
}a[maxn];


void solve(){
    sort(a+1,a+1+n,[](const node &a,const node &b)->bool{
        return a.x<b.x;
    });
    for(ll i=0;i<=n;i++){
        pre[i]=-1;
    }
    dp[1]=inf;
    dp[2]=inf;
    dp[3]=a[3].x-a[1].x;
    pre[3]=0;
    ll tmp;
    for(ll i=4;i<=n;i++){
        tmp=inf;
        for(ll j=max(0ll,i-7ll);j<i-2;j++){
            if(dp[j]+a[i].x-a[j+1].x<tmp){
                tmp=dp[j]+a[i].x-a[j+1].x;
                pre[i]=j;
            }
        }
        dp[i]=tmp;
    }
    ll groups=0;
    for(ll i=n;i>=1;){
        groups++;
        for(ll j=i;j>pre[i];j--){
            ans[a[j].id]=groups;
        }
        i=pre[i];
    }
    printf("%lld %lld\n",dp[n],groups);
    for(ll i=1;i<=n;i++){
        if(i>1)
            printf(" ");
        printf("%lld",ans[i]);
    }
}

int main(void){
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i].x);
        a[i].id=i;
    }
    solve();
    return 0;
}
