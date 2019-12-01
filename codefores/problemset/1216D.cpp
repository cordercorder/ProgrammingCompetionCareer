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

const ll maxn=(ll)2e5+10ll;

ll a[maxn],n;
ll sum,maxe;
vector<ll> ls;

vector<ll> fac(ll x){
    vector<ll> ans;
    for(ll i=1;i*i<=x;i++){
        if(x%i==0){
            ans.push_back(i);
            if(x/i!=i){
                ans.push_back(x/i);
            } 
        }
    }
    return ans;
}

void solve(){
    sort(ls.begin(),ls.end());
    ls.erase(unique(ls.begin(),ls.end()),ls.end());
    ll res=maxe-ls[0],rev=n*maxe-sum;
    vector<ll> f=fac(res);
    set<ll> S;
    for(ll e:f){
        S.insert(e);
    }
    for(ll i=1;i+1<(ll)ls.size();i++){
        for(set<ll>::iterator it=S.begin();it!=S.end();){
            if((maxe-ls[i])%(*it)!=0){
                S.erase(it++);
            }
            else{
                it++;
            }
        }
    }
    ll z,y;
    set<ll>::iterator it=S.begin();
    for(;it!=S.end();it++){
        z=*it;
        if(rev%z==0){
            y=rev/z;
            break;
        }
    }
    for(;it!=S.end();it++){
        if(rev%(*it)==0){
            if(rev/(*it)<y){
                z=*it;
                y=rev/z;
            }
        }
    }
    printf("%lld %lld\n",y,z);
}

int main(void){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
        maxe=max(maxe,a[i]);
        ls.push_back(a[i]); 
    }
    solve();
    return 0;
}
