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

const int maxn=(int)2e5+10;

int q;
int h,n;
int p[maxn];

void solve(){
    map<int,bool> isv;
    for(int i=1;i<=n;i++){
        isv[p[i]]=true;
    }
    int ans=0,cur=h;
    for(int i=2;i<=n;i++){
//        deb(cur,i);
        if(cur==p[i]+1){
            if(p[i]-1==0){
                break;
            }
            if(isv.find(p[i]-1)==isv.end()){
                ans++;
                cur=p[i]-1;
            }
            else{
                cur=p[i]-1;
            }
        }
        else if(cur!=p[i]){
            cur=p[i]+1;
            i--;
        }
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&h,&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&p[i]);
        }
        solve();
    }
    return 0;
}
