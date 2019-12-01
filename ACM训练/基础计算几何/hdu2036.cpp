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

const ll maxn=310;

struct node{
    ll x;
    ll y;
    node operator-(const node &a)const{
        node ans;
        ans.x=x-a.x;
        ans.y=y-a.y;
        return ans;
    }
};
ll n;
node p[maxn];

// p0p1 cross p0p2
ll cross(const node &p0,const node &p1,const node &p2){
    node tmp1=p1-p0;
    node tmp2=p2-p0;
    return tmp1.x*tmp2.y-tmp2.x*tmp1.y;
}

void solve(){
    ll ans=0;
    for(ll i=2;i+1<=n;i++){
        ans+=cross(p[1],p[i],p[i+1]);
    }
    printf("%.1f\n",(double)ans/2.0);
}

int main(void){
    while(scanf("%lld",&n)!=EOF){
        if(n==0)
            break;
        for(ll i=1;i<=n;i++){
            scanf("%lld %lld",&p[i].x,&p[i].y);
        }
        solve();
    }
    return 0;
}
