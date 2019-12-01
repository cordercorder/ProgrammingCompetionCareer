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

const int maxn=(int)2e5+10;

vector<int> a[3];
int k[3];
int arr[maxn],cnt;

void solve(){
    vector<int> rev;
    for(int i=0;i<3;i++){
        for(int j=0;j<(int)a[i].size();j++){
            rev.push_back(a[i][j]);
        }
    }
    cnt=0;
    arr[++cnt]=rev[0];
    for(int i=1;i<(int)rev.size();i++){
        if(arr[cnt]<rev[i]){
            arr[++cnt]=rev[i];
        }
        else{
            int pos=lower_bound(arr+1,arr+1+cnt,rev[i])-arr;
            arr[pos]=rev[i];
        }
    }
    int ans=k[0]+k[1]+k[2]-cnt;
    printf("%d\n",ans);
}

int main(void){
    int x;
    for(int i=0;i<3;i++){
        scanf("%d",&k[i]);
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<k[i];j++){
            scanf("%d",&x);
            a[i].push_back(x);
        }
        sort(a[i].begin(),a[i].end());
    }
    solve();
    return 0;
}
