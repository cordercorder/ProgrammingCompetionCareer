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

const int maxn=15;

int N,K;
ll ans;
int ma[maxn][maxn],cnt[(1<<9)+10];
ll dp[maxn][(1<<9)+10][maxn];

void pre_handle(){
    int tot;
    for(int i=0;i<(1<<9);i++){
        tot=0;
        for(int j=0;j<9;j++){
            if(i&(1<<j)){
                tot++;
            }
        }
        cnt[i]=tot;
    }
}

void solve(){
    pre_handle();
    vector<int> status;
    for(int i=0;i<(1<<N);i++){
        if((i&(i<<1))==0&&(i&(i>>1))==0){
            dp[1][i][cnt[i]]=1;
            status.push_back(i);
        }
    }
    for(int i=2;i<=N;i++){
        for(int j:status){
            for(int l=0;l<=K;l++){
                for(int k:status){
                    if((j&k)>0||(j&(k>>1))>0||(j&(k<<1))>0)
                        continue;
                    if(l>=cnt[j]){
                        dp[i][j][l]+=dp[i-1][k][l-cnt[j]];
                    }
                }
            }
        }
    }
    for(int i=0;i<(1<<N);i++){
        ans+=dp[N][i][K];
    }
    printf("%lld\n",ans);
}

int main(void){
    scanf("%d %d",&N,&K);
    solve();
    return 0;
}
