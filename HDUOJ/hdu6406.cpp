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
const int inf=(int)1e9;

int a[maxn],n,m,maxe[maxn],sum[maxn],que[maxn],suf[maxn];
int T[maxn<<2],t;

void pre_handle(){
    for(int i=1;i<=n;i++){
        if(a[i]>maxe[i-1]){
            sum[i]=sum[i-1]+1;
            maxe[i]=a[i];
        }
        else{
            maxe[i]=maxe[i-1];
            sum[i]=sum[i-1];
        }
    }
    int front=0,back=0;
    for(int i=n;i>=1;i--){
        while(front<back&&a[que[back]]<=a[i]){
            back--;
        }
        que[++back]=i;
        suf[i]=back-front;
    }
}

void create(int rt,int l,int r){
    if(l==r){
        T[rt]=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    int ls=rt<<1,rs=ls+1;
    create(ls,l,mid);
    create(rs,mid+1,r);
    T[rt]=max(T[ls],T[rs]);
}

int Find(int rt,int l,int r,int val){
    if(T[rt]<=val){
        return inf;
    }
    if(l==r){
        return l;
    }
    int mid=(l+r)>>1;
    int ls=rt<<1,rs=ls+1;
    if(T[ls]>val){
        return Find(ls,l,mid,val);
    }
    else{
        return Find(rs,mid+1,r,val);
    }
}

int cal(int rt,int l,int r,int L,int R,int val){
    if(T[rt]<=val){
        return inf;
    }
    if(l==L&&R==r){
        return Find(rt,l,r,val);
    }
    int mid=(l+r)>>1;
    int ls=rt<<1,rs=ls+1;
    if(R<=mid){
        return cal(ls,l,mid,L,R,val);
    }
    else if(L>mid){
        return cal(rs,mid+1,r,L,R,val);
    }
    else{
        return min(cal(ls,l,mid,L,mid,val),cal(rs,mid+1,r,mid+1,R,val));
    }
}

int main(void){
    int ret,x,y,ans,pos;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        pre_handle(); 
        create(1,1,n);
        while(m--){
            scanf("%d %d",&x,&y);
            ret=maxe[x-1];
            if(y>ret){
                ans=sum[x-1]+1;
                ret=y;
            }
            else{
                ans=sum[x-1];
            }
            if(x+1<=n){
                pos=cal(1,1,n,x+1,n,ret);
                if(pos!=inf){
                    ans+=suf[pos];
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
