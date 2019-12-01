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

const int maxn=(int)1e5+10;

int N,Q;
int R[maxn],C[maxn];
int st[2],ed[2];
int preR[maxn],preC[maxn];

int FindR(int x){
    return preR[x]==-1?x:preR[x]=FindR(preR[x]);
}

int FindC(int x){
    return preC[x]==-1?x:preC[x]=FindC(preC[x]);
}

void UnionR(int x,int y){
    int nx=FindR(x),ny=FindR(y);
    if(nx!=ny){
        preR[ny]=nx;
    }
}

void UnionC(int x,int y){
    int nx=FindC(x),ny=FindC(y);
    if(nx!=ny){
        preC[ny]=nx;
    }
}

void pre_handle(){
    for(int i=1;i<=N;i++){
        preR[i]=-1;
        preC[i]=-1;
    }
    for(int i=1;i<=N;){
        int j=i;
        while(j<=N&&C[i]%2==C[j]%2){
            UnionC(i,j);
            j++;
        }
        i=j;
    }
    for(int i=1;i<=N;){
        int j=i;
        while(j<=N&&R[i]%2==R[j]%2){
            UnionR(i,j);
            j++;
        }
        i=j;
    }
}

void solve(){
    if(FindR(st[0])==FindR(ed[0])&&FindC(st[1])==FindC(ed[1])){
        puts("YES");
    }
    else{
        puts("NO");
    }
}

int main(void){
    scanf("%d %d",&N,&Q);
    for(int i=1;i<=N;i++)
        scanf("%d",&R[i]);
    for(int i=1;i<=N;i++)
        scanf("%d",&C[i]);
    pre_handle();
    while(Q--){
        for(int i=0;i<2;i++)
            scanf("%d",&st[i]);
        for(int i=0;i<2;i++)
            scanf("%d",&ed[i]);
        solve();
    }
    return 0;
}
