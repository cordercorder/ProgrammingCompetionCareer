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
using pii=pair<ll,bool>;
 
/*head------[@cordercorder]*/

const ll maxn=(ll)1e5+10ll;

ll n,m,w[maxn];
ll l,r;
map<ll,ll> mp;

ll phi(ll x){
    ll res=x,a=x;
    for(ll i=2;i*i<=a;i++){
        if(a%i==0){
            res=res/i*(i-1);
            while(a%i==0)
                a/=i;
        }
    }
    if(a>1)
        res=res/a*(a-1);
    return res;
}

pii q_mod(ll a,ll b,ll mod){//a^b大于mod时,second为false 
    ll ans=1;
    bool f=true;
    while(b>0){
        if(b&1){
            if(ans*a>=mod){
                f=false;
            }
            ans=ans*a%mod;
        }
        b>>=1;
        if(b>0){
            if(a*a>=mod){
                f=false;
            }
        }
        a=a*a%mod;
    }
    return pii(ans,f);
}

pii cal(ll pos,ll mod){
    if(mod==1){//当mod为1时,phi(mod)=0,故此时x必定大于phi(mod),故返回false。一般情况下可以是pii(1,true),hack数据:当模数m原本是1时会被hack 
        return pii(0,false);
    }
    if(pos==r){
        return pii(w[pos]%mod,w[pos]<mod);//记录幂指数和模数的大小关系，如果幂指数小于模数，则second为true,否则为false 
    }
    bool f;
    ll p;
    if(mp.find(mod)!=mp.end()){
        p=mp[mod];
    }
    else{
        p=phi(mod);
        mp[mod]=p;
    }
    pii exp=cal(pos+1,p);
    if(!exp.second){//当幂指数大于phi(mod)时，降幂为x%phi(mod)+phi(mod) 
        exp.first+=p;//first中存的是幂指数 
    }
    return q_mod(w[pos],exp.first,mod);
}

int main(void){
    ll q,ans;
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&w[i]);
    }
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&l,&r);
        printf("%lld\n",cal(l,m).first);
    }
    return 0;
}
