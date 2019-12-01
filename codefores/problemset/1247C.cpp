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

ll n,p;
ll res[100],cnt;

void pre_handle(){
    res[0]=1;
    cnt=0;
    for(ll i=1;;i++){
        res[i]=res[i-1]*2;
        cnt++;
        if(res[i]>(ll)1e9)
            break;
    }
}

void solve(){
    ll tmp,sum;
    for(ll i=0;i<=32;i++){
        vector<ll> bits;
        tmp=n-p*i;
        sum=0;
        while(tmp>0){
            bits.push_back(tmp%2);
            tmp/=2;
        }
        for(ll j=0;j<(ll)bits.size();j++){
            if(bits[j]!=0){
                sum++;
            }
        }
        if(sum<=i&&(n-p*i)>=i){
            printf("%lld\n",i);
            return ;
        }
    }
    puts("-1");
}

int main(void){
    pre_handle();
    scanf("%lld %lld",&n,&p);
    solve();
    return 0;
}
