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

const ll mod=(ll)1e9+7ll;
const ll inf=(ll)1e18;

ll x,n;
vector<ll> rev[1000010];

ll q_mod(ll a,ll b){
    ll ans=1;
    a=a%mod;
    while(b>0){
        if(b&1){
            ans=ans*a%mod;
        }
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}

vector<ll> Fac(ll x){
    vector<ll> ans;
    for(ll i=2;i*i<=x;i++){
        if(x%i==0){
            while(x%i==0){
                x/=i;
            }
            ans.push_back(i);
        }
    }
    if(x>1){
        ans.push_back(x);
    }
    return ans;
}

void solve(){
    vector<ll> f=Fac(x);
    for(ll i=0;i<(ll)f.size();i++){
        ll tmp=f[i];
        for(;;tmp*=f[i]){
            if(tmp<=n)
                rev[i].push_back(tmp);
            if(tmp>n/f[i]){
                break;
            }
        }
    }
    ll ans=1ll;
    for(ll i=0;i<(ll)f.size();i++){
        ll tmp;
        for(ll j=0;j+1<(ll)rev[i].size();j++){
            tmp=n/rev[i][j];
            ans=ans*q_mod(rev[i][j],tmp)%mod;
            tmp=n/rev[i][j+1];
            tmp=q_mod(rev[i][j],tmp);
            tmp=q_mod(tmp,mod-2);
            ans=ans*tmp%mod;
        }
        if(!rev[i].empty()){
            tmp=n/rev[i].back();
            ans=ans*q_mod(rev[i].back(),tmp)%mod;
        }
    }
    printf("%lld\n",ans);
}

int main(void){
    scanf("%lld %lld",&x,&n);
    solve();
    return 0;
}
