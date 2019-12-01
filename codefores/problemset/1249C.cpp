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

const ll base=3;

ll q,n,m;
vector<ll> res,ls;

void dfs(ll pos,ll sum){
    if(pos==(ll)res.size()){
        if(sum!=0){
            ls.push_back(sum);
        }
        return ;
    }
    dfs(pos+1,sum+res[pos]);
    dfs(pos+1,sum);
}

void pre_handle(){
    ll ret=1;
    for(ll i=0;;i++){
        res.push_back(ret);
        if(ret*3>(ll)1e9){
            break;
        }
        ret=ret*base;
    }
    dfs(0,0);
    sort(ls.begin(),ls.end());
} 

int main(void){
    freopen("1.in","r",stdin);
    freopen("my.out","w",stdout);
    pre_handle();
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        printf("%lld\n",*(lower_bound(ls.begin(),ls.end(),n)));
    }
    return 0;
}
