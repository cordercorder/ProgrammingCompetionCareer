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

int n,k;
int ma[maxn][maxn],sum[maxn][maxn];
int a[4];

void solve(){
    int ans=0;
    for(int i=1;i<=1000;i++){
        for(int j=1;j<=1000;j++){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+ma[i][j];
            if(sum[i][j]==k)
                ans++;
        }
    }
    printf("%d\n",ans);
}

int main(void){
    int x1,y1,x2,y2;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        x1++;
        y1++;
        ma[x1][y1]++;
        ma[x1][y2+1]--;
        ma[x2+1][y1]--;
        ma[x2+1][y2+1]++;
    }
    solve();
    return 0;
}
