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

const int maxn=(int)1e5+10;
const int mod=9901;

int a[maxn],n,ha[maxn],diff;
int H,arr[maxn];

int lowbit(int x){
    return x&(-x);
}

void add(int x,int val){
    while(x<=diff){
        arr[x]=(arr[x]+val)%mod;
        x+=lowbit(x);
    }
}

int Sum(int x){
    int ans=0;
    while(x>0){
        ans=(ans+arr[x])%mod;
        x-=lowbit(x);
    }
    return ans;
}

int main(void){
    int pos,l,r,ans,tmp;
    while(scanf("%d %d",&n,&H)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            ha[i]=a[i];
        }
        ans=0;
        sort(ha+1,ha+1+n);
        diff=unique(ha+1,ha+1+n)-ha-1;
        for(int i=1;i<=n;i++){
            l=lower_bound(ha+1,ha+1+diff,a[i]-H)-ha;
            r=upper_bound(ha+1,ha+1+diff,a[i]+H)-ha-1;
            pos=lower_bound(ha+1,ha+1+diff,a[i])-ha;
            tmp=(Sum(r)-Sum(l-1)+mod+1)%mod;
            ans=(ans+tmp)%mod;
            add(pos,tmp);
        }
        ans=(ans-n%mod+mod)%mod;
        printf("%d\n",ans);
        for(int i=1;i<=diff;i++){
            arr[i]=0;
        }
    }
    return 0;
}
