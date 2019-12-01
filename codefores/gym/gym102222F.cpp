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

const int maxn=210;

int T;
int n,q;
pii r[maxn];
int ma[maxn][maxn],dis[maxn][maxn][maxn];

bool cmp(const pii &a,const pii &b){
    return a.first<b.first;
}

void handle(){
    sort(r+1,r+1+n);
    for(int ii=1;ii<=n;ii++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[ii][i][j]=min(dis[ii-1][i][j],dis[ii-1][i][r[ii].second]+dis[ii-1][r[ii].second][j]);
            }
        }
    }
}

int main(void){
    int u,v,w,pos,ans;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++){
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;i++){
            scanf("%d",&r[i].first);
            r[i].second=i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&ma[i][j]);
                dis[0][i][j]=ma[i][j];
            }
        }
        printf("Case #%d:\n",ca);
        handle();
        while(q--){
            scanf("%d %d %d",&u,&v,&w);
            pos=upper_bound(r+1,r+1+n,pii(w,0),cmp)-r-1;
            printf("%d\n",dis[pos][u][v]);
        }
    }
    return 0;
}
