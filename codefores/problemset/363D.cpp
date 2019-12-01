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

ll n,m,a;
ll b[maxn],p[maxn];
ll tmpb[maxn],tmp[maxn];

bool check(ll x){
    if(x>m){
        return false;
    }
    for(ll i=1;i<=x;i++){
        tmpb[i]=b[i];
    }
    ll cnt=0;
    for(ll i=x;i>=1;i--){
        tmp[++cnt]=p[i];
    }
    ll sum=0;
    for(ll i=1;i<=x;i++){
        if(tmp[i]>tmpb[i]){
            sum+=tmp[i]-tmpb[i];
        }
    }
    return sum<=a;
}

void solve(){
    sort(b+1,b+1+n,greater<ll>());
    sort(p+1,p+1+m);
    ll l=0,r=n+1,mid;
    while(l<r){
        mid=(l+r)>>1;
        if(check(mid)){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    ll ans1=l-1,ans2=0;
    for(ll i=1;i<=ans1;i++){
        ans2+=p[i];
    }
    ans2-=a;
    ans2=max(ans2,0ll);
    printf("%lld %lld\n",ans1,ans2);
}

int main(void){
    scanf("%lld %lld %lld",&n,&m,&a);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&b[i]);
    }
    for(ll i=1;i<=m;i++){
        scanf("%lld",&p[i]);
    }
    solve();
    return 0;
}
