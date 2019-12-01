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

const int maxn=510;
const int inf=(int)1e9;

int n;
char s[maxn];
int sum[maxn][2],mine[maxn],suf[maxn];

int cal(){
    int ans=0;
    mine[0]=inf;
    for(int i=1;i<=n;i++){
        sum[i][0]=sum[i-1][0]+(int)(s[i]=='(');
        sum[i][1]=sum[i-1][1]+(int)(s[i]==')');
        mine[i]=min(mine[i-1],sum[i][0]-sum[i][1]);
    }
    suf[n+1]=inf;
    for(int i=n;i>=1;i--)
        suf[i]=min(suf[i+1],sum[i][0]-sum[i][1]);
    if(sum[n][0]!=sum[n][1])
        return 0;
    int left=0,right=0;
    for(int i=n;i>=1;i--){
        if(i==n){
            if(mine[i]==0)
                ans++;
        }
        else{
            if(suf[i+1]-sum[i][0]+sum[i][1]>=0&&left-right+mine[i]>=0){
                ans++;
            }
        }
        left+=(int)(s[i]=='(');
        right+=(int)(s[i]==')');
    }
    return ans;
}

void solve(){
    int ans=0,L=1,R=1,tmp;
    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            swap(s[l],s[r]);
            tmp=cal();
            if(tmp>ans){
                ans=tmp;
                L=l;
                R=r;
            }
            swap(s[l],s[r]);
        }
    }
    printf("%d\n",ans);
    printf("%d %d\n",L,R);
}

int main(void){
    scanf("%d",&n);
    scanf("%s",s+1);
    solve();
    return 0;
}
