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
const int inf=(int)1e9;

int n,a[maxn],ans[maxn];
vector<int> e[maxn];
vector<int> even,odd;
int d[maxn];

void handle(vector<int>&S,vector<int> &T){
    for(int i=1;i<=n;i++){
        d[i]=inf;
    }
    queue<int> q;
    for(int v:S){
        d[v]=0;
        q.push(v);
    }
    int v;
    while(!q.empty()){
        v=q.front();
        q.pop();
        for(int to:e[v]){
            if(d[to]>=inf){
                d[to]=d[v]+1;
                q.push(to);
            }
        }
    }
    for(int to:T){
        ans[to]=d[to];
    }
}

void solve(){
    for(int i=1;i<=n;i++){
        if(a[i]%2==1){
            odd.push_back(i);
        }
        else{
            even.push_back(i);
        }
        if(i-a[i]>=1){
            e[i-a[i]].push_back(i);
        }
        if(i+a[i]<=n){
            e[i+a[i]].push_back(i);
        }
    }
    handle(odd,even);
    handle(even,odd);
    for(int i=1;i<=n;i++){
        if(ans[i]>=inf)
            ans[i]=-1;
        printf("%d ",ans[i]);
    }
}

int main(void){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    solve();
    return 0;
}