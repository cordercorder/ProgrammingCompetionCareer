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

const int maxn=110;

int m,n;
int a[maxn],b[maxn],c[maxn];
string name[maxn];
map<string,int> Index;
int cnt;
int dp[25];
int num[maxn],B[maxn],C[maxn];

void solve(){
    for(int i=1;i<=n;i++){
        int id=Index[name[i]];
        num[id]+=a[i];
        B[id]=b[i];
        C[id]=c[i];
    }
    m=21-m;
    for(int i=0;i<cnt;i++){
        for(int j=m;j>=0;j--){
            for(int k=0;k<=num[i]&&k<=j*C[i];k++){
                int tot=k/C[i];
                if(k%C[i]!=0)
                    tot++;
                dp[j]=max(dp[j],dp[j-tot]+k*B[i]);
            }
        }
    }
    cout<<dp[m];
}

int main(void){
    FC;
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i]>>name[i];
        if(Index.find(name[i])==Index.end()){
            Index[name[i]]=cnt++;
        }
    }
    solve();
    return 0;
}
