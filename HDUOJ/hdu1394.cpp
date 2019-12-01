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

const int maxn=5010;

int a[maxn],n,arr[maxn],rev[maxn];
pii res[maxn];
int sum;

int lowbit(int x){
    return x&(-x);
}

void add(int x,int val){
    while(x<=n){
        arr[x]+=val;
        x+=lowbit(x);
    }
}

int Sum(int x){
    int ans=0;
    while(x>0){
        ans+=arr[x];
        x-=lowbit(x);
    }
    return ans;
}

bool cmp(const pii &a,const pii &b){
    return a.first<b.first;
}

void solve(){
    sum=0;
    sort(res+1,res+1+n,[](const pii &a,const pii &b)->bool{
        return a.first<b.first;
    });
    for(int i=1;i<=n;i++){
        rev[res[i].second]=Sum(n)-Sum(res[i].second);
        add(res[i].second,1);
    }
    for(int i=1;i<=n;i++){
        sum+=rev[i];
    }
    int ans=sum;
    for(int i=1;i<n;i++){
        sum+=(n-a[i]-1-a[i]);
        ans=min(ans,sum);
//        deb(sum);
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++){
        arr[i]=0;
    }
}

int main(void){
    while(scanf("%d",&n)!=EOF){
        
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            res[i].first=a[i];
            res[i].second=i;
        }
        solve();
    } 
    
    return 0;
}
