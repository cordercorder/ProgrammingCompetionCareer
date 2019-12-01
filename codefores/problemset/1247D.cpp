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

const ll maxn=(ll)1e5+10;
const ll inf=(ll)1e5;

ll n,k;
ll a[maxn];
ll rev[maxn];

struct node{
    ll prime;
    ll cnt;
};

vector<node> Fac(ll x){
    vector<node> ans;
    node now;
    for(ll i=2;i*i<=x;i++){
        if(x%i==0){
            now.cnt=0;
            now.prime=i;
            while(x%i==0){
                x/=i;
                now.cnt++;
            }
            ans.push_back(now);
        }
    }
    if(x!=1){
        ans.push_back({x,1});
    }
    return ans;
}

void solve(){
    ll ans=0;
    for(ll i=1;i<=n;i++){
        vector<node> fac=Fac(a[i]);
        ll res1=1,res2=1;
        for(node e:fac){
            ll need=(k-e.cnt%k)%k;
            ll have=e.cnt%k;
            for(ll j=0;j<need;j++){
                if(res1<=inf)
                    res1*=e.prime;
            }
            for(ll j=0;j<have;j++){
                if(res2<=inf)
                    res2*=e.prime;
            }
        }
        if(res1<=inf)
            ans+=rev[res1];
        if(res2<=inf)
            rev[res2]++;
    }
    printf("%lld\n",ans);
}

int main(void){
    scanf("%lld %lld",&n,&k);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    solve();
    return 0;
}
