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

const ll maxn=(ll)1e6+10ll;

ll q,n,k;
char s[maxn];
ll sum[2];

void solve(){
    sum[0]=0;
    sum[1]=0;
    ll res=0;
    for(ll i=1;i<=n;i++){
        if(s[i]=='0'){
            res+=sum[1];
        }
        sum[s[i]-'0']++;
        if(res>k){
            ll tmp=res-k;
            sort(s+1,s+1+i);
            ll j=0;
            while(s[j+1]=='0'){
                j++;
            }
            swap(s[j],s[j+tmp]);
            puts(s+1);
            return ;
        }
    }
    sort(s+1,s+1+n);
    puts(s+1);
}

int main(void){
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&n,&k);
        scanf("%s",s+1);
        solve();
    }
    return 0;
}
