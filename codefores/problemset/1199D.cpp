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

const int maxn=(int)2e5+10;

int a[maxn],n,q;
int minF[maxn<<2],minS[maxn<<2];

void pushup(int rt){
    minF[rt]=min(minF[rt<<1],minF[rt<<1|1]);
    minS[rt]=min(minS[rt<<1],minS[rt<<1|1]);
    if(minF[rt<<1]!=minF[rt<<1|1]){
        minS[rt]=min(minS[rt],max(minF[rt<<1],minF[rt<<1|1]));
    }
}

void pushdown(int rt){
    if(minF[rt]>minF[rt<<1]){
        minF[rt<<1]=minF[rt];
    }
    if(minF[rt]>minF[rt<<1|1]){
        minF[rt<<1|1]=minF[rt];
    }
}

void create(int rt,int l,int r){
    if(l==r){
        minF[rt]=a[l];
        minS[rt]=(int)1e9+10;
        return ;
    }
    int mid=(l+r)>>1;
    create(rt<<1,l,mid);
    create(rt<<1|1,mid+1,r);
    pushup(rt);
}

void update1(int rt,int l,int r,int pos,int x){
    if(l==r){
        minF[rt]=x;
        return ;
    }
    pushdown(rt);
    int mid=(l+r)>>1;
    if(pos<=mid){
        update1(rt<<1,l,mid,pos,x);
    }
    else{
        update1(rt<<1|1,mid+1,r,pos,x);
    }
    pushup(rt); 
}

void update2(int rt,int l,int r,int L,int R,int x){
    if(x<=minF[rt]){
        return ;
    }
    if(l==L&&R==r&&x<minS[rt]){
        minF[rt]=x;
        return ;
    }
    pushdown(rt);
    int mid=(l+r)>>1;
    if(R<=mid){
        update2(rt<<1,l,mid,L,R,x);
    }
    else if(L>mid){
        update2(rt<<1|1,mid+1,r,L,R,x);
    }
    else{
        update2(rt<<1,l,mid,L,mid,x);
        update2(rt<<1|1,mid+1,r,mid+1,R,x);
    }
    pushup(rt);
}

void print(int rt,int l,int r){
    if(l==r){
        printf("%d ",minF[rt]);
        return ;
    }
    pushdown(rt);
    int mid=(l+r)>>1;
    print(rt<<1,l,mid);
    print(rt<<1|1,mid+1,r);
}

int main(void){
    int tmp,p,x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    create(1,1,n);
    scanf("%d",&q);
    while(q--){
        scanf("%d",&tmp);
        if(tmp==1){
            scanf("%d %d",&p,&x);
            update1(1,1,n,p,x);
        }
        else{
            scanf("%d",&x);
            update2(1,1,n,1,n,x);
        }
    }
    print(1,1,n);
    return 0;
}
