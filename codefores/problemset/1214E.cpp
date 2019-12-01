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

pii d[maxn];
int n,id[maxn<<1];
vector<int> e[maxn<<1];

void solve(){
    sort(d+1,d+1+n,[](const pii &a,const pii &b)->bool{
        return a.first>b.first;
    });
    for(int i=1;i<=n;i++){
        id[i]=d[i].second;
    }
    for(int i=1;i<n;i++){
        e[d[i].second].push_back(d[i+1].second);
    }
    int u,v,lst=n;
    for(int i=1;i<=n;i++){
        v=d[i].second+1;
        u=id[d[i].first+i-1];
        e[u].push_back(v);
//        deb(u,v);
        if(d[i].first+i-1==lst){
            lst++;
            id[lst]=v;
        }
    }
    for(int i=1;i<=2*n;i++){
        for(int x:e[i]){
            printf("%d %d\n",i,x);
        }
    }
}

int main(void){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&d[i].first);
        d[i].second=2*i-1;
    }
    solve();
    return 0;
}
