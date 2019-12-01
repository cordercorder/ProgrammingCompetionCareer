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

ll q,k;
vector<ll> rev,ls;
ll a[100];

ll bits(ll x){
    ll ans=0;
    while(x>0){
        x/=10;
        ans++;
    }
    return ans;
}

void pre_handle(){
    ll sum=0,lst=0,tmp;
    rev.push_back(0);
    ls.push_back(0);
    for(ll i=1;;i++){
        tmp=bits(i);
        lst+=tmp;
        sum+=lst;
        if(sum>(ll)1e9){
            break;
        }
        ls.push_back(lst);
        rev.push_back(sum);
    }
}

void solve(){
    ll pos=upper_bound(rev.begin(),rev.end(),k)-rev.begin()-1;
    ll res=k-rev[pos];
    if(res==0){
        printf("%lld\n",pos%10);
        return ;
    }
    ll pos2=upper_bound(ls.begin(),ls.end(),res)-ls.begin()-1;
    res-=ls[pos2];
//    deb(pos,pos2,res);
    if(res==0){
        printf("%lld\n",pos2%10);
    }
    else{
        pos2++;
        ll tmp=bits(pos2);
        while(true){
            if(res>tmp){
                res-=tmp;
            }
            else{
                break;
            }
            pos2++;
            tmp=bits(pos2);
        }
        ll tot=0;
        tmp=pos2;
        while(tmp>0){
            a[tot++]=tmp%10;
            tmp/=10;
        }
        reverse(a,a+tot);
        printf("%lld\n",a[res-1]);
    }
}

int main(void){
    pre_handle();
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&k);
        solve();
    }
    return 0;
}
