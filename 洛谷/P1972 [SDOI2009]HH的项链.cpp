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

const int maxn=(int)1e6+10;

int N,M;
int a[maxn],pre[maxn];//pre[i]为元素i最近出现的元素的位置 

struct node{
    int x;
    int y;
    int id;
};

node res[maxn],Q[maxn];
int ans[maxn],T[maxn];

int lowbit(int x){
    return x&(-x);
}

void Add(int x,int val){
    while(x<=1000000){
        T[x]+=val;
        x+=lowbit(x);
    }
}

int Sum(int x){
    int ans=0;
    while(x>0){
        ans+=T[x];
        x-=lowbit(x);
    }
    return ans;
}

int main(void){
    int L,R;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",&a[i]);
        res[i]={pre[a[i]],i,0};
        pre[a[i]]=i;
    }
    scanf("%d",&M);
    for(int i=1;i<=M;i++){
        scanf("%d %d",&L,&R);
        Q[i]={L-1,R,i};
    }
    sort(res+1,res+1+N,[](const node &a,const node &b)->bool{
        return a.x<b.x;
    });
    sort(Q+1,Q+1+M,[](const node &a,const node &b)->bool{
        return a.x<b.x;
    });
    int tot=1;
    for(int i=1;i<=M;i++){
        while(tot<=N&&res[tot].x<=Q[i].x){
            Add(res[tot].y,1);
            tot++;
        }
        ans[Q[i].id]=Sum(Q[i].y)-Sum(Q[i].x);//相当于S(l-1,r)-S(l-1,l-1) 
    }
    for(int i=1;i<=M;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
