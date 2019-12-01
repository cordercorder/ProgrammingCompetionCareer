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

int a[maxn],n,b[maxn],f[maxn];

int T[maxn<<2];

void upd(int rt,int l,int r,int pos,int val){
    if(l==r){
        T[rt]=val;
        return ;
    }
    int mid=(l+r)>>1;
    if(pos<=mid)
        upd(rt<<1,l,mid,pos,val);
    else
        upd(rt<<1|1,mid+1,r,pos,val);
    T[rt]=max(T[rt<<1],T[rt<<1|1]);
}

int query_max(int rt,int l,int r,int L,int R){
    if(l==L&&R==r){
        return T[rt];
    }
    int mid=(l+r)>>1;
    if(R<=mid)
        return query_max(rt<<1,l,mid,L,R);
    else if(L>mid)
        return query_max(rt<<1|1,mid+1,r,L,R);
    else
        return max(query_max(rt<<1,l,mid,L,mid),query_max(rt<<1|1,mid+1,r,mid+1,R));
} 

void solve(){
    sort(b+1,b+1+n);
    int len=unique(b+1,b+1+n)-b-1,pos,maxe;
    for(int i=1;i<=n;i++){
        pos=lower_bound(b+1,b+1+len,a[i])-b;
        f[i]=1;
        if(pos-1<1){
            upd(1,1,n,pos,f[i]);
            continue;
        }
        maxe=query_max(1,1,n,1,pos-1);
        f[i]=max(maxe+1,f[i]);
        upd(1,1,n,pos,f[i]);
    }
    maxe=1;
    for(int i=1;i<=n;i++){
        if(f[maxe]<f[i]){
            maxe=i;
        }
    } 
    printf("%d\n",n-f[maxe]);
}

int main(void){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    solve();
    return 0;
}
