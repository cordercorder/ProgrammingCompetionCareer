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

struct node{
    int x1;
    int x2;
};
int N;
node res[maxn];
int num[maxn];

void solve(){
    sort(res+1,res+1+N,[](const node &a,const node &b)->bool{
        return a.x1<b.x1;
    });
    int cnt=0;
    num[++cnt]=res[1].x2;
    for(int i=2;i<=N;i++){
        if(res[i].x2>num[cnt]){
            num[++cnt]=res[i].x2;
        }
        else{
            int pos=lower_bound(num+1,num+1+cnt,res[i].x2)-num;
            num[pos]=res[i].x2;
        }
    }
    printf("%d\n",cnt);
}

int main(void){
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d %d",&res[i].x1,&res[i].x2);
    }
    solve();
    return 0;
}
