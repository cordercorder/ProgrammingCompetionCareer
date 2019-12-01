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

const int maxn=15000;

int a[maxn],n,ans[maxn];
int sum;

void solve(){
    int tot=0;
    for(int i=1;i<=n;i++){
        if(a[i]%2==0){
            ans[i]=a[i]/2;
        }
        else{
            tot++;
            if(tot<=sum/2){
                ans[i]=(a[i]+1)/2;
            }
            else{
                ans[i]=(a[i]-1)/2;
            }
        }
    } 
    for(int i=1;i<=n;i++){
        printf("%d\n",ans[i]);
    }
}

int main(void){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]%2){
            sum++;
        }
    }
    solve();
    return 0;
}
