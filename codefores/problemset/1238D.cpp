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

const ll maxn=(ll)3e5+10;

ll n;
char s[maxn];

void handle(ll &ans){
    for(int i=0;i<n;){
        if(s[i]=='A'){
            int j=i;
            while(j+1<n&&s[j+1]=='B'){
                j++;
            }
            ans-=(j-i);
            if(i==j){
                i++;
            }
            else{
                i=j;
            }
        }
        else{
            int j=i;
            while(j+1<n&&s[j+1]=='A'){
                j++;
            }
            ans-=(j-i);
            if(i==j){
                i++;
            }
            else{
                i=j;
            }
        }
    }
}

void solve(){
    ll ans=n*(n-1)/2;
    for(int i=0;i+1<n;i++){
        if(s[i]=='A'&&s[i+1]=='B'){
            ans++;
        }
        else if(s[i]=='B'&&s[i+1]=='A'){
            ans++;
        }
    }
    handle(ans);
    reverse(s,s+n);
    handle(ans);
    printf("%lld\n",ans);
}

int main(void){
    scanf("%lld",&n);
    scanf("%s",s);
    solve();
    return 0;
}
