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

const int maxn=110;
const int maxn2=(int)1e6+10;
const int inf=(int)1e9;

char s[maxn][maxn];

int n,m,p[maxn2];
int d[maxn][maxn];

void solve(){
    for(int ii=1;ii<=n;ii++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j]=min(d[i][j],d[i][ii]+d[ii][j]);
            }
        }
    }
    vector<int> ans;
    ans.push_back(1);
    for(int i=2;i<=m;i++){
        if(d[p[ans.back()]][p[i]]<i-ans.back()){
            ans.push_back(i-1);
        }
    }
    ans.push_back(m);
    printf("%d\n",(int)ans.size());
    for(auto e:ans){
        printf("%d ",p[e]);
    }
}

int main(void){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            d[i][j]=inf;
            if(s[i][j]=='1'){
                d[i][j]=1;
            }
        }
        d[i][i]=0;
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&p[i]);
    }
    solve();
    return 0;
}
