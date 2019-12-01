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

const ll maxn=(ll)1e3+10;
const ll mod=(ll)1e9+7ll;

ll h,w;
ll r[maxn],c[maxn];
ll ma[maxn][maxn];

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

void solve(){
    for(ll i=1;i<=h;i++){
        if(r[i]>0){
            ll j;
            for(j=1;j<=r[i];j++){
                ma[i][j]=1;
            }
            if(j<=w){
                ma[i][j]=-1;
            }
        }
        else{
            ma[i][1]=-1;
        }
    }
    for(ll i=1;i<=w;i++){
        if(c[i]>0){
            ll j;
            for(j=1;j<=c[i];j++){
                if(ma[j][i]==-1){
                    puts("0");
                    return ;
                }
                ma[j][i]=1;
            }
            if(j<=h){
                if(ma[j][i]==1){
                    puts("0");
                    return ;
                }
                ma[j][i]=-1;
            }
        }
        else{
            if(ma[1][i]==1){
                puts("0");
                return ;
            }
            ma[1][i]=-1;
        }
    }
    ll sum=0;
    for(ll i=1;i<=h;i++){
        for(ll j=1;j<=w;j++){
            if(ma[i][j]==0){
                sum++;
            }
        }
    }
    printf("%lld\n",q_mod(2ll,sum));
}

int main(void){
    scanf("%lld %lld",&h,&w);
    for(ll i=1;i<=h;i++){
        scanf("%lld",&r[i]);
    }
    for(ll i=1;i<=w;i++){
        scanf("%lld",&c[i]);
    }
    solve();
    return 0;
}
