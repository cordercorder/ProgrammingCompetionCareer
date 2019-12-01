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

const int maxn=1010;

bool isv[maxn];
vector<int> prime;
int n;
ll dp[maxn];

void pre_handle(){
    for(int i=2;i<=1000;i++){
        if(!isv[i]){
            prime.push_back(i);
            for(int j=i*i;j<=1000;j+=i)
                isv[j]=true;
        }
    }
}

void solve(){
    dp[0]=1;
    for(int i=0;i<(int)prime.size();i++){
        for(int j=prime[i];j<=n;j++)
            dp[j]+=dp[j-prime[i]];
    }
    printf("%lld\n",dp[n]);
}

int main(void){
    pre_handle();
    scanf("%d",&n);
    solve();
    return 0;
}
